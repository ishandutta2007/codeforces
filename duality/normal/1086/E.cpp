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
#define MOD 998244353

int a[2000][2000];
int D[2001],C[2001][2001],fact[2001];
int dp[2001][2001];
int bit[2001],bit2[2001],bit3[2001];
set<int> S;
int seen[2001];
int main() {
    int i,j;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) scanf("%d",&a[i][j]);
    }

    int k;
    D[0] = 1,D[1] = 0,D[2] = 1;
    for (i = 3; i <= n; i++) D[i] = ((LLI) (i-1)*(D[i-1]+D[i-2])) % MOD;
    for (i = 0; i <= n; i++) {
        dp[i][0] = 1;
        for (j = 1; j < i; j++) dp[i][j] = (dp[i-1][j]+(LLI) j*dp[i-1][j-1]) % MOD;
        dp[i][i] = D[i];
    }
    for (i = 0; i <= n; i++) {
        C[i][0] = 1;
        for (j = 1; j <= i; j++) C[i][j] = (C[i-1][j]+C[i-1][j-1]) % MOD;
    }
    fact[0] = 1;
    for (i = 1; i <= n; i++) fact[i] = ((LLI) i*fact[i-1]) % MOD;
    LLI ans = 0;
    for (i = 0; i < n; i++) {
        LLI m = 1,sum = 0;
        for (j = i+1; j < n; j++) m *= D[n],m %= MOD;
        fill(bit,bit+n+1,0),fill(bit2,bit2+n+1,0),S.clear(),fill(bit3,bit3+n+1,0),fill(seen,seen+n+1,0);
        if (i == 0) {
            for (j = 0; j < n; j++) {
                int x = 0;
                for (k = a[i][j]; k > 0; k -= k & (-k)) x += bit[k];
                x = a[i][j]-x-1;
                sum += ((LLI) fact[n-j-1]*x) % MOD,sum %= MOD;
                for (k = a[i][j]; k <= n; k += k & (-k)) bit[k]++;
            }
        }
        else {
            for (j = 0; j < n; j++) {
                S.insert(j+1);
                for (k = j+1; k <= n; k += k & (-k)) bit[k]++;
            }
            for (j = 0; j < n; j++) {
                if (S.count(a[i-1][j])) {
                    S.erase(a[i-1][j]);
                    if (!seen[a[i-1][j]]) {
                        //cout<<"move "<<a[i-1][j]<<endl;
                        for (k = a[i-1][j]; k <= n; k += k & (-k)) bit[k]--,bit2[k]++;
                    }
                }
                if (S.count(a[i][j])) {
                    //cout<<"del "<<a[i][j]<<" from bit1"<<endl;
                    for (k = a[i][j]; k <= n; k += k & (-k)) bit[k]--;
                }
                else {
                    //cout<<"del "<<a[i][j]<<" from bit2"<<endl;
                    for (k = a[i][j]; k <= n; k += k & (-k)) bit2[k]--;
                }
                for (k = a[i][j]; k <= n; k += k & (-k)) bit3[k]--;
                seen[a[i][j]] = 1;

                int p = 0;
                for (k = a[i][j]-1; k > 0; k -= k & (-k)) p += bit[k];
                if (S.count(a[i-1][j]) && !seen[a[i-1][j]] && (a[i-1][j] < a[i][j])) p--;
                int s = S.size()-1;
                printVar(p);
                sum += (p*(((LLI) dp[n-j-1][s]*fact[n-j-1-s]) % MOD)) % MOD;
                p = 0;
                for (k = a[i][j]-1; k > 0; k -= k & (-k)) p += bit2[k];
                if (!S.count(a[i-1][j]) && !seen[a[i-1][j]] && (a[i-1][j] < a[i][j])) p--;
                s = S.size();
                printVar(p);
                sum += (p*(((LLI) dp[n-j-1][s]*fact[n-j-1-s]) % MOD)) % MOD;


                /*for (k = 1; k < a[i][j]; k++) {
                    if (!seen[k] && (k != a[i-1][j])) {
                        int s = S.size();
                        if (S.count(k)) s--;
                        cout<<n-j-1<<","<<s<<endl;
                        sum += ((LLI) dp[n-j-1][s]*fact[n-j-1-s]) % MOD;
                    }
                }*/
                debug sum;
                if (S.count(a[i][j])) S.erase(a[i][j]);
                sum %= MOD;
            }
        }
        ans += (sum*m) % MOD,ans %= MOD;
    }
    printf("%I64d\n",ans);

    return 0;
}