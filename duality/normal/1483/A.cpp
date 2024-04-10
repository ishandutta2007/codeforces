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

vi a[100000];
int ans[100000],occ[100001];
int main() {
    int i,j;
    int t,n,m,k;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&m);
        for (i = 0; i < m; i++) {
            scanf("%d",&k);
            a[i].resize(k);
            for (j = 0; j < k; j++) scanf("%d",&a[i][j]);
        }

        for (i = 0; i < m; i++) {
            ans[i] = a[i][0];
            occ[ans[i]]++;
        }
        for (i = 1; i <= n; i++) {
            if (occ[i] > (m+1)/2) break;
        }
        if (i <= n) {
            int c = i;
            for (i = 0; i < m; i++) {
                if ((ans[i] == c) && (occ[c] > (m+1)/2)) {
                    if (a[i].size() >= 2) {
                        occ[ans[i]]--;
                        ans[i] = a[i][1];
                        occ[ans[i]]++;
                    }
                }
            }
            if (occ[c] <= (m+1)/2) {
                printf("YES\n");
                for (i = 0; i < m; i++) printf("%d ",ans[i]);
                printf("\n");
            }
            else printf("NO\n");
        }
        else {
            printf("YES\n");
            for (i = 0; i < m; i++) printf("%d ",ans[i]);
            printf("\n");
        }

        fill(occ,occ+n+1,0);
    }

    return 0;
}