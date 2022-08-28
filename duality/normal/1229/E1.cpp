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

int inv(int n) {
    int e = MOD-2,r = 1;
    while (e > 0) {
        if (e & 1) r = ((LLI) r*n) % MOD;
        e >>= 1;
        n = ((LLI) n*n) % MOD;
    }
    return r;
}
vi masks,masks2;
int prob[1 << 20],prob2[1 << 20];
int P[6][6];
int main() {
    int i,j;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) scanf("%d",&P[i][j]);
    }

    int k,h = (n+1)/2;
    int h2 = n-h;
    int inv100 = inv(100);
    for (i = 0; i < (1 << n); i++) {
        int c = 0;
        for (j = 0; j < n; j++) {
            if (i & (1 << j)) c++;
        }
        if (c == h) masks.pb(i);
        if (c == h2) masks2.pb(i);
    }
    for (i = 0; i < (1 << (n*h)); i++) {
        LLI p = 1;
        for (j = 0; j < n*h; j++) {
            int x = j/n,y = j % n;
            if (i & (1 << j)) p *= ((LLI) P[x][y]*inv100) % MOD,p %= MOD;
            else p *= ((LLI) (100-P[x][y])*inv100) % MOD,p %= MOD;
        }
        int poss = 0;
        for (j = 0; j < masks.size(); j++) {
            vi v;
            for (k = 0; k < n; k++) {
                if (masks[j] & (1 << k)) v.pb(k);
            }
            do {
                for (k = 0; k < v.size(); k++) {
                    int a = k*n+v[k];
                    if (!(i & (1 << a))) break;
                }
                if (k == v.size()) {
                    poss |= (1 << j);
                    break;
                }
            } while (next_permutation(v.begin(),v.end()));
        }
        prob[poss] += p,prob[poss] %= MOD;
    }
    for (i = 0; i < (1 << (n*h2)); i++) {
        LLI p = 1;
        for (j = 0; j < n*h2; j++) {
            int x = j/n+h,y = j % n;
            if (i & (1 << j)) p *= ((LLI) P[x][y]*inv100) % MOD,p %= MOD;
            else p *= ((LLI) (100-P[x][y])*inv100) % MOD,p %= MOD;
        }
        int poss = 0;
        for (j = 0; j < masks.size(); j++) {
            vi v;
            for (k = 0; k < n; k++) {
                if (!(masks[j] & (1 << k))) v.pb(k);
            }
            do {
                for (k = 0; k < v.size(); k++) {
                    int a = k*n+v[k];
                    if (!(i & (1 << a))) break;
                }
                if (k == v.size()) {
                    poss |= (1 << j);
                    break;
                }
            } while (next_permutation(v.begin(),v.end()));
        }
        prob2[poss] += p,prob2[poss] %= MOD;
    }
    LLI ans = 0;
    for (i = 0; i < masks.size(); i++) {
        for (j = 0; j < (1 << masks.size()); j++) {
            if (j & (1 << i)) prob2[j] += prob2[j^(1 << i)],prob2[j] %= MOD;
        }
    }
    for (i = 0; i < (1 << masks.size()); i++) ans += (LLI) prob[i]*prob2[((1 << masks.size())-1)^i],ans %= MOD;
    printf("%I64d\n",(MOD+1-ans) % MOD);

    return 0;
}