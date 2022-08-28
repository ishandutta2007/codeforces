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

char grid[300][300];
int main() {
    int i,j;
    int t,n;
    scanf("%d",&t);
    while (t--) {
        int c = 0;
        scanf("%d",&n);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) scanf(" %c",&grid[i][j]),c += (grid[i][j] != '.');
        }

        int x,y;
        for (x = 0; x < 3; x++) {
            for (y = 0; y < 3; y++) {
                if (x == y) continue;
                int d = 0;
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        if ((((i+j) % 3) == x) && (grid[i][j] == 'X')) d++;
                        if ((((i+j) % 3) == y) && (grid[i][j] == 'O')) d++;
                    }
                }
                if (d <= c/3) {
                    for (i = 0; i < n; i++) {
                        for (j = 0; j < n; j++) {
                            if ((((i+j) % 3) == x) && (grid[i][j] == 'X')) grid[i][j] = 'O';
                            if ((((i+j) % 3) == y) && (grid[i][j] == 'O')) grid[i][j] = 'X';
                        }
                    }
                    break;
                }
            }
            if (y < 3) break;
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) printf("%c",grid[i][j]);
            printf("\n");
        }
    }

    return 0;
}