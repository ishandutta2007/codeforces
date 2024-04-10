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

char d[200000];
int ans[200000];
int main() {
    int i,j;
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (i = 0; i < n; i++) scanf(" %c",&d[i]);

        for (i = 0; i <= 9; i++) {
            int p1 = -1,p2 = -1;
            vi a,b,v;
            for (j = 0; j < n; j++) {
                if (d[j]-'0' < i) {
                    if (d[j]-'0' < p1) break;
                    else p1 = d[j]-'0';
                    a.pb(j);
                    ans[j] = 1;
                }
                else if (d[j]-'0' > i) {
                    if (d[j]-'0' < p2) break;
                    else p2 = d[j]-'0';
                    b.pb(j);
                    ans[j] = 2;
                }
                else v.pb(j);
            }
            if (j == n) {
                for (j = 0; j < v.size(); j++) {
                    int x = a.empty() || (v[j] > a.back());
                    int y = b.empty() || (v[j] < b[0]);
                    if (!x && !y) break;
                    else if (x) ans[v[j]] = 1;
                    else ans[v[j]] = 2;
                }
                if (j == v.size()) {
                    for (j = 0; j < n; j++) printf("%d",ans[j]);
                    printf("\n");
                    break;
                }
            }
        }
        if (i >= 10) printf("-\n");
    }

    return 0;
}