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

int n,a[300000],r1[300000],r2[300000],r3[300000];
vi adjList[300000];
struct node {
    node *l,*r;
    int h1,h2,h3;
};
node *root[300000];
int build(int s,int e,node *n) {
    if (s == e) {
        n->l = n->r = NULL;
        n->h1 = r1[a[s]],n->h2 = r2[a[s]],n->h3 = r3[a[s]];
        return 0;
    }

    int mid = (s+e) / 2;
    n->l = new node,n->r = new node;
    build(s,mid,n->l),build(mid+1,e,n->r);
    n->h1 = n->l->h1 ^ n->r->h1;
    n->h2 = n->l->h2 ^ n->r->h2;
    n->h3 = n->l->h3 ^ n->r->h3;
    return 0;
}
int update(int s,int e,int ai,node *o,node *n,int a) {
    if (s == e) {
        n->l = n->r = NULL;
        n->h1 = o->h1^r1[a],n->h2 = o->h2^r2[a],n->h3 = o->h3^r3[a];
        return 0;
    }

    int mid = (s+e) / 2;
    if (ai <= mid) {
        n->r = o->r,n->l = new node;
        update(s,mid,ai,o->l,n->l,a);
    }
    else {
        n->l = o->l,n->r = new node;
        update(mid+1,e,ai,o->r,n->r,a);
    }
    n->h1 = n->l->h1 ^ n->r->h1;
    n->h2 = n->l->h2 ^ n->r->h2;
    n->h3 = n->l->h3 ^ n->r->h3;
    return 0;
}
int query(int s,int e,int qs,int qe,node *n1,node *n2) {
    if ((s > qe) || (e < qs)) return -1;
    else if ((s >= qs) && (e <= qe)) {
        if ((n1->h1 == n2->h1) && (n1->h2 == n2->h2) && (n1->h3 == n2->h3)) return -1;
        else if (s == e) return s;
        else {
            int mid = (s+e) / 2;
            int c = query(s,mid,qs,qe,n1->l,n2->l);
            if (c != -1) return c;
            else return query(mid+1,e,qs,qe,n1->r,n2->r);
        }
    }

    int mid = (s+e) / 2;
    int c = query(s,mid,qs,qe,n1->l,n2->l);
    if (c != -1) return c;
    else return query(mid+1,e,qs,qe,n1->r,n2->r);
}
int parent[300000][19],depth[300000];
int doDFS(int u,int p,int d) {
    int i;
    parent[u][0] = p,depth[u] = d;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) {
            root[v] = new node;
            update(0,n-1,a[v],root[u],root[v],a[v]);
            doDFS(v,u,d+1);
        }
    }
    return 0;
}
int logn;
int lca(int u,int v) {
    int i;
    if (depth[u] < depth[v]) swap(u,v);
    for (i = logn-1; i >= 0; i--) {
        if ((parent[u][i] != -1) && (depth[parent[u][i]] >= depth[v])) u = parent[u][i];
    }
    if (u == v) return u;
    for (i = logn-1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) u = parent[u][i],v = parent[v][i];
    }
    return parent[u][0];
}
int main() {
    int i,j;
    int q,u,v,l,r;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),a[i]--;
    mt19937 gen;
    for (i = 0; i < n; i++) {
        r1[i] = uniform_int_distribution<int>(0,(1 << 30)-1)(gen);
        r2[i] = uniform_int_distribution<int>(0,(1 << 30)-1)(gen);
        r3[i] = uniform_int_distribution<int>(0,(1 << 30)-1)(gen);
    }
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    root[0] = new node;
    build(0,n-1,root[0]);
    doDFS(0,-1,0);
    for (i = 1; (1 << i) < n; i++) {
        for (j = 0; j < n; j++) {
            if (parent[j][i-1] != -1) parent[j][i] = parent[parent[j][i-1]][i-1];
            else parent[j][i] = -1;
        }
    }
    logn = i;
    for (i = 0; i < q; i++) {
        scanf("%d %d %d %d",&u,&v,&l,&r);
        u--,v--,l--,r--;

        node *x = new node;
        int w = lca(u,v);
        update(0,n-1,a[w],root[u],x,a[w]);
        int c = query(0,n-1,l,r,x,root[v]);
        printf("%d\n",(c == -1) ? -1:c+1);
    }

    return 0;
}