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
#define MOD 1000000007

int a[60],s[61],b[60];
LLI adj[60];
int visited[60];
vi cc;
int doDFS(int u) {
    if (visited[u]) return 0;
    int i;
    visited[u] = 1,cc.pb(u);
    for (i = 0; i < 60; i++) {
        if (adj[u] & (1LL << i)) doDFS(i);
    }
    return 0;
}
int C[61][61];
map<LLI,int> dp[61];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    sort(a,a+n);

    int j,k;
    int m = 0;
    for (i = 0; i < n; i++) {
        if (!s[a[i]]) {
            for (j = 2*a[i]; j <= 60; j += a[i]) s[j] = 1;
        }
        else b[m++] = a[i];
    }
    for (i = 0; i < m; i++) {
        adj[i] |= (1LL << i);
        for (j = i+1; j < m; j++) {
            for (k = 0; k < n; k++) {
                if (((b[i] % a[k]) == 0) && ((b[j] % a[k]) == 0)) break;
            }
            if (k < n) adj[i] |= (1LL << j),adj[j] |= (1LL << i);
        }
    }
    int ans = 1,sum = 0;
    for (i = 0; i <= m; i++) {
        C[i][0] = 1;
        for (j = 1; j <= i; j++) C[i][j] = (C[i-1][j-1]+C[i-1][j]) % MOD;
    }
    for (i = 0; i < m; i++) {
        if (!visited[i]) {
            doDFS(i);
            for (j = 0; j < cc.size(); j++) dp[1][adj[cc[j]]]++;
            for (j = 1; j < cc.size(); j++) {
                for (auto it = dp[j].begin(); it != dp[j].end(); it++) {
                    int c = 0;
                    for (k = 0; k < cc.size(); k++) {
                        if (it->first & (1LL << cc[k])) {
                            if ((it->first | adj[cc[k]]) != it->first) {
                                dp[j+1][it->first | adj[cc[k]]] += it->second;
                                if (dp[j+1][it->first | adj[cc[k]]] >= MOD) dp[j+1][it->first | adj[cc[k]]] -= MOD;
                            }
                            else c++;
                        }
                    }
                    if (c > j) dp[j+1][it->first] = (dp[j+1][it->first]+(LLI) it->second*(c-j)) % MOD;
                }
            }
            ans = ((LLI) ans*dp[cc.size()].begin()->second) % MOD;
            ans = ((LLI) ans*C[sum+cc.size()-1][cc.size()-1]) % MOD;
            sum += cc.size()-1;
            for (j = 1; j <= cc.size(); j++) dp[j].clear();
            cc.clear();
        }
    }
    printf("%d\n",ans);

    return 0;
}