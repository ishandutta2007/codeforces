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

int c[52],d[52];
vector<vi> sol;
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&c[i]);

    int j,k;
    while (1) {
        for (i = 2; i <= n; i++) {
            int a,b;
            for (j = 0; j < n; j++) {
                if (c[j] == i-1) a = j;
                if (c[j] == i) b = j;
            }
            if (a > b) {
                vi v;
                int z = 1;
                while (c[b+z-1] == c[b+z]-1) z++;
                v.pb(b),v.pb(z),v.pb(a-b+1-z),v.pb(n-a-1);
                int x = n,y = 0;
                for (j = v.size()-1; j >= 0; j--) {
                    for (k = x-v[j]; k < x; k++) d[y++] = c[k];
                    x -= v[j];
                }
                for (j = 0; j < n; j++) c[j] = d[j];
                sol.pb(v);
                break;
            }
        }
        if (i > n) break;
    }
    for (i = 0; i < n; i++) assert(c[i] == i+1);
    printf("%d\n",sol.size());
    for (i = 0; i < sol.size(); i++) {
        int a = 0;
        for (j = 0; j < sol[i].size(); j++) a += sol[i][j] != 0;
        printf("%d",a);
        for (j = 0; j < sol[i].size(); j++) {
            if (sol[i][j] != 0) printf(" %d",sol[i][j]);
        }
        printf("\n");
    }

    return 0;
}