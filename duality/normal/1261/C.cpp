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

char grid[1000000];
int pre[3000000];
int diff[3000000];
int main() {
    int i,j;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf(" %c",&grid[i*m+j]);
            pre[(i+1)*(m+1)+j+1] = (grid[i*m+j] == '.') + pre[(i+1)*(m+1)+j] + pre[i*(m+1)+j+1] - pre[i*(m+1)+j];
        }
    }

    int l = 0,r = (min(n,m)-1)/2;
    while (l < r) {
        int mid = (l+r+1) / 2;

        int T = mid;
        memset(diff,0,sizeof(diff));
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if ((i >= T) && (i+T < n) && (j >= T) && (j+T < m)) {
                    if (pre[(i+T+1)*(m+1)+(j+T+1)]-pre[(i-T)*(m+1)+(j+T+1)]-pre[(i+T+1)*(m+1)+j-T]+pre[(i-T)*(m+1)+j-T] == 0) {
                        diff[(i+T+1)*(m+1)+(j+T+1)]++,diff[(i-T)*(m+1)+(j+T+1)]--;
                        diff[(i+T+1)*(m+1)+j-T]--,diff[(i-T)*(m+1)+j-T]++;
                    }
                }
            }
        }
        for (i = 1; i < n; i++) {
            for (j = 0; j < m; j++) diff[i*(m+1)+j] += diff[(i-1)*(m+1)+j];
        }
        for (i = 0; i < n; i++) {
            for (j = 1; j < m; j++) diff[i*(m+1)+j] += diff[i*(m+1)+j-1];
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if ((diff[i*(m+1)+j] == 0) && (grid[i*m+j] == 'X')) break;
            }
            if (j < m) break;
        }
        if (i < n) r = mid-1;
        else l = mid;
    }
    int T = l;
    printf("%d\n",T);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if ((i >= T) && (i+T < n) && (j >= T) && (j+T < m)) {
                if (pre[(i+T+1)*(m+1)+(j+T+1)]-pre[(i-T)*(m+1)+(j+T+1)]-pre[(i+T+1)*(m+1)+j-T]+pre[(i-T)*(m+1)+j-T] == 0) printf("X");
                else printf(".");
            }
            else printf(".");
        }
        printf("\n");
    }

    return 0;
}