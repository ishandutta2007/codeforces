#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
// basic debugging macros
int __i__,__j__;
#define printLine(l) for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl
#define printLine2(l,c) for(__i__=0;__i__<l;__i__++){cout<<c;}cout<<endl
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}
#define print2dArr2(a,r,c,l) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<setw(l)<<setfill(' ')<<a[__i__][__j__]<<" ";}cout<<endl;}

// advanced debugging class
// debug 1,2,'A',"test";
class _Debug {
    public:
        template<typename T>
        _Debug& operator,(T val) {
            cout << val << endl;
            return *this;
        }
};
#define debug _Debug(),
#else
#define printLine(l)
#define printLine2(l,c)
#define printVar(n)
#define printArr(a,l)
#define print2dArr(a,r,c)
#define print2dArr2(a,r,c,l)
#define debug
#endif

// define
#define MAX_VAL 999999999
#define MAX_VAL_2 999999999999999999LL
#define EPS 1e-6
#define mp make_pair
#define pb push_back

// typedef
typedef unsigned int UI;
typedef long long int LLI;
typedef unsigned long long int ULLI;
typedef unsigned short int US;
typedef pair<int,int> pii;
typedef pair<LLI,LLI> plli;
typedef vector<int> vi;
typedef vector<LLI> vlli;
typedef vector<pii> vpii;
typedef vector<plli> vplli;

// ---------- END OF TEMPLATE ----------

struct node {
    node *l,*r,*p;
    int k,s;
};
node *nodes[100001];
int size(node *r) {
    if (r == NULL) return 0;
    else return r->s;
}
int update(node *r) {
    if (r != NULL) r->s = size(r->l)+size(r->r)+1;
    return 0;
}
int isRoot(node *r) {
    return (r->p == NULL) || ((r->p->l != r) && (r->p->r != r));
}
int rotL(node *r) {
    node *n = r->r;
    r->r = n->l;
    if (n->l != NULL) n->l->p = r;
    n->p = r->p;
    if (r->p != NULL) {
        if (r->p->l == r) r->p->l = n;
        else if (r->p->r == r) r->p->r = n;
    }
    n->l = r,r->p = n;
    update(r),update(n);
    return 0;
}
int rotR(node *r) {
    node *n = r->l;
    r->l = n->r;
    if (n->r != NULL) n->r->p = r;
    n->p = r->p;
    if (r->p != NULL) {
        if (r->p->l == r) r->p->l = n;
        else if (r->p->r == r) r->p->r = n;
    }
    n->r = r,r->p = n;
    update(r),update(n);
    return 0;
}
int splay(node *n) {
    if (n == NULL) return 0;
    while (!isRoot(n)) {
        if (isRoot(n->p)) {
            if (n == n->p->l) rotR(n->p);
            else rotL(n->p);
        }
        else if ((n->p->l == n) && (n->p->p->l == n->p)) rotR(n->p->p),rotR(n->p);
        else if ((n->p->r == n) && (n->p->p->r == n->p)) rotL(n->p->p),rotL(n->p);
        else if ((n->p->l == n) && (n->p->p->r == n->p)) rotR(n->p),rotL(n->p);
        else rotL(n->p),rotR(n->p);
    }
    return 0;
}
int access(node *n) {
    for (splay(n),n->r = NULL,update(n); n->p != NULL; splay(n)) splay(n->p),n->p->r = n;
    return 0;
}
int find(int k) {
    node *n = nodes[k];
    access(n);
    while (n->l != NULL) n = n->l;
    splay(n);
    return n->k;
}
int link(int a,int b) {
    access(nodes[a]);
    nodes[a]->p = nodes[b];
    access(nodes[a]);
    return 0;
}
int cut(int k) {
    node *n = nodes[k];
    access(n);
    n->l->p = NULL;
    n->l = NULL;
    update(n);
    return 0;
}
int depth(int k) {
    access(nodes[k]);
    return nodes[k]->s-1;
}
int x[100000],logg[100001];
pii sparse[100000][17];
vpii queries;
pair<int,pii> updates[8000000];
int ans[100000];
int main() {
    int i;
    int n,w,q,k;
    scanf("%d %d %d",&n,&w,&q);
    for (i = 0; i < n; i++) scanf("%d",&x[i]);
    for (i = 0; i < q; i++) scanf("%d",&k),queries.pb(mp(w-k,i));

    int j,B = 0.25*sqrt(n);
    for (i = 0; i <= n; i++) {
        nodes[i] = new node;
        nodes[i]->l = nodes[i]->r = nodes[i]->p = NULL;
        nodes[i]->k = i,nodes[i]->s = 1;
    }
    for (i = 0; i < n; i++) sparse[i][0] = mp(x[i],x[i]);
    for (i = 1; (1 << i) < n; i++) {
        for (j = 0; j <= n-(1 << i); j++) {
            sparse[j][i].first = min(sparse[j][i-1].first,sparse[j+(1 << (i-1))][i-1].first);
            sparse[j][i].second = max(sparse[j][i-1].second,sparse[j+(1 << (i-1))][i-1].second);
        }
    }
    int logn = i,c = 0;
    for (i = 2; i <= n; i++) logg[i] = logg[i/2]+1;
    for (i = 0; i < n; i++) {
        link(i,i+1);
        int s = x[i],b = x[i];
        for (j = 1; j < B; j++) {
            if (i+j >= n) break;
            int o = b-s;
            s = min(s,x[i+j]),b = max(b,x[i+j]);
            if (b-s > o) {
                if (j > 1) updates[c++] = mp(o,mp(i,i+j));
            }
        }
        updates[c++] = mp(b-s,mp(i,-1));
    }
    j = 0;
    sort(updates,updates+c);
    sort(queries.begin(),queries.end());
    for (i = 0; i < queries.size(); i++) {
        while ((j < c) && (updates[j].first <= queries[i].first)) {
            cut(updates[j].second.first);
            if (updates[j].second.second != -1) link(updates[j].second.first,updates[j].second.second);
            j++;
        }
        int u = 0,d = 0;
        while (u < n) {
            d += depth(u),u = find(u);
            if (u < n) {
                int s = x[u],b = x[u];
                for (k = logn-1; k >= 0; k--) {
                    if ((u+(1 << k) <= n) && (max(b,sparse[u][k].second)-min(s,sparse[u][k].first) <= queries[i].first)) {
                        s = min(s,sparse[u][k].first),b = max(b,sparse[u][k].second);
                        u += (1 << k);
                    }
                }
                d++;
            }
        }
        ans[queries[i].second] = d-1;
    }
    for (i = 0; i < q; i++) printf("%d\n",ans[i]);

    return 0;
}