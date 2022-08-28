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

int x[200000],y[200000];
double s[200000];
multiset<pair<long double,long double> > S;
int main() {
    int i;
    int n,L;
    scanf("%d %d",&n,&L);
    for (i = 0; i < n; i++) scanf("%d %d %lf",&x[i],&y[i],&s[i]);

    long double ans = x[0];
    S.insert(mp(1,1e18));
    for (i = 0; i < n; i++) {
        int d = y[i]-x[i];
        long double m = 1/(s[i]+1);
        long double l = d/s[i]+d/(s[i]+2);
        S.insert(mp(m,l));
        l = d/(s[i]+2)+0.5*(((i == n-1) ? L:x[i+1])-y[i]),ans += l;
        while (l > 0) {
            if (S.begin()->second < l) {
                l -= S.begin()->second;
                ans += S.begin()->first*S.begin()->second;
                S.erase(S.begin());
            }
            else {
                pair<long double,long double> p = *S.begin();
                p.second -= l;
                ans += p.first*l;
                l = 0;
                S.erase(S.begin()),S.insert(p);
            }
        }
    }
    printf("%.12lf\n",(double) ans);

    return 0;
}