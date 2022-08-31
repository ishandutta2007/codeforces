#define DEBUG 1

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

int a[5000];
int yes[20000];
int ways(int n) {
    int i,j,c = 0;
    memset(yes,0,sizeof(yes));
    for (i = 0; i < n; i++) yes[a[i]] = 1;
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (yes[a[i]+a[j]]) c++;
        }
    }
    return c;
}
int main() {
    int n,m;
    cin >> n >> m;
    if (n <= 2) {
        if (m == 0) {
            if (n == 1) printf("1\n");
            else printf("1 2\n");
        }
        else printf("-1\n");
        return 0;
    }

    int i;
    int mm = 0;
    for (i = 0; i < n; i++) mm += i/2;
    if (m > mm) {
        printf("-1\n");
        return 0;
    }

    int l = 0,r = n*(n-2);
    while (l < r) {
        int mid = (l+r) / 2;

        for (i = 0; i < n; i++) {
            a[i] = n+i-1;
            a[i] -= (mid+n-i-1)/n;
        }
        int x = ways(n);
        if (x >= m) r = mid;
        else l = mid+1;
    }
    for (i = 0; i < n; i++) {
        a[i] = n+i-1;
        a[i] -= (l+n-i-1)/n;
        printf("%d ",a[i]);
    }
    assert(ways(n) == m);
    printf("\n");

    return 0;
}