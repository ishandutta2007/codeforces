#define DEBUG 1

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

struct line { LLI m,b; };
bool comp(line a,line b) {
    if (a.m == b.m) return a.b > b.b;
    else return a.m > b.m;
}
int bad(line a,line b,line c) {
    return (b.b-a.b)*(b.m-c.m) >= (c.b-b.b)*(a.m-b.m);
}
int n;
vi adjList[500000];
int size[500000];
LLI down[500000],best = 1e18;
vplli nums;
vector<line> lines,hull;
int solve(int l,int r) {
    if (l == r) return 0;
    int i,mid = (l+r) / 2;
    solve(l,mid),solve(mid+1,r);
    for (i = l; i <= mid; i++) lines.pb((line){2*nums[i].first,nums[i].second});
    sort(lines.begin(),lines.end(),comp);
    for (i = 0; i < lines.size(); i++) {
        line l = lines[i];
        while ((hull.size() >= 1) && (l.m == hull.back().m)) hull.pop_back();
        while ((hull.size() >= 2) && bad(hull[hull.size()-2],hull.back(),l)) hull.pop_back();
        hull.pb(l);
    }
    lines.clear();
    for (i = mid+1; i <= r; i++) lines.pb((line){nums[i].first,nums[i].second});
    sort(lines.begin(),lines.end(),comp);
    int j = 0;
    for (i = 0; i < lines.size(); i++) {
        while ((j < hull.size()-1) && (hull[j].m*lines[i].m+hull[j].b \
            > hull[j+1].m*lines[i].m+hull[j+1].b)) j++;
        best = min(best,hull[j].m*lines[i].m+hull[j].b+lines[i].b+(LLI) n*n);
    }
    lines.clear(),hull.clear();
    return 0;
}
int doDFS(int u,int p) {
    int i;
    size[u] = 1,down[u] = 1e18;
    vplli vv;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) {
            doDFS(v,u);
            size[u] += size[v];
            vv.pb(mp(size[v],(LLI) size[v]*size[v]+down[v]-2LL*n*size[v]));
            best = min(best,down[v]+(LLI) (n-size[v])*(n-size[v]));
        }
    }
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) down[u] = min(down[u],down[v]+(LLI) (size[u]-size[v])*(size[u]-size[v]));
    }
    down[u] = min(down[u],(LLI) size[u]*size[u]);
    if (!vv.empty()) {
        nums = vv;
        solve(0,(int) vv.size()-1);
    }
    return 0;
}
int main() {
    int i;
    int u,v;
    scanf("%d",&n);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    doDFS(0,-1);
    printf("%I64d\n",(LLI) n*n-(best+n)/2);

    return 0;
}