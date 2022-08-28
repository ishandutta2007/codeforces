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

vi C[3000];
int S[3000];
int main() {
    int i;
    int n,m;
    int p,c;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) scanf("%d %d",&p,&c),C[p-1].pb(c);

    int j,k;
    LLI ans,best = MAX_VAL_2;
    for (i = 0; i < m; i++) sort(C[i].begin(),C[i].end());
    for (i = max((int) C[0].size(),1); i <= n; i++) {
        int v = C[0].size();
        c = 0,ans = 0;
        for (j = 1; j < m; j++) {
            k = 0;
            if (C[j].size() >= i) {
                while (C[j].size() >= k+i) ans += C[j][k],v++,k++;
            }
            while (k < C[j].size()) S[c++] = C[j][k],k++;
        }
        sort(S,S+c);
        k = 0;
        while ((k < c) && (v < i)) ans += S[k],v++,k++;
        if (v >= i) best = min(best,ans);
    }
    printf("%I64d\n",best);

    return 0;
}