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
#define SIZE 100000000U

bitset<SIZE+10> bs;
vi primes;
int main() {
    int i;
    UI n,A,B,C,D;
    cin >> n >> A >> B >> C >> D;

    int j;
    bs.set();
    bs[0] = bs[1] = 0;
    for (i = 2; i*i <= n; (i == 2) ? (i = 3):(i += 2)) {
        if (bs[i]) {
            for (j = i*i; j <= min(n,SIZE); j += i) bs[j] = 0;
            primes.pb(i);
        }
    }
    int c = i;
    UI ans = 0;
    for (i = 0; i < primes.size(); i++) {
        int p = primes[i];
        j = p;
        while (1) {
            ans += (n/j)*(A*p*p*p+B*p*p+C*p+D);
            if ((LLI) j*p <= n) j *= p;
            else break;
        }
        //cout<<p<<endl;
    }
    int d = c;
    while (c <= n) {
        if (bs[d]) {
            //cout<<c<<endl;
            ans += (n/c)*(A*c*c*c+B*c*c+C*c+D);
        }
        c++,d++;
        if (d > SIZE-3) {
            bs.set();
            for (i = 0; i < primes.size(); i++) {
                int p = primes[i];
                for (j = ((c+p-1)/p)*p; j <= min(n,c+SIZE); j += p) bs[j-c] = 0;
            }
            d = 0;
        }
    }
    printf("%u\n",ans);

    return 0;
}