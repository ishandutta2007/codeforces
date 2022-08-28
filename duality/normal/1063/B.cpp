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

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
char grid[2000][2000];
int dist[2000][2000];
priority_queue<pair<int,pii> > H;
int main() {
    int i,j;
    int n,m,r,c,x,y;
    scanf("%d %d",&n,&m);
    scanf("%d %d %d %d",&r,&c,&x,&y);
    r--,c--;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) scanf(" %c",&grid[i][j]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) dist[i][j] = -1;
    }
    dist[r][c] = 0,H.push(mp(0,mp(r,c)));
    while (!H.empty()) {
        int r = H.top().second.first;
        int c = H.top().second.second;
        int d = -H.top().first;
        H.pop();

        for (i = 0; i < 4; i++) {
            int rr = r+dx[i],cc = c+dy[i];
            int w = (i == 1);
            if ((rr >= 0) && (rr < n) && (cc >= 0) && (cc < m) && (grid[rr][cc] == '.')\
                && ((dist[rr][cc] == -1) || (d+w < dist[rr][cc]))) {

                dist[rr][cc] = d+w;
                H.push(mp(-dist[rr][cc],mp(rr,cc)));
            }
        }
    }
    int ans = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if ((dist[i][j] != -1) && (dist[i][j] <= x) && (dist[i][j]+j-c <= y)) ans++;
        }
    }
    printf("%d\n",ans);

    return 0;
}