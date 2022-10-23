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

pii p[3];
int main() {
    int i;
    int t,n,x,y;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        scanf("%d %d %d %d %d %d",&p[0].x,&p[0].y,&p[1].x,&p[1].y,&p[2].x,&p[2].y);
        scanf("%d %d",&x,&y);
        if ((mp(x,y) == p[0]) || (mp(x,y) == p[1]) || (mp(x,y) == p[2])) {
            printf("YES\n");
            continue;
        }

        vi v;
        v.pb(p[0].x),v.pb(p[1].x),v.pb(p[2].x);
        sort(v.begin(),v.end());
        int cx = v[1];
        v.clear();
        v.pb(p[0].y),v.pb(p[1].y),v.pb(p[2].y);
        sort(v.begin(),v.end());
        int cy = v[1];
        if ((x == cx) || (y == cy)) printf("YES\n");
        else if (((cx == 1) || (cx == n)) && ((cy == 1) || (cy == n))) printf("NO\n");
        else if (((x & 1) != (cx & 1)) && ((y & 1) != (cy & 1))) printf("NO\n");
        else printf("YES\n");
    }
    
    return 0;
}