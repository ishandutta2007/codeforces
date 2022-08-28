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
#define MOD1 1000000007
#define S1 37
#define MOD2 1000000009
#define S2 43

int inv(LLI n,int MOD) {
    int e = MOD-2;
    LLI r = 1;
    while (e > 0) {
        if (e & 1) r *= n,r %= MOD;
        e >>= 1;
        n *= n,n %= MOD;
    }
    return r;
}
LLI sum[1000001],sum2[1000001];
LLI pow1[1000001],pow2[1000001];
pii getHash(int l,int r) {
    LLI a = sum[r+1]-sum[l]*pow1[r-l+1];
    a %= MOD1;
    if (a < 0) a += MOD1;
    LLI b = sum2[r+1]-sum2[l]*pow2[r-l+1];
    b %= MOD2;
    if (b < 0) b += MOD2;
    return mp(a,b);
}
int main() {
    string s,t;
    cin >> s >> t;

    int i,j;
    int c0 = 0,c1 = 0;
    for (i = 0; i < s.size(); i++) {
        if (s[i] == '0') c0++;
        else c1++;
    }
    pow1[0] = pow2[0] = 1;
    for (i = 0; i < t.size(); i++) {
        sum[i+1] = (S1*sum[i]+t[i]) % MOD1;
        sum2[i+1] = (S2*sum2[i]+t[i]) % MOD2;
        pow1[i+1] = (pow1[i]*S1) % MOD1;
        pow2[i+1] = (pow2[i]*S2) % MOD2;
    }
    int ans = 0;
    for (i = 1; i <= t.size(); i++) {
        LLI x = (LLI) i*c0;
        if ((x < t.size()) && (((t.size()-x) % c1) == 0)) {
            int l0 = i,l1 = (t.size()-x)/c1;
            int p = 0;
            pii h1 = mp(-1,-1),h2 = mp(-1,-1);
            int no = 0;
            for (j = 0; j < s.size(); j++) {
                if (s[j] == '0') {
                    pii h = getHash(p,p+l0-1);
                    if (h1 == mp(-1,-1)) h1 = h;
                    if (h1 != h) {
                        no = 1;
                        break;
                    }
                    p += l0;
                }
                else {
                    pii h = getHash(p,p+l1-1);
                    if (h2 == mp(-1,-1)) h2 = h;
                    if (h2 != h) {
                        no = 1;
                        break;
                    }
                    p += l1;
                }
            }
            if (!no && (h1 != h2)) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}