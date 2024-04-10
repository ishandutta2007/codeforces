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

int a[300000];
int sparse[300000][19],logg[300001];
int query(int s,int e) {
    int l = logg[e-s+1];
    return min(sparse[s][l],sparse[e-(1 << l)+1][l]);
}
int good[300001];
int seen[300001];
int main() {
    int i,j;
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (i = 0; i < n; i++) scanf("%d",&a[i]);

        for (i = 0; i < n; i++) sparse[i][0] = a[i];
        for (i = 1; (1 << i) <= n; i++) {
            for (j = 0; j <= n-(1 << i); j++) sparse[j][i] = min(sparse[j][i-1],sparse[j+(1 << (i-1))][i-1]);
        }
        for (i = 2; i <= n; i++) logg[i] = logg[i/2]+1;
        int l = 0,r = n-1;
        fill(good,good+n+1,0);
        for (i = 1; i <= n; i++) {
            int q = query(l,r);
            if (q > i) break;
            else if (q == i) {
                good[i] = 1;
                if (a[l] == i) {
                    q = query(l+1,r);
                    if (q == i) break;
                    else l++;
                }
                else if (a[r] == i) {
                    q = query(l,r-1);
                    if (q == i) break;
                    else r--;
                }
                else break;
            }
        }
        fill(seen,seen+n+1,0);
        for (i = 0; i < n; i++) seen[a[i]] = 1;
        for (i = 1; i <= n; i++) {
            if (!seen[i]) break;
        }
        if (i > n) good[n] = 1;
        for (i = n; i >= 1; i--) printf("%d",good[i]);
        printf("\n");
    }

    return 0;
}