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
int sparse[300000][20];
int query(int s,int e) {
    int l = log2(e-s+1);
    return min(sparse[s][l],sparse[e-(1 << l)+1][l]);
}
int pos[300000],ans[300000];
int main() {
    int i,j;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),a[i+n] = a[i+2*n] = a[i];
    for (i = 0; i < 3*n; i++) sparse[i][0] = a[i];
    for (i = 1; (1 << i) <= 3*n; i++) {
        for (j = 0; j <= (3*n-(1 << i)); j++) sparse[j][i] = min(sparse[j][i-1],sparse[j+(1 << (i-1))][i-1]);
    }

    for (i = 3*n-1; i >= 0; i--) {
        int l = i+1,r = 3*n;
        while (l < r) {
            int m = (l+r) / 2;
            if (2*query(i+1,m) < a[i]) r = m;
            else l = m+1;
        }
        pos[i] = l;
    }
    int p = 3*n;
    for (i = 3*n-1; i >= 0; i--) {
        p = min(p,pos[i]);
        ans[i] = p;
    }
    for (i = 0; i < n; i++) {
        if (ans[i]-i > 2*n) printf("-1 ");
        else printf("%d ",ans[i]-i);
    }
    printf("\n");

    return 0;
}