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

LLI w[1000000];
set<plli> S;
LLI num[1000000],d[1000000],h[1000000];
int main() {
    int i;
    int n;
    scanf("%d %*lld",&n);
    for (i = 0; i < n-2; i++) scanf("%lld",&w[i]);

    int m = 1;
    LLI b = 0;
    S.insert(mp(0,1e12));
    for (i = 0; i < n-2; i++) {
        auto it = S.lower_bound(mp(m*(w[i]-b),1e18));
        if (it != S.begin()) {
            it--;
            if ((it->first <= m*(w[i]-b)) && (m*(w[i]-b) <= it->second)) {
                num[i] = w[i];
                S.clear(),S.insert(mp(0,w[i])),m = 1,b = 0;
                continue;
            }
        }
        LLI l = m*(-b),r = m*(w[i]-b);
        if (l > r) swap(l,r);
        while (!S.empty() && (S.begin()->first < l)) {
            if (S.begin()->second < l) S.erase(S.begin());
            else {
                plli p = *S.begin();
                S.erase(S.begin());
                S.insert(mp(l,p.second));
            }
        }
        while (!S.empty() && ((--S.end())->second > r)) {
            if ((--S.end())->first > l) S.erase(--S.end());
            else {
                plli p = *(--S.end());
                S.erase(--S.end());
                S.insert(mp(p.first,r));
            }
        }
        if (S.empty()) {
            printf("NO\n");
            return 0;
        }
        num[i] = m*S.begin()->first+b;
        m *= -1,b = w[i]-b,S.insert(mp(m*(w[i]-b),m*(w[i]-b)));
    }
    d[n-2] = m*S.begin()->first+b;
    for (i = n-3; i >= 0; i--) {
        if (num[i] == w[i]) d[i] = w[i];
        else if (d[i+1] == w[i]) d[i] = num[i];
        else d[i] = w[i]-d[i+1];
    }
    h[0] = 0;
    for (i = 0; i < n-2; i++) {
        if (max(max(abs(d[i]),abs(d[i+1])),abs(d[i]+d[i+1])) != w[i]) d[i+1] *= -1;
    }
    for (i = 0; i < n-1; i++) h[i+1] = h[i]+d[i];
    LLI s = *min_element(h,h+n);
    printf("YES\n");
    for (i = 0; i < n; i++) h[i] -= s,printf("%lld%c",h[i],(i == n-1) ? '\n':' ');

    return 0;
}