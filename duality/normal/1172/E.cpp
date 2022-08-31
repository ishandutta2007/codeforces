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

int c[400001];
vi adjList[400001];
vpii events[400001];
LLI diff[400002],ans = 0;
int parent[400001];
int doDFS(int u,int p) {
    int i;
    parent[u] = p;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS(v,u);
    }
    return 0;
}
struct node {
    node *l,*r,*p;
    int k,s,v;
    LLI sq;
};
node *nodes[400001];
int size(node *r) {
    if (r == NULL) return 0;
    else return r->s;
}
int update(node *r) {
    if (r != NULL) r->s = size(r->l)+size(r->r)+r->v+1;
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
    node *p = NULL,*o = n;
    while (n != NULL) {
        splay(n);
        n->v += size(n->r),n->sq += (LLI) size(n->r)*size(n->r);
        n->r = p,n->v -= size(p),n->sq -= (LLI) size(p)*size(p);
        update(n),p = n,n = n->p;
    }
    splay(o);
    //for (splay(n),n->r = NULL,update(n); n->p != NULL; splay(n)) splay(n->p),n->p->r = n;
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
    int ra = find(a),rb = find(b);
    ans -= nodes[ra]->sq+(LLI) (nodes[ra]->s-nodes[ra]->v-1)*(nodes[ra]->s-nodes[ra]->v-1);
    ans -= nodes[rb]->sq+(LLI) (nodes[rb]->s-nodes[rb]->v-1)*(nodes[rb]->s-nodes[rb]->v-1);
    access(nodes[a]);
    nodes[a]->p = nodes[b];
    nodes[b]->v += nodes[a]->s,nodes[b]->sq += (LLI) nodes[a]->s*nodes[a]->s;
    access(nodes[a]);
    rb = find(b);
    ans += nodes[rb]->sq+(LLI) (nodes[rb]->s-nodes[rb]->v-1)*(nodes[rb]->s-nodes[rb]->v-1);
    return 0;
}
int cut(int k) {
    node *n = nodes[k];
    int r = find(k);
    ans -= nodes[r]->sq+(LLI) (nodes[r]->s-nodes[r]->v-1)*(nodes[r]->s-nodes[r]->v-1);
    access(n);
    n->l->p = NULL;
    r = n->l->k;
    n->l = NULL;
    update(n),access(n);
    r = find(r);
    ans += nodes[r]->sq+(LLI) (nodes[r]->s-nodes[r]->v-1)*(nodes[r]->s-nodes[r]->v-1);
    ans += nodes[k]->sq+(LLI) (nodes[k]->s-nodes[k]->v-1)*(nodes[k]->s-nodes[k]->v-1);
    return 0;
}
int main() {
    int i;
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    for (i = 1; i <= n; i++) scanf("%d",&c[i]),events[c[i]].pb(mp(0,i));
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    for (i = 1; i <= m; i++) {
        scanf("%d %d",&u,&v);
        events[c[u]].pb(mp(i,-u));
        c[u] = v;
        events[c[u]].pb(mp(i,u));
    }
    for (i = 1; i <= n; i++) events[c[i]].pb(mp(m+1,-i));

    int j;
    doDFS(1,0);
    for (i = 0; i <= n; i++) {
        nodes[i] = new node;
        nodes[i]->l = nodes[i]->r = nodes[i]->p = NULL;
        nodes[i]->k = i,nodes[i]->s = 1,nodes[i]->v = nodes[i]->sq = 0;
    }
    for (i = 1; i <= n; i++) link(i,parent[i]);
    for (i = 1; i <= n; i++) {
        for (j = 0; j < events[i].size(); j++) {
            diff[(j == 0) ? 0:events[i][j-1].first] += ans;
            diff[events[i][j].first] -= ans;
            if (events[i][j].second > 0) cut(events[i][j].second);
            else link(-events[i][j].second,parent[-events[i][j].second]);
        }
        if (!events[i].empty()) diff[events[i].back().first] += ans;
        else diff[0] += (LLI) n*n;
    }
    for (i = 1; i <= m; i++) diff[i] += diff[i-1];
    for (i = 0; i <= m; i++) printf("%I64d\n",(LLI) n*n*n-diff[i]);

    return 0;
}