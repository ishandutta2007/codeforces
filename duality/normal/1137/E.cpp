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

struct line { LLI m,b; };
int op[300000],b[300000],s[300000];
vector<line> hull;
int bad(line a,line b,line c) {
    long double x = (long double) (b.b-a.b)*(b.m-c.m);
    long double y = (long double) (c.b-b.b)*(a.m-b.m);
    if (x == y) return (b.b-a.b)*(b.m-c.m) <= (c.b-b.b)*(a.m-b.m);
    else return x <= y;
}
int main() {
    int i;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d",&op[i]);
        if (op[i] <= 2) scanf("%d",&b[i]);
        else scanf("%d %d",&b[i],&s[i]);
    }

    int sum = n;
    LLI bb = 0,ss = 0;
    hull.pb((line){0,0});
    for (i = 0; i < m; i++) {
        if (op[i] == 1) {
            hull.clear(),hull.pb((line){0,0});
            sum += b[i],bb = ss = 0;
        }
        else if (op[i] == 2) {
            line l = (line){sum,-(sum*ss+bb)};
            while ((hull.size() >= 2) && bad(hull[hull.size()-2],hull.back(),l)) hull.pop_back();
            hull.pb(l);
            sum += b[i];
        }
        else bb += b[i],ss += s[i];
        while ((hull.size() >= 2) && (hull.back().m*ss+bb+hull.back().b \
                >= hull[hull.size()-2].m*ss+bb+hull[hull.size()-2].b)) hull.pop_back();
        printf("%d %I64d\n",(int) hull.back().m+1,hull.back().m*ss+bb+hull.back().b);
        //for(int j=0;j<hull.size();j++)cout<<hull[j].m<<","<<hull[j].b<<" ";
        //cout<<endl;
    }

    return 0;
}