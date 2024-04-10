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

int modPow(int b,int e) {
    int r = 1;
    while (e > 0) {
        if (e & 1) r = ((LLI) r*b) % MOD;
        e >>= 1;
        b = ((LLI) b*b) % MOD;
    }
    return r;
}
int fact[41],C[41][41],ways[40];
int p[40],v[40],occ[41],occ2[41];
int dp[1000000];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&p[i]),p[i]--;

    int j,k;
    fact[0] = 1;
    for (i = 1; i <= n; i++) fact[i] = ((LLI) i*fact[i-1]) % MOD;
    for (i = 0; i <= n; i++) {
        C[i][0] = 1;
        for (j = 1; j <= i; j++) C[i][j] = (C[i-1][j-1]+C[i-1][j]) % MOD;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            ways[i] += ((((LLI) C[i][j]*fact[j]) % MOD)*fact[n-j-1]) % MOD;
            ways[i] %= MOD;
        }
    }
    for (i = 0; i < n; i++) {
        if (!v[i]) {
            int u = i,c = 0;
            while (!v[u]) v[u] = 1,u = p[u],c++;
            occ[c]++;
        }
    }
    int s = 1;
    for (i = 1; i <= n; i++) s *= occ[i]+1;
    dp[0] = 1;
    for (i = 1; i < s; i++) {
        int t = i,s2 = 1,sum = 0;
        for (j = 1; j <= n; j++) {
            occ2[j] = t % (occ[j]+1),s2 *= occ2[j]+1,sum += occ2[j]*j;
            t /= occ[j]+1;
        }
        for (j = 1; j < s2; j++) {
            int t2 = j,sum2 = 0,num = 0,j2 = 0,pp = 1;
            LLI c = 1;
            for (k = 1; k <= n; k++) {
                int occ3 = t2 % (occ2[k]+1);
                c *= C[occ2[k]][occ3],c %= MOD,num += occ3,sum2 += occ3*k;
                j2 += (occ2[k]-occ3)*pp;
                t2 /= occ2[k]+1,pp *= occ[k]+1;
            }
            if (!(num & 1)) c = MOD-c;
            c *= dp[j2],c %= MOD;
            dp[i] += (c*modPow(ways[sum-sum2],sum2)) % MOD,dp[i] %= MOD;
        }
    }
    printf("%d\n",dp[s-1]);

    return 0;
}