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


int main() {
    int n,m,x,y,vx,vy;
    cin >> n >> m >> x >> y >> vx >> vy;

    if (vx == 0) {
        if (vy == -1) {
            if (x == 0) printf("%d %d\n",0,0);
            else if (x == n) printf("%d %d\n",n,0);
            else printf("-1\n");
        }
        else if (vy == 1) {
            if (x == 0) printf("%d %d\n",0,m);
            else if (x == n) printf("%d %d\n",n,m);
            else printf("-1\n");
        }
    }
    else if (vy == 0) {
        if (vx == -1) {
            if (y == 0) printf("%d %d\n",0,0);
            else if (y == m) printf("%d %d\n",0,m);
            else printf("-1\n");
        }
        else if (vx == 1) {
            if (y == 0) printf("%d %d\n",n,0);
            else if (y == m) printf("%d %d\n",n,m);
            else printf("-1\n");
        }
    }
    else {
        int a,b;
        if ((vx == -1) && (vy == -1)) a = x,b = y;
        else if ((vx == -1) && (vy == 1)) a = x,b = m-y;
        else if ((vx == 1) && (vy == -1)) a = n-x,b = y;
        else a = n-x,b = m-y;
        LLI temp;
        LLI r = m,pr = n;
        LLI s = 0,ps = 1;
        LLI t = 1,pt = 0;
        while (r > 0) {
            LLI q = pr/r;
            temp = r,r = pr-q*r,pr = temp;
            temp = s,s = ps-q*s,ps = temp;
            temp = t,t = pt-q*t,pt = temp;
        }
        if ((abs(a-b) % pr) != 0) printf("-1\n");
        else {
            ps *= (b-a)/pr;
            pt *= (a-b)/pr;
            LLI tt = 0;
            if (ps < 0) tt = max(tt,(-ps+m/pr-1)/(m/pr));
            if (pt < 0) tt = max(tt,(-pt+n/pr-1)/(n/pr));
            ps += tt*(m/pr),pt += tt*(n/pr);
            tt = min(ps/(m/pr),pt/(n/pr));
            ps -= tt*(m/pr),pt -= tt*(n/pr);
            int xx,yy;
            if (ps & 1) xx = -1;
            else xx = 1;
            if (pt & 1) yy = -1;
            else yy = 1;
            xx *= vx,yy *= vy;
            if (xx == -1) printf("%d ",0);
            else printf("%d ",n);
            if (yy == -1) printf("%d\n",0);
            else printf("%d\n",m);
        }
    }

    return 0;
}