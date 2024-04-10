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
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int B = 1;
vpii adjList[250000];
LLI dp[250000][2];
int doDFS(int u,int p,int d) {
    int i;
    vlli x;
    dp[u][0] = dp[u][1] = 0;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i].first;
        if (v != p) {
            doDFS(v,u,d),dp[u][1] += dp[v][0];
            x.pb(adjList[u][i].second+dp[v][1]-dp[v][0]);
        }
    }
    sort(x.begin(),x.end());
    int need = (int) x.size()-d;
    dp[u][0] = dp[u][1];
    for (i = 0; i < x.size(); i++) {
        if ((i >= need) && (x[i] > 0)) break;
        dp[u][1] += x[i];
    }
    need++;
    if (need == x.size()+1) dp[u][0] = 1e18;
    else {
        for (i = 0; i < x.size(); i++) {
            if ((i >= need) && (x[i] > 0)) break;
            dp[u][0] += x[i];
        }
    }
    return 0;
}
int ll[250000],visited[250000];
vpii adjList2[500000];
vlli sorted[500000],sum[500000];
int doDFS2(int u,int p,int d) {
    visited[u] = 1;
    int i;
    vlli x;
    dp[u][0] = dp[u][1] = 0;
    for (i = 0; i < adjList2[u].size(); i++) {
        int v = adjList2[u][i].first;
        if (v != p) {
            doDFS2(v,u,d),dp[u][1] += dp[v][0];
            x.pb(adjList2[u][i].second+dp[v][1]-dp[v][0]);
        }
    }
    sort(x.begin(),x.end());
    printArr(x,x.size());
    int need = (int) x.size()+(int) sorted[u].size()-d,c = 0,s = 0;
    dp[u][0] = dp[u][1];
    for (i = 0; i < x.size(); i++) {
        if (x[i] < 0) dp[u][1] += x[i],c++;
        else {
            if (c+s >= need) break;
            int p = upper_bound(sorted[u].begin(),sorted[u].end(),x[i])-sorted[u].begin()-1;
            if (p+1+c >= need) s = need-c;
            else s = p,dp[u][1] += x[i],c++;
        }
    }
    if (c+s < need) s = need-c;
    printVar(s);
    dp[u][1] += (s == 0) ? 0:sum[u][s-1];
    printVar(dp[u][1]);
    need++;
    if (need == x.size()+sorted[u].size()+1) dp[u][0] = 1e18;
    else {
        c = s = 0;
        for (i = 0; i < x.size(); i++) {
            if (x[i] < 0) dp[u][0] += x[i],c++;
            else {
                if (c+s >= need) break;
                int p = upper_bound(sorted[u].begin(),sorted[u].end(),x[i])-sorted[u].begin()-1;
                if (p+1+c >= need) s = need-c;
                else s = p,dp[u][0] += x[i],c++;
            }
        }
        if (c+s < need) s = need-c;
        printVar(s);
        dp[u][0] += (s == 0) ? 0:sum[u][s-1];
    }
    return 0;
}
int main() {
    int i;
    int n,a,b,c;
    scanf("%d",&n);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d %d",&a,&b,&c);
        a--,b--;
        adjList[a].pb(mp(b,c));
        adjList[b].pb(mp(a,c));
    }

    int j,k,p = 0;
    for (k = 1; k < n; k <<= 1) {
        vi large;
        fill(ll,ll+n,-1);
        B = k-1;
        for (i = 0; i < n; i++) {
            if (adjList[i].size() > B) large.pb(i),ll[i] = large.size()-1;
        }
        debug "here";
        for (i = 0; i < large.size(); i++) {
            int u = large[i];
            debug u;
            for (j = 0; j < adjList[u].size(); j++) {
                int v = adjList[u][j].first;
                if (ll[v] != -1) adjList2[i].pb(mp(ll[v],adjList[u][j].second));
                else sorted[i].pb(adjList[u][j].second);
            }
            debug "here";
            sort(sorted[i].begin(),sorted[i].end());
            sum[i].resize(sorted[i].size());
            for (j = 0; j < sorted[i].size(); j++) sum[i][j] = ((j == 0) ? 0:sum[i][j-1])+sorted[i][j];
            printArr(sorted[i],sorted[i].size());
            printArr(sum[i],sum[i].size());
        }
        printArr(large,large.size());

        for (i = p; i < min(n,2*(p+1)); i++) {
            LLI ans = 0;
            fill(visited,visited+large.size(),0);
            for (j = 0; j < large.size(); j++) {
                if (!visited[j]) {
                    doDFS2(j,-1,i);
                    ans += dp[j][1];
                }
            }
            debug "ANS";
            printf("%I64d ",ans);
            debug "ANS";
        }
        p = i;

        for (i = 0; i < large.size(); i++) sorted[i].clear(),sum[i].clear(),adjList2[i].clear();
    }
    printf("\n");

    return 0;
}