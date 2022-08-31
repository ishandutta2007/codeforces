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

int n,m;
char grid[1000][1000];
int visited[1000][1000];
int doDFS(int x,int y) {
    if ((x < 0) || (x >= m) || (y < 0) || (y >= n)) return 0;
    else if (visited[y][x] || (grid[y][x] == '.')) return 0;
    visited[y][x] = 1;
    doDFS(x-1,y),doDFS(x,y-1),doDFS(x+1,y),doDFS(x,y+1);
    return 0;
}
int main() {
    int i,j;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) scanf(" %c",&grid[i][j]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (grid[i][j] == '#') break;
        }
        if (j == m) break;
    }
    if (i == n) {
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (grid[j][i] == '#') break;
            }
            if (j == n) {
                printf("-1\n");
                return 0;
            }
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (grid[j][i] == '#') break;
        }
        if (j == n) break;
    }
    if (i == m) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (grid[i][j] == '#') break;
            }
            if (j == m) {
                printf("-1\n");
                return 0;
            }
        }
    }

    for (i = 0; i < n; i++) {
        int f = 0;
        for (j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                if (f == 0) f = 1;
                else if (f == 2) break;
            }
            if (grid[i][j] == '.') {
                if (f == 1) f = 2;
            }
        }
        if (j < m) {
            printf("-1\n");
            return 0;
        }
    }
    for (i = 0; i < m; i++) {
        int f = 0;
        for (j = 0; j < n; j++) {
            if (grid[j][i] == '#') {
                if (f == 0) f = 1;
                else if (f == 2) break;
            }
            if (grid[j][i] == '.') {
                if (f == 1) f = 2;
            }
        }
        if (j < n) {
            printf("-1\n");
            return 0;
        }
    }
    int c = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (!visited[i][j] && (grid[i][j] == '#')) doDFS(j,i),c++;
        }
    }
    printf("%d\n",c);

    return 0;
}