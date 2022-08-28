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

int a[300000];
int f[300001];
int gcd(int a,int b) {
    int t;
    while (a > 0) t = b % a,b = a,a = t;
    return b;
}
int inv(LLI n) {
    int e = MOD-2;
    LLI r = 1;
    while (e > 0) {
        if (e & 1) r *= n,r %= MOD;
        e >>= 1;
        n *= n,n %= MOD;
    }
    return r;
}
vi fact[300001];
vpii check;
int occ[300001];
int main() {
    int i;
    int n,g = 0;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),g = gcd(g,a[i]);
    if (g != 1) {
        printf("-1\n");
        return 0;
    }
    for (i = 0; i < n; i++) {
        if (a[i] == 1) {
            printf("1\n");
            return 0;
        }
    }

    int j,k;
    for (i = 2; i <= 300000; i++) {
        if (f[i] == 0) {
            for (j = 2*i; j <= 300000; j += i) {
                if (f[j] == 0) f[j] = i;
            }
            f[i] = i;
        }
    }
    for (i = 1; i <= 300000; i++) {
        int t = i,x = 1;
        while (t > 1) {
            if (fact[i].empty() || (fact[i].back() != f[t])) fact[i].pb(f[t]),x *= f[t];
            t /= f[t];
        }
        if (x == i) check.pb(mp(i,(fact[i].size() & 1) ? -1:1));
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < (1 << fact[a[i]].size()); j++) {
            int x = 1;
            for (k = 0; k < fact[a[i]].size(); k++) {
                if (j & (1 << k)) x *= fact[a[i]][k];
            }
            occ[x]++;
        }
    }
    int ans = 2;
    while (1) {
        LLI c = 0;
        for (i = 0; i < check.size(); i++) {
            int u = check[i].first;
            LLI x = 1;
            for (j = 0; j < ans; j++) {
                x *= occ[u]-j,x %= MOD;
                x *= inv(j+1),x %= MOD;
            }
            c += check[i].second*x,c %= MOD;
        }
        if (c != 0) {
            printf("%d\n",ans);
            return 0;
        }
        else ans++;
    }

    return 0;
}