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

vplli v;
int main() {
    LLI x0,y0,ax,ay,bx,by;
    LLI x,y,t;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    cin >> x >> y >> t;

    int i;
    v.pb(mp(x0,y0));
    while ((x0 < 3e16) && (y0 < 3e16)) {
        x0 = ax*x0+bx,y0 = ay*y0+by;
        if ((x0 < 3e16) && (y0 < 3e16)) v.pb(mp(x0,y0));
    }
    int j,k,ans = 0;
    for (i = 0; i < v.size(); i++) {
        LLI tt = t-abs(v[i].first-x)-abs(v[i].second-y);
        if (tt >= 0) {
            for (j = 0; j < v.size(); j++) {
                for (k = 0; k < v.size(); k++) {
                    LLI ttt = tt;
                    ttt -= abs(v[i].first-v[j].first)+abs(v[i].second-v[j].second);
                    ttt -= abs(v[j].first-v[k].first)+abs(v[j].second-v[k].second);
                    if (ttt >= 0) ans = max(ans,max(max(i,j),k)-min(min(i,j),k)+1);
                }
            }
        }
    }
    printf("%d\n",ans);

    return 0;
}