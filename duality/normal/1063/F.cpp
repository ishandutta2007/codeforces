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
#define S1 37
#define MOD1 1000000007
#define S2 43
#define MOD2 1000000009

char s[500000];
int h1[500001],p1[500001];
int h2[500001],p2[500001];
LLI getHash(int l,int r) {
    return ((h1[r+1]-(((LLI) h1[l]*p1[r-l+1]) % MOD1)+MOD1) % MOD1)*MOD2 \
         + ((h2[r+1]-(((LLI) h2[l]*p2[r-l+1]) % MOD2)+MOD2) % MOD2);
}
unordered_set<LLI> S;
int dp[500000];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf(" %c",&s[i]);

    int ans = 0;
    int j = n-1,k;
    p1[0] = p2[0] = 1;
    for (i = 0; i < n; i++) {
        h1[i+1] = ((LLI) h1[i]*S1+s[i]) % MOD1,p1[i+1] = ((LLI) p1[i]*S1) % MOD1;
        h2[i+1] = ((LLI) h2[i]*S2+s[i]) % MOD2,p2[i+1] = ((LLI) p2[i]*S2) % MOD2;
    }
    S.insert(0);
    for (i = n-1; i >= 0; i--) {
        while (!S.count(getHash(i,j-1)) && !S.count(getHash(i+1,j))) {
            for (k = dp[j]-1; k >= 0; k--) {
                if (S.count(getHash(j,j+k))) break;
                else S.insert(getHash(j,j+k));
            }
            j--;
        }
        dp[i] = j-i+1,ans = max(ans,dp[i]);
    }
    printf("%d\n",ans);

    return 0;
}