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

int dx[4] = {-1,0,1,0},dy[4] = {0,-1,0,1};
char grid[1000][1000];
int dist[1000][1000];
queue<pii> Q;
int main() {
    int i,j;
    int n,m,t;
    scanf("%d %d %d",&n,&m,&t);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) scanf(" %c",&grid[i][j]);
    }

    for (i = 0; i < n; i++) fill(dist[i],dist[i]+m,-1);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if ((i > 0) && (grid[i][j] == grid[i-1][j])) dist[i][j] = dist[i-1][j] = 0;
            if ((j > 0) && (grid[i][j] == grid[i][j-1])) dist[i][j] = dist[i][j-1] = 0;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (dist[i][j] == 0) Q.push(mp(i,j));
        }
    }
    while (!Q.empty()) {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();

        for (i = 0; i < 4; i++) {
            int xx = x+dx[i],yy = y+dy[i];
            if ((xx >= 0) && (xx < m) && (yy >= 0) && (yy < n) && (dist[yy][xx] == -1)) {
                dist[yy][xx] = dist[y][x]+1;
                Q.push(mp(yy,xx));
            }
        }
    }

    int x,y;
    LLI p;
    for (i = 0; i < t; i++) {
        scanf("%d %d %I64d",&y,&x,&p);
        x--,y--;
        if (dist[y][x] == -1) printf("%c\n",grid[y][x]);
        else if (p <= dist[y][x]) printf("%c\n",grid[y][x]);
        else printf("%c\n",grid[y][x]^(dist[y][x] & 1)^(p & 1));
    }

    return 0;
}