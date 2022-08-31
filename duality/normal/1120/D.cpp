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

int c[200000],leaf[200000];
vi adjList[200000];
LLI dp[200000][2];
vi child[200000][2];
int doDFS(int u,int p) {
    int i;
    vector<pair<plli,int> > vv;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) {
            doDFS(v,u);
            vv.pb(mp(mp(dp[v][0],dp[v][1]),v));
        }
    }
    if (vv.empty()) {
        dp[u][0] = c[u],dp[u][1] = 0;
        leaf[u] = 1;
        return 0;
    }
    LLI m = 1;
    vi pp;
    for (i = 0; i < vv.size(); i++) {
        dp[u][0] += vv[i].first.first;
        LLI x = vv[i].first.second-vv[i].first.first;
        if (x < m) m = x,pp.clear(),pp.pb(vv[i].second);
        else if (x == m) pp.pb(vv[i].second);
    }
    child[u][1] = pp;
    if (m == 0) child[u][1].pb(-1);
    dp[u][1] = dp[u][0] + m;
    if (m+c[u] > 0) child[u][0].pb(-1);
    else {
        dp[u][0] += m+c[u],child[u][0] = pp;
        if (m+c[u] == 0) child[u][0].pb(-1);
    }
    return 0;
}
vi sol;
int done[200000][2];
int doDFS2(int u,int p,int take) {
    if (done[u][take]) return 0;
    if (leaf[u]) {
        if (!take) sol.pb(u);
        return 0;
    }

    int i;
    done[u][take] = 1;
    if (take) {
        int j = 0;
        for (i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i];
            if (v == p) continue;
            while ((j < child[u][1].size()) && (child[u][1][j] < v)) j++;
            if ((j < child[u][1].size()) && (child[u][1][j] == v)) {
                if (child[u][1].size() >= 2) doDFS2(v,u,0);
                doDFS2(v,u,1);
            }
            else doDFS2(v,u,0);
        }
    }
    else {
        int j = 0;
        for (i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i];
            if (v == p) continue;
            while ((j < child[u][0].size()) && (child[u][0][j] < v)) j++;
            if ((j < child[u][0].size()) && (child[u][0][j] == v)) {
                if (child[u][0].size() >= 2) doDFS2(v,u,0);
                doDFS2(v,u,1);
            }
            else doDFS2(v,u,0);
        }
        if ((child[u][0].size() >= 2) || (child[u][0][0] != -1)) sol.pb(u);
    }
    return 0;
}
int main() {
    int i;
    int n,a,b;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&c[i]);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&a,&b);
        a--,b--;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }
    for (i = 0; i < n; i++) sort(adjList[i].begin(),adjList[i].end());
    doDFS(0,-1);
    for (i = 0; i < n; i++) {
        sort(child[i][0].begin(),child[i][0].end());
        sort(child[i][1].begin(),child[i][1].end());
    }
    printf("%I64d ",dp[0][0]);
    for (i = 0;i<n;i++){
    //    printArr(child[i][0],child[i][0].size());
    }
    for (i = 0; i < n; i++) {
        if (c[i] == 0) sol.pb(i);
    }
    doDFS2(0,-1,0);
    sort(sol.begin(),sol.end());
    sol.resize(unique(sol.begin(),sol.end())-sol.begin());
    printf("%d\n",sol.size());
    for (i = 0; i < sol.size(); i++) printf("%d ",sol[i]+1);
    printf("\n");

    return 0;
}