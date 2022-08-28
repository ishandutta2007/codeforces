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

char A[100001],B[100001];
int adj[20],dp[1 << 20],v[20];
int doDFS(int u) {
    if (v[u]) return 0;
    int i;
    v[u] = 1;
    for (i = 0; i < 20; i++) {
        if ((adj[u] & (1 << i)) || (adj[i] & (1 << u))) doDFS(i);
    }
    return 0;
}
int main() {
    int i,j;
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %s %s",&n,A,B);

        for (i = 0; i < 20; i++) adj[i] = v[i] = 0;
        for (i = 0; i < n; i++) {
            if (A[i] != B[i]) adj[A[i]-'a'] |= (1 << (B[i]-'a'));
        }
        n = 20;
        for (i = 0; i < (1 << n); i++) dp[i] = 0;
        for (i = 0; i < (1 << n); i++) {
            for (j = 0; j < n; j++) {
                if (!(i & (1 << j))) dp[i|(1 << j)] = max(dp[i|(1 << j)],dp[i]+((adj[j] & i) == adj[j]));
            }
        }
        int c = 0;
        for (i = 0; i < 20; i++) {
            if (!v[i]) c++,doDFS(i);
        }
        printf("%d\n",2*n-dp[(1 << n)-1]-c);
    }

    return 0;
}