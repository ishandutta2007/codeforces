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

LLI a[500];
int type[500];
vlli primes;
int isPrime(int n) {
    int i;
    for (i = 2; i*i <= n; i++) {
        if ((n % i) == 0) return 0;
    }
    return 1;
}
LLI gcd(LLI a,LLI b) {
    LLI t;
    while (a > 0) t = b % a,b = a,a = t;
    return b;
}
vi occ;
int main() {
    int i;
    int n;
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];

    int j;
    for (i = 0; i < n; i++) {
        int s = sqrt(a[i])-5;
        s = max(s,0);
        while ((LLI) s*s < a[i]) s++;
        if ((LLI) s*s == a[i]) {
            if (isPrime(s)) type[i] = 1,primes.pb(s);
            else type[i] = 3,primes.pb(round(sqrt(s)));
        }
        else {
            s = pow(a[i],(double) 1/3)-5;
            s = max(s,0);
            while ((LLI) s*s*s < a[i]) s++;
            if ((LLI) s*s*s == a[i]) type[i] = 2,primes.pb(s);
            else type[i] = 4;
        }
    }
    for (i = 0; i < n; i++) {
        if (type[i] == 4) {
            for (j = 0; j < primes.size(); j++) {
                if ((a[i] % primes[j]) == 0) {
                    primes.pb(a[i]/primes[j]);
                    break;
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if ((type[i] == 4) && (type[j] == 4) && (a[i] != a[j])) {
                LLI g = gcd(a[i],a[j]);
                if (g > 1) primes.pb(g),primes.pb(a[i]/g),primes.pb(a[j]/g);
            }
        }
    }
    sort(primes.begin(),primes.end());
    primes.resize(unique(primes.begin(),primes.end())-primes.begin());
    occ.resize(primes.size());
    printArr(primes,primes.size());
    int c = 0;
    LLI ans = 1;
    sort(a,a+n);
    for (i = 0; i < n; i++) {
        LLI x = a[i];
        for (j = 0; j < primes.size(); j++) {
            if ((x % primes[j]) == 0) {
                while ((x % primes[j]) == 0) occ[j]++,x /= primes[j];
            }
        }
        if (x > 1) c++;
        if ((i == n-1) || (a[i] != a[i+1])) {
            if (c > 0) ans *= ((LLI) (c+1)*(c+1)) % MOD,ans %= MOD;
            c = 0;
        }
    }
    for (i = 0; i < primes.size(); i++) ans *= occ[i]+1,ans %= MOD;
    cout << ans << endl;

    return 0;
}