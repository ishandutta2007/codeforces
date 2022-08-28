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

char s[500001];
int x[300000],y[300000];
int main() {
    int i,j;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        scanf("%s",s);
        for (j = 0; s[j] != '\0'; j++) {
            if (s[j] == 'B') x[i]++;
            else y[i]++;
        }
    }

    int l = 0,r = 5e5;
    while (l < r) {
        int m = (l+r) / 2;

        int lx = 0,rx = 1e9,ly = 0,ry = 1e9;
        int lxy = -1e9,rxy = 1e9;
        for (i = 0; i < n; i++) {
            lx = max(lx,x[i]-m),rx = min(rx,x[i]+m);
            ly = max(ly,y[i]-m),ry = min(ry,y[i]+m);
            lxy = max(lxy,y[i]-x[i]-m),rxy = min(rxy,y[i]-x[i]+m);
        }
        int no = 0;
        if (lx > rx) no = 1;
        if (ly > ry) no = 1;
        if (lxy > rxy) no = 1;
        if (ly-rx > rxy) no = 1;
        if (ry-lx < lxy) no = 1;
        if ((lx == 0) && (ly == 0) && (lxy <= 0) && (rxy >= 0)) {
            debug m,lx,ly,rx,ry,lxy,rxy,"---";
            if ((rx == 0) && (ry == 0)) no = 1;
            if ((rx == 0) && (rxy <= 0)) no = 1;
            if ((ry == 0) && (lxy >= 0)) no = 1;
        }
        if (no) l = m+1;
        else r = m;
    }
    printf("%d\n",l);
    int m = l;
    int lx = 0,rx = 1e9,ly = 0,ry = 1e9;
    int lxy = -1e9,rxy = 1e9;
    for (i = 0; i < n; i++) {
        lx = max(lx,x[i]-m),rx = min(rx,x[i]+m);
        ly = max(ly,y[i]-m),ry = min(ry,y[i]+m);
        lxy = max(lxy,y[i]-x[i]-m),rxy = min(rxy,y[i]-x[i]+m);
    }
    int x,y;
    for (x = lx; x <= rx; x++) {
        int l = ly,r = ry;
        l = max(l,x+lxy),r = min(r,x+rxy);
        if ((l <= r) && ((x > 0) || (r > 0))) {
            y = r;
            break;
        }
    }
    while (x--) printf("B");
    while (y--) printf("N");
    printf("\n");

    return 0;
}