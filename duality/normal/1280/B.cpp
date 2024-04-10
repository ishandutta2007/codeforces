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

char grid[60][60];
int main() {
    int i,j;
    int t,r,c;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&r,&c);
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) scanf(" %c",&grid[i][j]);
        }

        int a = 1,b = 1;
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                a &= (grid[i][j] == 'A');
                b &= (grid[i][j] == 'P');
            }
        }
        if (a) printf("0\n");
        else if (b) printf("MORTAL\n");
        else {
            int no1 = 0,no2 = 0;
            for (i = 0; i < r; i++) {
                if (grid[i][0] == 'P') no1 = 1;
                if (grid[i][c-1] == 'P') no2 = 1;
            }
            if (!no1 || !no2) printf("1\n");
            else {
                no1 = 0,no2 = 0;
                for (i = 0; i < c; i++) {
                    if (grid[0][i] == 'P') no1 = 1;
                    if (grid[r-1][i] == 'P') no2 = 1;
                }
                if (!no1 || !no2) printf("1\n");
                else {
                    if ((grid[0][0] == 'A') || (grid[0][c-1] == 'A') || (grid[r-1][0] == 'A') || (grid[r-1][c-1] == 'A')) {
                        printf("2\n");
                        continue;
                    }
                    for (i = 0; i < r; i++) {
                        int f = 1;
                        for (j = 0; j < c; j++) f &= (grid[i][j] == 'A');
                        if (f) break;
                    }
                    if (i < r) {
                        printf("2\n");
                        continue;
                    }
                    for (i = 0; i < c; i++) {
                        int f = 1;
                        for (j = 0; j < r; j++) f &= (grid[j][i] == 'A');
                        if (f) break;
                    }
                    if (i < c) {
                        printf("2\n");
                        continue;
                    }
                    for (i = 0; i < r; i++) {
                        if (grid[i][0] == 'A') break;
                        if (grid[i][c-1] == 'A') break;
                    }
                    if (i < r) {
                        printf("3\n");
                        continue;
                    }
                    for (i = 0; i < c; i++) {
                        if (grid[0][i] == 'A') break;
                        if (grid[r-1][i] == 'A') break;
                    }
                    if (i < c) {
                        printf("3\n");
                        continue;
                    }
                    printf("4\n");
                }
            }
        }
    }

    return 0;
}