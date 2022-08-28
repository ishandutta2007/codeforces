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
#define x first
#define y second

plli p[100000];
int ccw(plli a,plli b,plli c) {
    return (b.x-a.x)*(c.y-a.y) >= (b.y-a.y)*(c.x-a.x);
}
int coll(plli a,plli b,plli c) {
    return (b.x-a.x)*(c.y-a.y) == (b.y-a.y)*(c.x-a.x);
}
vplli hull;
int main() {
    int i;
    int n,a,b;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d %d",&a,&b),p[i] = mp(a,b-(LLI) a*a);
    sort(p,p+n);

    for (i = 0; i < n; i++) {
        while ((hull.size() >= 2) && ccw(hull[hull.size()-2],hull.back(),p[i])) hull.pop_back();
        hull.pb(p[i]);
    }
    int ans = 0;
    for (i = 0; i < hull.size()-1; i++) {
        if (hull[i].x != hull[i+1].x) ans++;
    }
    printf("%d\n",ans);

    return 0;
}