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

int x[2500],y[2500];
vpii v;
int quad(pii p) {
    if ((p.x > 0) && (p.y > 0)) return 0;
    else if ((p.x == 0) && (p.y > 0)) return 1;
    else if ((p.x < 0) && (p.y > 0)) return 2;
    else if ((p.x < 0) && (p.y == 0)) return 3;
    else if ((p.x < 0) && (p.y < 0)) return 4;
    else if ((p.x == 0) && (p.y < 0)) return 5;
    else if ((p.x > 0) && (p.y < 0)) return 6;
    else if ((p.x > 0) && (p.y == 0)) return 7;
    else return 8;
}
LLI cross(pii a,pii b) {
    return (LLI) a.x*b.y-(LLI) a.y*b.x;
}
bool comp(pii a,pii b) {
    if (quad(a) != quad(b)) return quad(a) < quad(b);
    else return cross(a,b) > 0;
}
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d %d",&x[i],&y[i]);

    int j;
    LLI ans = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j != i) v.pb(mp(x[j]-x[i],y[j]-y[i]));
        }
        sort(v.begin(),v.end(),comp);
        int k = 0;
        for (j = 0; j < v.size(); j++) {
            if (k == j) {
                k++;
                if (k == v.size()) k = 0;
            }
            while (cross(v[j],v[k]) > 0) {
                k++;
                if (k == v.size()) k = 0;
            }
            int c = (k-j+v.size()-1) % v.size();
            ans += (LLI) c*(c-1)*(c-2)/6;
        }
        v.clear();
    }
    ans = (LLI) n*(n-1)*(n-2)*(n-3)*(n-4)/24-ans;
    printf("%I64d\n",ans);

    return 0;
}