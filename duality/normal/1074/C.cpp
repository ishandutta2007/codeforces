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

int x[300000],y[300000];
vi cand;
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d %d",&x[i],&y[i]);

    int p = 0,minx,maxx,miny,maxy;
    for (i = 0; i < n; i++) {
        if (x[i] < x[p]) p = i;
    }
    cand.pb(p),minx = x[p],p = 0;
    for (i = 0; i < n; i++) {
        if (x[i] > x[p]) p = i;
    }
    cand.pb(p),maxx = x[p],p = 0;
    for (i = 0; i < n; i++) {
        if (y[i] < y[p]) p = i;
    }
    cand.pb(p),miny = y[p],p = 0;
    for (i = 0; i < n; i++) {
        if (y[i] > y[p]) p = i;
    }
    cand.pb(p),maxy = y[p],p = 0;
    sort(cand.begin(),cand.end());
    cand.resize(unique(cand.begin(),cand.end())-cand.begin());
    if (cand.size() <= 3) {
        for (i = 3; i <= n; i++) printf("%d ",2*(maxx-minx+maxy-miny));
        printf("\n");
    }
    else {
        int j,k;
        int best = 0;
        for (i = 0; i < cand.size(); i++) {
            for (j = i+1; j < cand.size(); j++) {
                for (k = 0; k < n; k++) {
                    if ((k != cand[i]) && (k != cand[j])) {
                        int a = cand[i],b = cand[j],c = k;
                        best = max(best,2*(max(max(x[a],x[b]),x[c])-min(min(x[a],x[b]),x[c])) + \
                            2*(max(max(y[a],y[b]),y[c])-min(min(y[a],y[b]),y[c])));
                    }
                }
            }
        }
        printf("%d ",best);
        for (i = 4; i <= n; i++) printf("%d ",2*(maxx-minx+maxy-miny));
        printf("\n");
    }

    return 0;
}