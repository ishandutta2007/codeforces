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

vi adjList[100000];
pii dp[100000];
int num[100000],c = 0;
vi adjList2[100000];
int doDFS(int u,int p) {
    int i;
    num[u] = c++;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS(v,u),adjList2[num[u]].pb(num[v]);
    }
    return 0;
}
int ans[100001];
int getAns(int n,int k) {
    if (ans[k] != -1) return ans[k];
    int u,i;
    for (u = n-1; u >= 0; u--) {
        int paths = 0,len1 = 0,len2 = 0;
        for (i = 0; i < adjList2[u].size(); i++) {
            int v = adjList2[u][i];
            paths += dp[v].first;
            if (dp[v].second >= len1) len2 = len1,len1 = dp[v].second;
            else if (dp[v].second >= len2) len2 = dp[v].second;
        }
        if (len1+len2+1 >= k) dp[u] = mp(paths+1,0);
        else dp[u] = mp(paths,len1+1);
    }
    return ans[k] = dp[0].first;
}
int main() {
    int i;
    int n,u,v;
    scanf("%d",&n);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    doDFS(0,-1);
    fill(ans,ans+n+1,-1);

    int B = sqrt(n);
    for (i = 1; i <= B; i++) ans[i] = getAns(n,i);
    int c = B;
    while (c < n) {
        int l = c,r = n;
        while (l < r) {
            int m = (l+r+1) / 2;
            if (getAns(n,m) == ans[c]) l = m;
            else r = m-1;
        }
        fill(ans+c,ans+l+1,ans[c]);
        c = l+1,ans[c] = getAns(n,l+1);
    }
    for (i = 1; i <= n; i++) printf("%d\n",ans[i]);

    return 0;
}