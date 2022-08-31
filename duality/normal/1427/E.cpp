#define DEBUG 1

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

vector<pair<char,plli> > sol;
LLI gcd(LLI a,LLI b) {
    LLI t;
    while (a > 0) t = b % a,b = a,a = t;
    return b;
}
set<LLI> nums;
int main() {
    LLI x;
    cin >> x;
    sol.pb(mp('^',mp(x,x)));

    int i = 2;
    while (1) {
        if (gcd(x,x^((LLI) i*x)) == 1) break;
        else i++;
    }
    int p = i;
    LLI y = x;
    for (i = 0; i < 63; i++) {
        sol.pb(mp('+',mp(y,y))),y *= 2;
        if (y*2 > 4.5e18) break;
    }
    LLI c = 0;
    for (i = 0; i < 63; i++) {
        if (p & (1LL << i)) sol.pb(mp('+',mp(c,x*(1LL << i)))),c += x*(1LL << i);
    }
    sol.pb(mp('^',mp(x,(LLI) p*x)));
    y = x^((LLI) p*x);
    LLI z = y;
    for (i = 0; i < 63; i++) {
        sol.pb(mp('+',mp(z,z))),z *= 2;
        if (z*2 > 4.5e18) break;
    }

    LLI big = 4e18;
    LLI a,b;
    for (i = 0; i < x; i++) {
        if (((big-y*i) % x) == 0) {
            a = (big-y*i)/x,b = i;
            break;
        }
    }
    c = 0;
    for (i = 0; i < 63; i++) {
        if (a & (1LL << i)) sol.pb(mp('+',mp(c,x*(1LL << i)))),c += x*(1LL << i);
    }
    for (i = 0; i < 63; i++) {
        if (b & (1LL << i)) sol.pb(mp('+',mp(c,y*(1LL << i)))),c += y*(1LL << i);
    }
    big = 4e18;
    big++;
    for (i = 0; i < x; i++) {
        if (((big-y*i) % x) == 0) {
            a = (big-y*i)/x,b = i;
            break;
        }
    }
    c = 0;
    for (i = 0; i < 63; i++) {
        if (a & (1LL << i)) sol.pb(mp('+',mp(c,x*(1LL << i)))),c += x*(1LL << i);
    }
    for (i = 0; i < 63; i++) {
        if (b & (1LL << i)) sol.pb(mp('+',mp(c,y*(1LL << i)))),c += y*(1LL << i);
    }
    sol.pb(mp('^',mp(big,big-1)));

    printf("%d\n",sol.size());
    nums.insert(x);
    for (i = 0; i < sol.size(); i++) {
        printf("%I64d %c %I64d\n",sol[i].second.first,sol[i].first,sol[i].second.second);
        assert(nums.count(sol[i].second.first));
        assert(nums.count(sol[i].second.second));
        if (sol[i].first == '+') nums.insert(sol[i].second.first+sol[i].second.second);
        else nums.insert(sol[i].second.first^sol[i].second.second);
    }
    assert(nums.count(1));

    return 0;
}