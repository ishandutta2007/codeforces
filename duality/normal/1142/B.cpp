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

int p[200000],a[200000],P[200000];
int r[200000],nxt[200000][18];
int arr[200000];
int main() {
    int i;
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    for (i = 0; i < n; i++) scanf("%d",&p[i]),p[i]--;
    for (i = 0; i < m; i++) scanf("%d",&a[i]),a[i]--;

    int j;
    for (i = 0; i < n; i++) r[i] = m,P[p[i]] = p[(i+1) % n];
    for (i = m-1; i >= 0; i--) nxt[i][0] = r[P[a[i]]],r[a[i]] = i;
    for (i = 1; (1 << i) < m; i++) {
        for (j = 0; j < m; j++) {
            if (nxt[j][i-1] != m) nxt[j][i] = nxt[nxt[j][i-1]][i-1];
            else nxt[j][i] = m;
        }
    }
    int logm = i;
    for (i = 0; i < m; i++) {
        arr[i] = i;
        for (j = logm-1; j >= 0; j--) {
            if ((n-1) & (1 << j)) arr[i] = nxt[arr[i]][j];
            if (arr[i] == m) break;
        }
    }
    for (i = m-2; i >= 0; i--) arr[i] = min(arr[i],arr[i+1]);

    int l,r;
    for (i = 0; i < q; i++) {
        scanf("%d %d",&l,&r);
        l--,r--;
        if (arr[l] <= r) printf("1");
        else printf("0");
    }
    printf("\n");

    return 0;
}