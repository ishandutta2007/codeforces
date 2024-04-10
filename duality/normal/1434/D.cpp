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

int u[500000],v[500000],t[500000];
vi adjList[500000];
int parent[500000],disc[500000],fin[500000];
vi order;
int doDFS(int u,int p,int d) {
    int i;
    parent[u] = p,order.pb(d),disc[u] = order.size()-1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) {
            doDFS(v,u,d+1);
            order.pb(d);
        }
    }
    order.pb(d);
    fin[u] = order.size()-1;
    return 0;
}
struct node { int a0,a1,b,ab0,ab1,bc0,bc1,abc; };
node com(node a,node b) {
    node c;
    c.a0 = max(a.a0,b.a0),c.a1 = max(a.a1,b.a1),c.b = min(a.b,b.b);
    c.ab0 = max(max(a.ab0,b.ab0),a.a0-2*b.b);
    c.ab1 = max(max(a.ab1,b.ab1),a.a1-2*b.b);
    c.bc0 = max(max(a.bc0,b.bc0),-2*a.b+b.a0);
    c.bc1 = max(max(a.bc1,b.bc1),-2*a.b+b.a1);
    c.abc = max(max(a.abc,b.abc),max(max(a.ab0+b.a0,a.ab1+b.a1),max(a.a0+b.bc0,a.a1+b.bc1)));
    return c;
}
node tree[1 << 22];
int lazy[1 << 22];
int prop(int s,int e,int i) {
    if (lazy[i]) {
        swap(tree[i].a0,tree[i].a1);
        swap(tree[i].ab0,tree[i].ab1);
        swap(tree[i].bc0,tree[i].bc1);
        if (s != e) lazy[2*i+1] ^= 1,lazy[2*i+2] ^= 1;
        lazy[i] = 0;
    }
    return 0;
}
int build(int s,int e,int i) {
    if (s == e) {
        tree[i].a0 = order[s],tree[i].a1 = -1e9;
        tree[i].b = order[s];
        tree[i].ab0 = tree[i].ab1 = tree[i].bc0 = tree[i].bc1 = tree[i].abc = -1e9;
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    tree[i] = com(tree[2*i+1],tree[2*i+2]);
    return 0;
}
int update(int s,int e,int as,int ae,int i) {
    prop(s,e,i);
    if ((s > ae) || (e < as)) return 0;
    else if ((s >= as) && (e <= ae)) {
        lazy[i] ^= 1;
        prop(s,e,i);
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,as,ae,2*i+1),update(mid+1,e,as,ae,2*i+2);
    tree[i] = com(tree[2*i+1],tree[2*i+2]);
    return 0;
}
int main() {
    int i;
    int n,m,p;
    scanf("%d",&n);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d %d",&u[i],&v[i],&t[i]);
        u[i]--,v[i]--;
        adjList[u[i]].pb(v[i]);
        adjList[v[i]].pb(u[i]);
    }
    doDFS(0,-1,0);
    build(0,order.size()-1,0);
    for (i = 0; i < n-1; i++) {
        if (parent[u[i]] == v[i]) swap(u[i],v[i]);
        if (t[i] == 1) update(0,order.size()-1,disc[v[i]],fin[v[i]],0);
    }
    scanf("%d",&m);
    for (i = 0; i < m; i++) {
        scanf("%d",&p),p--;
        t[p] ^= 1;
        update(0,order.size()-1,disc[v[p]],fin[v[p]],0);
        printf("%d\n",max(tree[0].abc,0));
    }

    return 0;
}