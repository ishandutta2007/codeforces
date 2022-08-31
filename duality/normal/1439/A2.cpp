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

int grid[100][100];
struct op { int x,y,d; };
vector<op> sol;
int doOp(int x,int y,int d) {
    sol.pb((op){x,y,d});
    if (d == 1) grid[x][y] ^= 1,grid[x+1][y] ^= 1,grid[x+1][y+1] ^= 1;
    else if (d == 2) grid[x][y] ^= 1,grid[x][y+1] ^= 1,grid[x+1][y+1] ^= 1;
    else if (d == 3) grid[x][y] ^= 1,grid[x][y+1] ^= 1,grid[x+1][y] ^= 1;
    else if (d == 4) grid[x+1][y] ^= 1,grid[x][y+1] ^= 1,grid[x+1][y+1] ^= 1;
    return 0;
}
int main() {
    int i,j;
    int t,n,m;
    char c;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&m);
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) scanf(" %c",&c),grid[i][j] = (c == '1');
        }

        for (i = 0; i < n-2; i++) {
            for (j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    if (j == m-1) doOp(i,j-1,4);
                    else doOp(i,j,1);
                }
            }
        }
        for (i = 0; i < m-2; i++) {
            if (grid[n-2][i] == 1) doOp(n-2,i,2);
            if (grid[n-1][i] == 1) doOp(n-2,i,4);
        }
        int M = 0;
        M |= grid[n-2][m-2];
        M |= grid[n-2][m-1] << 1;
        M |= grid[n-1][m-2] << 2;
        M |= grid[n-1][m-1] << 3;
        int x[4] = {13,11,7,14};
        for (i = 0; i < 16; i++) {
            int c = 0;
            for (j = 0; j < 4; j++) {
                if (i & (1 << j)) c ^= x[j];
            }
            if (c == M) {
                for (j = 0; j < 4; j++) {
                    if (i & (1 << j)) doOp(n-2,m-2,j+1);
                }
                break;
            }
        }
        printf("%d\n",sol.size());
        for (i = 0; i < sol.size(); i++) {
            int x = sol[i].x+1,y = sol[i].y+1;
            if (sol[i].d == 1) printf("%d %d %d %d %d %d\n",x,y,x+1,y,x+1,y+1);
            if (sol[i].d == 2) printf("%d %d %d %d %d %d\n",x,y,x,y+1,x+1,y+1);
            if (sol[i].d == 3) printf("%d %d %d %d %d %d\n",x,y,x,y+1,x+1,y);
            if (sol[i].d == 4) printf("%d %d %d %d %d %d\n",x+1,y,x,y+1,x+1,y+1);
        }
        sol.clear();
    }

    return 0;
}