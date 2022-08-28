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

int a[100000];
double p[100000],X = 0;
struct line { long double m,b; };
bool comp(line a,line b) {
    if (a.m == b.m) return a.b < b.b;
    else return a.m < b.m;
}
int bad(line a,line b,line c) {
    return (a.b-b.b)*(c.m-b.m) >= (b.b-c.b)*(b.m-a.m);
}
vector<line> lines,hull;
long double apply(line l,long double p,LLI t) {
    return (1-pow(1-l.m,t))/l.m*(X-l.b)+pow(1-l.m,t)*p;
}
int main() {
    int i;
    int n,b;
    LLI t;
    scanf("%d %I64d",&n,&t);
    for (i = 0; i < n; i++) scanf("%d %d %lf",&a[i],&b,&p[i]),X = max(X,p[i]*b);

    for (i = 0; i < n; i++) lines.pb((line){p[i],p[i]*a[i]});
    sort(lines.begin(),lines.end(),comp);
    for (i = 0; i < n; i++) {
        while (!hull.empty() && (hull.back().m == lines[i].m)) hull.pop_back();
        while ((hull.size() >= 2) && bad(hull[hull.size()-2],hull.back(),lines[i])) hull.pop_back();
        hull.pb(lines[i]);
    }
    LLI c = 0;
    long double p = 0;
    i = 0;
    while (c < t) {
        LLI l = c,r = t;
        while (l < r) {
            LLI m = (l+r) / 2;
            long double pp = apply(hull[i],p,m-c);
            if (i == hull.size()-1) l = m+1;
            else if (hull[i].m*pp+hull[i].b < hull[i+1].m*pp+hull[i+1].b) r = m;
            else l = m+1;
        }
        p = apply(hull[i],p,l-c),c = l,i++;
    }
    printf("%.13lf\n",(double) (t*X-p));

    return 0;
}