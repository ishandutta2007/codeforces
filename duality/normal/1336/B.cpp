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

vpii v;
int best[300000];
int o[3];
LLI sq(LLI x) {
    return x*x;
}
int main() {
    int i;
    int t,a,b,c,x;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d %d",&a,&b,&c);
        for (i = 0; i < a; i++) scanf("%d",&x),v.pb(mp(x,0));
        for (i = 0; i < b; i++) scanf("%d",&x),v.pb(mp(x,1));
        for (i = 0; i < c; i++) scanf("%d",&x),v.pb(mp(x,2));
        sort(v.begin(),v.end());

        LLI ans = 9e18;
        o[0] = 0,o[1] = 1,o[2] = 2;
        do {
            int b = -1;
            for (i = v.size()-1; i >= 0; i--) {
                if (v[i].second == o[2]) b = i;
                best[i] = b;
            }
            b = -1;
            for (i = 0; i < v.size(); i++) {
                if (v[i].second == o[0]) b = i;
                if (v[i].second == o[1]) {
                    if ((best[i] != -1) && (b != -1))
                        ans = min(ans,sq(v[i].first-v[b].first)+sq(v[i].first-v[best[i]].first)+sq(v[b].first-v[best[i]].first));
                }
            }
        } while (next_permutation(o,o+3));
        printf("%I64d\n",ans);
        v.clear();
    }

    return 0;
}