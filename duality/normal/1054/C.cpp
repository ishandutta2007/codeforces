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

int l[1000],r[1000],s[1000];
pii sorted[1000];
int ans[1000];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&l[i]);
    for (i = 0; i < n; i++) scanf("%d",&r[i]),s[i] = l[i]+r[i],sorted[i] = mp(s[i],i);
    sort(sorted,sorted+n,greater<pii>());

    int c = 1;
    for (i = 0; i < n; i++) {
        ans[sorted[i].second] = c;
        if ((i < n-1) && (sorted[i+1].first != sorted[i].first)) c++;
    }
    printArr(ans,n);
    int j;
    for (i = 0; i < n; i++) {
        int x = 0;
        for (j = 0; j < i; j++) {
            if (ans[j] > ans[i]) x++;
        }
        if (x != l[i]) {
            printf("NO\n");
            return 0;
        }
        x = 0;
        for (j = i+1; j < n; j++) {
            if (ans[j] > ans[i]) x++;
        }
        if (x != r[i]) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    for (i = 0; i < n; i++) printf("%d ",ans[i]);
    printf("\n");

    return 0;
}