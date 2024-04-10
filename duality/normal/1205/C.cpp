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

int grid1[50][50],grid2[50][50];
int main() {
    int n;
    cin >> n;

    int i,j;
    grid1[0][0] = 1,grid1[n-1][n-1] = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (!((i+j) & 1)) {
                if ((i == 0) && (j == 0)) continue;
                else if ((i == n-1) && (j == n-1)) continue;
                if (i == 0) {
                    int r;
                    cout << "? " << j-1 << " " << 1 << " " << j+1 << " " << 1 << endl;
                    cin >> r;
                    grid1[i][j] = grid1[i][j-2]^r^1;
                }
                else if (j == 0) {
                    int r;
                    cout << "? " << 1 << " " << i-1 << " " << 1 << " " << i+1 << endl;
                    cin >> r;
                    grid1[i][j] = grid1[i-2][j]^r^1;
                }
                else {
                    int r;
                    cout << "? " << j << " " << i << " " << j+1 << " " << i+1 << endl;
                    cin >> r;
                    grid1[i][j] = grid1[i-1][j-1]^r^1;
                }
            }
            else grid1[i][j] = -1;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) grid2[i][j] = grid1[i][j];
    }
    int r;
    grid1[0][1] = 0,grid2[0][1] = 1;
    cout << "? 2 1 2 3" << endl;
    cin >> r;
    grid1[2][1] = grid1[0][1]^r^1,grid2[2][1] = grid2[0][1]^r^1;
    cout << "? 1 2 2 3" << endl;
    cin >> r;
    grid1[1][0] = grid1[2][1]^r^1,grid2[1][0] = grid2[2][1]^r^1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if ((i+j) & 1) {
                if (grid1[i][j] != -1) continue;
                if (i == 0) {
                    int r;
                    cout << "? " << j-1 << " " << 1 << " " << j+1 << " " << 1 << endl;
                    cin >> r;
                    grid1[i][j] = grid1[i][j-2]^r^1,grid2[i][j] = grid2[i][j-2]^r^1;
                }
                else if (j == 0) {
                    int r;
                    cout << "? " << 1 << " " << i-1 << " " << 1 << " " << i+1 << endl;
                    cin >> r;
                    grid1[i][j] = grid1[i-2][j]^r^1,grid2[i][j] = grid2[i-2][j]^r^1;
                }
                else {
                    int r;
                    cout << "? " << j << " " << i << " " << j+1 << " " << i+1 << endl;
                    cin >> r;
                    grid1[i][j] = grid1[i-1][j-1]^r^1,grid2[i][j] = grid2[i-1][j-1]^r^1;
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if ((i+1 < n) && (j+2 < n)) {
                int a = (grid1[i][j] == grid1[i+1][j+2]) && ((grid1[i+1][j] == grid1[i+1][j+1]) \
                    || (grid1[i][j+1] == grid1[i+1][j+1]) || (grid1[i][j+1] == grid1[i][j+2]));
                int b = (grid2[i][j] == grid2[i+1][j+2]) && ((grid2[i+1][j] == grid2[i+1][j+1]) \
                    || (grid2[i][j+1] == grid2[i+1][j+1]) || (grid2[i][j+1] == grid2[i][j+2]));
                if (a != b) {
                    int r;
                    cout << "? " << j+1 << " " << i+1 << " " << j+3 << " " << i+2 << endl;
                    cin >> r;
                    if (r == a) {
                        cout << "!" << endl;
                        for (j = 0; j < n; j++) {
                            for (i = 0; i < n; i++) cout << grid1[i][j];
                            cout << endl;
                        }
                        return 0;
                    }
                    else {
                        cout << "!" << endl;
                        for (j = 0; j < n; j++) {
                            for (i = 0; i < n; i++) cout << grid2[i][j];
                            cout << endl;
                        }
                        return 0;
                    }
                }
            }
            if ((i+2 < n) && (j+1 < n)) {
                int a = (grid1[i][j] == grid1[i+2][j+1]) && ((grid1[i][j+1] == grid1[i+1][j+1]) \
                    || (grid1[i+1][j] == grid1[i+1][j+1]) || (grid1[i+1][j] == grid1[i+2][j]));
                int b = (grid2[i][j] == grid2[i+2][j+1]) && ((grid2[i][j+1] == grid2[i+1][j+1]) \
                    || (grid2[i+1][j] == grid2[i+1][j+1]) || (grid2[i+1][j] == grid2[i+2][j]));
                if (a != b) {
                    int r;
                    cout << "? " << j+1 << " " << i+1 << " " << j+2 << " " << i+3 << endl;
                    cin >> r;
                    if (r == a) {
                        cout << "!" << endl;
                        for (j = 0; j < n; j++) {
                            for (i = 0; i < n; i++) cout << grid1[i][j];
                            cout << endl;
                        }
                        return 0;
                    }
                    else {
                        cout << "!" << endl;
                        for (j = 0; j < n; j++) {
                            for (i = 0; i < n; i++) cout << grid2[i][j];
                            cout << endl;
                        }
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}