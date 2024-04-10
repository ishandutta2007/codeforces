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

vi adjList[200000],adjList2[200000];
set<pii> S;
int parent[200000],disc[200000],fin[200000],num = 0;
int doDFS(int u,int p) {
    int i;
    parent[u] = p,disc[u] = num++;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) adjList2[u].pb(v),doDFS(v,u);
    }
    fin[u] = num;
    return 0;
}
int tree[1 << 19],lazy[1 << 19],occ[1 << 19];
int build(int s,int e,int i) {
    if (s == e) {
        occ[i] = 1;
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    occ[i] = e-s+1;
    return 0;
}
int prop(int s,int e,int i) {
    tree[i] += lazy[i];
    if (s != e) lazy[2*i+1] += lazy[i],lazy[2*i+2] += lazy[i];
    lazy[i] = 0;
    return 0;
}
int update(int s,int e,int as,int ae,int i,int num) {
    prop(s,e,i);
    if ((s > ae) || (e < as)) return 0;
    else if ((s >= as) && (e <= ae)) {
        lazy[i] += num;
        prop(s,e,i);
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,as,ae,2*i+1,num),update(mid+1,e,as,ae,2*i+2,num);
    tree[i] = min(tree[2*i+1],tree[2*i+2]),occ[i] = 0;
    if (tree[i] == tree[2*i+1]) occ[i] += occ[2*i+1];
    if (tree[i] == tree[2*i+2]) occ[i] += occ[2*i+2];
    return 0;
}
int update(int u,int v,int n,int num) {
    if (disc[u] < disc[v]) swap(u,v);
    if ((disc[u] >= disc[v]) && (disc[u] < fin[v])) {
        update(0,n-1,disc[u],fin[u]-1,0,-num);
        int l = 0,r = adjList2[v].size()-1;
        while (l < r) {
            int m = (l+r+1) / 2;
            if (disc[u] >= disc[adjList2[v][m]]) l = m;
            else r = m-1;
        }
        int w = adjList2[v][l];
        update(0,n-1,disc[w],fin[w]-1,0,num);
    }
    else {
        update(0,n-1,0,n-1,0,num);
        update(0,n-1,disc[u],fin[u]-1,0,-num);
        update(0,n-1,disc[v],fin[v]-1,0,-num);
    }
    return 0;
}
int main() {
    int i;
    int n,q,u,v;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    doDFS(0,-1);
    build(0,n-1,0);
    for (i = 0; i < q; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        if (u > v) swap(u,v);
        if (S.count(mp(u,v))) update(u,v,n,-1),S.erase(mp(u,v));
        else update(u,v,n,1),S.insert(mp(u,v));
        prop(0,n-1,0);
        printf("%d\n",(tree[0] == 0) ? occ[0]:0);
    }

    return 0;
}