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

int w[100];
int a[1000],b[1000],ans[1000];
int deg[100][1000];
int main() {
    int i;
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for (i = 0; i < n; i++) scanf("%d",&w[i]);
    for (i = 0; i < m; i++) scanf("%d %d",&a[i],&b[i]),a[i]--,b[i]--;

    int j;
    for (i = 0; i < m; i++) {
        int x,s = 1e9;
        for (j = 0; j < k; j++) {
            if (deg[a[i]][j]+deg[b[i]][j] < s) s = deg[a[i]][j]+deg[b[i]][j],x = j;
        }
        ans[i] = x;
        deg[a[i]][x]++,deg[b[i]][x]++;
    }
    while (1) {
        for (i = 0; i < n; i++) {
            int p = deg[i][0],q = deg[i][0];
            for (j = 0; j < k; j++) p = min(p,deg[i][j]),q = max(q,deg[i][j]);
            if (q-p > 2) break;
        }
        if (i == n) break;
        for (i = 0; i < m; i++) {
            int x = ans[i],s = deg[a[i]][ans[i]]+deg[b[i]][ans[i]];
            for (j = 0; j < k; j++) {
                if (deg[a[i]][j]+deg[b[i]][j] < s) s = deg[a[i]][j]+deg[b[i]][j],x = j;
            }
            deg[a[i]][ans[i]]--,deg[b[i]][ans[i]]--;
            ans[i] = x;
            deg[a[i]][x]++,deg[b[i]][x]++;
        }
    }
    for (i = 0; i < m; i++) printf("%d\n",ans[i]+1);

    return 0;
}