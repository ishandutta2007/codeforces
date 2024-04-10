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

int t[200000],h[200000];
vi adjList[200000];
LLI dp[200000][2];
int doDFS(int u,int p) {
    int i;
    vi c;
    int in = 0,out = 0;
    LLI xx = 0;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) {
            doDFS(v,u);
            if (h[v] > h[u]) out++,xx += dp[v][0];
            else if (h[v] < h[u]) in++,xx += dp[v][1];
            else c.pb(v);
        }
    }
    dp[u][0] = dp[u][1] = 1e18;
    LLI xx2 = xx;
    int in2 = in+1;
    if (in2 <= adjList[u].size()/2) {
        vlli d;
        xx2 += (LLI) (adjList[u].size()-in2)*t[u];
        for (i = 0; i < c.size(); i++) {
            xx2 += dp[c[i]][0];
            d.pb(dp[c[i]][1]-dp[c[i]][0]);
        }
        sort(d.begin(),d.end());
        for (i = 0; i < d.size(); i++) {
            if ((in2+1 <= adjList[u].size()/2) && (d[i]-t[u] < 0)) xx2 += d[i]-t[u],in2++;
        }
        dp[u][0] = min(dp[u][0],xx2);
    }
    xx2 = xx;
    int out2 = out;
    if (out2 <= adjList[u].size()/2) {
        vlli d;
        xx2 += (LLI) (adjList[u].size()-out2)*t[u];
        for (i = 0; i < c.size(); i++) {
            xx2 += dp[c[i]][1];
            d.pb(dp[c[i]][0]-dp[c[i]][1]);
        }
        sort(d.begin(),d.end());
        for (i = 0; i < d.size(); i++) {
            if ((out2+1 <= adjList[u].size()/2) && (d[i]-t[u] < 0)) xx2 += d[i]-t[u],out2++;
        }
        dp[u][0] = min(dp[u][0],xx2);
    }
    xx2 = xx,in2 = in;
    if (in2 <= adjList[u].size()/2) {
        vlli d;
        xx2 += (LLI) (adjList[u].size()-in2)*t[u];
        for (i = 0; i < c.size(); i++) {
            xx2 += dp[c[i]][0];
            d.pb(dp[c[i]][1]-dp[c[i]][0]);
        }
        sort(d.begin(),d.end());
        for (i = 0; i < d.size(); i++) {
            if ((in2+1 <= adjList[u].size()/2) && (d[i]-t[u] < 0)) xx2 += d[i]-t[u],in2++;
        }
        dp[u][1] = min(dp[u][1],xx2);
    }
    xx2 = xx,out2 = out+1;
    if (out2 <= adjList[u].size()/2) {
        vlli d;
        xx2 += (LLI) (adjList[u].size()-out2)*t[u];
        for (i = 0; i < c.size(); i++) {
            xx2 += dp[c[i]][1];
            d.pb(dp[c[i]][0]-dp[c[i]][1]);
        }
        sort(d.begin(),d.end());
        for (i = 0; i < d.size(); i++) {
            if ((out2+1 <= adjList[u].size()/2) && (d[i]-t[u] < 0)) xx2 += d[i]-t[u],out2++;
        }
        dp[u][1] = min(dp[u][1],xx2);
    }
    return 0;
}
int main() {
    int i;
    int n,u,v;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&t[i]);
    for (i = 0; i < n; i++) scanf("%d",&h[i]);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    for (i = 0; i < n; i++) {
        if (adjList[i].size() == 1) break;
    }
    int r = i,c = adjList[i][0];
    doDFS(c,r);
    LLI ans;
    if (h[r] > h[c]) ans = dp[c][1];
    else if (h[r] < h[c]) ans = dp[c][0];
    else ans = min(dp[c][0],dp[c][1]);
    ans += t[r];
    printf("%I64d\n",ans);

    return 0;
}