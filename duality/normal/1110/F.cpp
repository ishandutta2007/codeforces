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

struct Query { int l,r,i; };
vpii adjList[500000];
vector<Query> queries[500000];
int fin[500000];
LLI dist[500000];
int doDFS(int u,LLI d) {
    int i;
    fin[u] = u;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i].first;
        fin[u] = max(fin[u],doDFS(v,d+adjList[u][i].second));
    }
    dist[u] = adjList[u].empty() ? d:MAX_VAL_2;
    return fin[u];
}
LLI tree[1 << 20],lazy[1 << 20];
LLI build(int s,int e,int i) {
    if (s == e) {
        tree[i] = dist[s];
        return tree[i];
    }

    int mid = (s+e) / 2;
    tree[i] = min(build(s,mid,2*i+1),build(mid+1,e,2*i+2));
    return tree[i];
}
int prop(int s,int e,int i) {
    tree[i] += lazy[i];
    if (s != e) lazy[2*i+1] += lazy[i],lazy[2*i+2] += lazy[i];
    lazy[i] = 0;
    return 0;
}
LLI update(int s,int e,int as,int ae,int i,int num) {
    prop(s,e,i);
    if ((s > ae) || (e < as)) return tree[i];
    else if ((s >= as) && (e <= ae)) {
        lazy[i] += num;
        prop(s,e,i);
        return tree[i];
    }

    int mid = (s+e) / 2;
    tree[i] = min(update(s,mid,as,ae,2*i+1,num),update(mid+1,e,as,ae,2*i+2,num));
    return tree[i];
}
LLI query(int s,int e,int qs,int qe,int i) {
    prop(s,e,i);
    if ((s > qe) || (e < qs)) return MAX_VAL_2;
    else if ((s >= qs) && (e <= qe)) return tree[i];

    int mid = (s+e) / 2;
    return min(query(s,mid,qs,qe,2*i+1),query(mid+1,e,qs,qe,2*i+2));
}
LLI ans[500000];
int doDFS2(int u,int n) {
    int i;
    for (i = 0; i < queries[u].size(); i++) ans[queries[u][i].i] = query(0,n-1,queries[u][i].l,queries[u][i].r,0);
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i].first;
        update(0,n-1,0,n-1,0,adjList[u][i].second);
        update(0,n-1,v,fin[v],0,-2*adjList[u][i].second);
        doDFS2(v,n);
        update(0,n-1,0,n-1,0,-adjList[u][i].second);
        update(0,n-1,v,fin[v],0,2*adjList[u][i].second);
    }
    return 0;
}
int main() {
    int i;
    int n,q,p,w;
    int v,l,r;
    scanf("%d %d",&n,&q);
    for (i = 1; i < n; i++) scanf("%d %d",&p,&w),adjList[p-1].pb(mp(i,w));
    for (i = 0; i < q; i++) scanf("%d %d %d",&v,&l,&r),queries[v-1].pb((Query){l-1,r-1,i});
    doDFS(0,0);
    build(0,n-1,0);
    doDFS2(0,n);
    for (i = 0; i < q; i++) printf("%I64d\n",ans[i]);

    return 0;
}