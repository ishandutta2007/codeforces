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
    LLI k,s;
};
node *nodes[200001];
LLI size(node *r) {
    if (r == NULL) return 0;
    else return r->s;
}
int update(node *r) {
    if (r != NULL) r->s = size(r->l)+size(r->r)+r->k;
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
LLI depth(int k) {
    access(nodes[k]);
    return nodes[k]->s;
}

int p[200000],r[200000];
vi s;
vi v[200001];
LLI a[200001],b[200001];
int x[200000];
set<int> S;
vpii qq;
LLI ans[600001];
int main() {
    int i;
    int n,q;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n; i++) scanf("%d",&p[i]);
    for (i = 0; i < n; i++) scanf("%I64d",&a[i]);
    for (i = 0; i < n; i++) scanf("%I64d",&b[i]);

    int logn = 0;
    while ((1 << logn) < n) logn++;
    for (i = n-1; i >= 0; i--) {
        while (!s.empty() && (p[s.back()] < p[i])) s.pop_back();
        if (s.empty()) r[i] = n;
        else r[i] = s.back();
        s.pb(i);
        int u = i+1;
        LLI w = a[i];
        while (u < r[i]) w += b[u],u = r[u];
        b[i] = min(b[i],w);
        v[r[i]].pb(i);
    }

    S.insert(0),S.insert(n);
    qq.pb(mp(n,0));
    for (i = 0; i < q; i++) {
        scanf("%d",&x[i]),x[i]--;
        if (x[i] > 0) {
            if (S.count(x[i])) {
                S.erase(x[i]);
                auto it = S.lower_bound(x[i]);
                int t = *it;
                it--;
                qq.pb(mp(t,*it));
            }
            else {
                auto it = S.lower_bound(x[i]);
                qq.pb(mp(*it,x[i]));
                it--;
                qq.pb(mp(x[i],*it));
                S.insert(x[i]);
            }
        }
    }
    sort(qq.begin(),qq.end());
    qq.resize(unique(qq.begin(),qq.end())-qq.begin());

    for (i = 0; i <= n; i++) {
        nodes[i] = new node;
        nodes[i]->l = nodes[i]->r = nodes[i]->p = NULL;
        nodes[i]->k = nodes[i]->s = a[i];
    }
    int j = 0,k;
    for (i = 0; i <= n; i++) {
        for (k = 0; k < v[i].size(); k++) {
            cut(v[i][k]);
            splay(nodes[v[i][k]]);
            nodes[v[i][k]]->k = b[v[i][k]];
            update(nodes[v[i][k]]);
            link(v[i][k],i);
        }
        while ((j < qq.size()) && (qq[j].first == i)) {
            ans[j] = depth(qq[j].second)-a[i];
            j++;
        }
        if (i < n) link(i,i+1);
    }

    S.clear();
    S.insert(0),S.insert(n);
    LLI sum = ans[lower_bound(qq.begin(),qq.end(),mp(n,0))-qq.begin()];
    for (i = 0; i < q; i++) {
        if (x[i] > 0) {
            if (S.count(x[i])) {
                S.erase(x[i]);
                auto it = S.lower_bound(x[i]);
                sum -= ans[lower_bound(qq.begin(),qq.end(),mp(*it,x[i]))-qq.begin()];
                int t = *it;
                it--;
                sum -= ans[lower_bound(qq.begin(),qq.end(),mp(x[i],*it))-qq.begin()];
                sum += ans[lower_bound(qq.begin(),qq.end(),mp(t,*it))-qq.begin()];
            }
            else {
                auto it = S.lower_bound(x[i]);
                sum += ans[lower_bound(qq.begin(),qq.end(),mp(*it,x[i]))-qq.begin()];
                int t = *it;
                it--;
                sum += ans[lower_bound(qq.begin(),qq.end(),mp(x[i],*it))-qq.begin()];
                sum -= ans[lower_bound(qq.begin(),qq.end(),mp(t,*it))-qq.begin()];
                S.insert(x[i]);
            }
        }
        printf("%I64d\n",sum);
    }

    return 0;
}