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

int p[200000];
map<int,LLI> dp[200000];
vi adjList[200000];
int s[200000];
LLI findAns(int u,int k) {
    if (dp[u].count(k)) return dp[u][k];
    else if (adjList[u].empty()) return (LLI) k*s[u];

    LLI sum = 0;
    vlli diff;
    for (int v: adjList[u]) {
        sum += findAns(v,k/adjList[u].size());
        diff.pb(findAns(v,(k+adjList[u].size()-1)/adjList[u].size())-findAns(v,k/adjList[u].size()));
    }
    LLI ans = sum;
    sort(diff.begin(),diff.end(),greater<LLI>());
    for (int i = 0; i < (k % adjList[u].size()); i++) ans += diff[i];
    ans += (LLI) k*s[u];
    dp[u][k] = ans;
    return ans;
}
int main() {
    int i;
    int t,n,k;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&k);
        p[0] = -1;
        for (i = 1; i < n; i++) scanf("%d",&p[i]),p[i]--;
        for (i = 1; i < n; i++) adjList[p[i]].pb(i);
        for (i = 0; i < n; i++) scanf("%d",&s[i]);
        printf("%lld\n",findAns(0,k));
        for (i = 0; i < n; i++) adjList[i].clear(),dp[i].clear();
    }
    
    return 0;
}