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

pii p[4],p2[4];
int l,r,u,d;
int ld,rd,ud,dd;
int check(int x,int y) {
    if ((x < l) || (x > r) || (y < d) || (y > u)) return 0;
    if ((x-y < ld) || (x-y > rd) || (x+y < dd) || (x+y > ud)) return 0;
    return 1;
}
int main() {
    int i;
    l = d = ld = dd = 10000,r = u = rd = ud = -10000;
    for (i = 0; i < 4; i++) {
        scanf("%d %d",&p[i].x,&p[i].y);
        p[i].x *= 2,p[i].y *= 2;
        l = min(l,p[i].x),r = max(r,p[i].x);
        d = min(d,p[i].y),u = max(u,p[i].y);
    }
    for (i = 0; i < 4; i++) {
        scanf("%d %d",&p2[i].x,&p2[i].y);
        p2[i].x *= 2,p2[i].y *= 2;
        ld = min(ld,p2[i].x-p2[i].y),rd = max(rd,p2[i].x-p2[i].y);
        dd = min(dd,p2[i].x+p2[i].y),ud = max(ud,p2[i].x+p2[i].y);
    }

    for (i = 0; i < 4; i++) {
        if (check(p[i].x,p[i].y)) {
            printf("YES\n");
            return 0;
        }
        if (check(p2[i].x,p2[i].y)) {
            printf("YES\n");
            return 0;
        }
    }
    if (check((l+r)/2,(u+d)/2)) printf("YES\n");
    else printf("NO\n");

    return 0;
}