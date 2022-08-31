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

int yes[504][504],yes2[504][504];
vpii adj(int x,int y) {
    vpii v;
    if (x+1 < 504) v.pb(mp(x+1,y));
    if (x > 0) v.pb(mp(x-1,y));
    if ((x & 1) && (y+1 < 504)) v.pb(mp(x-1,y+1));
    else if (!(x & 1) && (y > 0)) v.pb(mp(x+1,y-1));
    return v;
}
vpii adjList[504][504];
queue<pii> Q;
int visited[504][504],e,nn,p,b;
int doDFS(int x,int y) {
    int i,c = 0;
    visited[x][y] = 1,nn++;
    for (i = 0; i < adjList[x][y].size(); i++) {
        int xx = adjList[x][y][i].first,yy = adjList[x][y][i].second;
        c += yes[xx][yy] != yes[x][y];
        if (!visited[xx][yy]) p += yes[xx][yy] != yes[x][y];
        if (yes2[xx][yy]) {
            e++;
            if (!visited[xx][yy]) doDFS(xx,yy);
        }
    }
    if (c < 3) b = 0;
    return 0;
}
int main() {
    int i;
    int n,x,y;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d %d",&x,&y),x += 2,y++,yes[x][y] = yes2[x][y] = 1;

    int j;
    for (i = 0; i < 504; i++) {
        for (j = 0; j < 504; j++) {
            if (yes[i][j]) Q.push(mp(i,j));
            adjList[i][j] = adj(i,j);
        }
    }
    while (!Q.empty()) {
        x = Q.front().first,y = Q.front().second;
        Q.pop();

        for (i = 0; i < adjList[x][y].size(); i++) {
            int xx = adjList[x][y][i].first,yy = adjList[x][y][i].second;
            if (yes2[xx][yy]) continue;
            int c = 0;
            for (j = 0; j < adjList[xx][yy].size(); j++) {
                if (yes2[adjList[xx][yy][j].first][adjList[xx][yy][j].second]) c++;
            }
            if (c >= 2) yes2[xx][yy] = 1,Q.push(mp(xx,yy));
        }
    }
    int ans = 0;
    for (i = 0; i < 504; i++) {
        for (j = 0; j < 504; j++) {
            if (yes2[i][j] && !visited[i][j]) {
                e = nn = p = 0,b = 1,doDFS(i,j);
                if (e/2 > nn-1) {
                    printf("SICK\n");
                    return 0;
                }
                ans += p-2;
                if (b && (nn > 1)) ans -= 2;
            }
        }
    }
    printf("RECOVERED\n%d\n",ans);

    return 0;
}