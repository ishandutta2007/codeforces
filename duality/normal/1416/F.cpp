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
int arr[100000];
struct edge { int v,c,r; };
vector<edge> adjList[200002];
int nn[100000],in[100000];
int addEdge(int u,int v,int c) {
    adjList[u].pb((edge){v,c,adjList[v].size()});
    adjList[v].pb((edge){u,0,adjList[u].size()-1});
    return 0;
}
int dist[200002];
queue<int> Q;
int doBFS(int N) {
    int i;
    for (i = 0; i < N; i++) dist[i] = -1;
    dist[0] = 0,Q.push(0);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i].v;
            if ((adjList[u][i].c > 0) && (dist[v] == -1)) {
                dist[v] = dist[u]+1;
                Q.push(v);
            }
        }
    }
    return (dist[1] != -1);
}
int work[200002];
int doDFS(int u,int f) {
    if (u == 1) return f;
    int &i = work[u];
    for (; i < adjList[u].size(); i++) {
        int v = adjList[u][i].v;
        if ((adjList[u][i].c > 0) && (dist[v] == dist[u]+1)) {
            int df = doDFS(v,min(f,adjList[u][i].c));
            if (df > 0) {
                adjList[u][i].c -= df;
                adjList[v][adjList[u][i].r].c += df;
                return df;
            }
        }
    }
    return 0;
}
char ans[100000];
int ans2[100000];
int main() {
    int i,j,k;
    int T,n,m;
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d",&n,&m);
        for (i = 0; i < n*m; i++) scanf("%d",&arr[i]);

        int c = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                for (k = 0; k < 4; k++) {
                    int x = i+dx[k],y = j+dy[k];
                    if ((x >= 0) && (x < n) && (y >= 0) && (y < m) && (arr[x*m+y] < arr[i*m+j])) break;
                }
                if (k == 4) {
                    addEdge(0,i*m+j+2,1);
                    for (k = 0; k < 4; k++) {
                        int x = i+dx[k],y = j+dy[k];
                        if ((x >= 0) && (x < n) && (y >= 0) && (y < m) && (arr[x*m+y] == arr[i*m+j]))
                            addEdge(i*m+j+2,x*m+y+n*m+2,1);
                    }
                    c++;
                }
                addEdge(i*m+j+n*m+2,1,1);
            }
        }
        int mf = 0,f;
        while (doBFS(2*n*m+2)) {
            while (!Q.empty()) Q.pop();
            while ((f=doDFS(0,1e9)) > 0) mf += f;
            fill(work,work+2*n*m+2,0);
        }
        if (mf != c) printf("NO\n");
        else {
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    for (k = 0; k < 4; k++) {
                        int x = i+dx[k],y = j+dy[k];
                        if ((x >= 0) && (x < n) && (y >= 0) && (y < m) && (arr[x*m+y] < arr[i*m+j])) {
                            nn[i*m+j] = x*m+y;
                            break;
                        }
                    }
                    if (k == 4) {
                        for (k = 0; k < adjList[i*m+j+2].size(); k++) {
                            edge e = adjList[i*m+j+2][k];
                            if ((e.v >= n*m+2) && (e.c == 0)) nn[i*m+j] = e.v-n*m-2;
                        }
                    }
                }
            }
            for (i = 0; i < n*m; i++) in[nn[i]]++;
            for (i = 0; i < n*m; i++) {
                if (in[i] == 0) Q.push(i);
            }
            while (!Q.empty()) {
                int u = Q.front();
                Q.pop();

                if (arr[nn[u]] == arr[u]) {
                    in[nn[nn[u]]]--;
                    if (in[nn[nn[u]]] == 0) Q.push(nn[nn[u]]);
                    nn[nn[u]] = u;
                }
                else {
                    in[nn[u]]--;
                    if (in[nn[u]] == 0) Q.push(nn[u]);
                }
            }
            for (i = 0; i < n*m; i++) in[i] = 0;
            for (i = 0; i < n*m; i++) in[nn[i]]++;
            for (i = 0; i < n*m; i++) {
                if (in[i] == 0) Q.push(i);
            }
            while (!Q.empty()) {
                int u = Q.front();
                Q.pop();

                in[nn[u]]--;
                if (in[nn[u]] == 0) Q.push(nn[u]);
            }
            for (i = 0; i < n*m; i++) {
                if (in[i] > 0) {
                    int u = i;
                    do {
                        in[u] = in[nn[u]] = 0;
                        int t = nn[nn[u]];
                        nn[nn[u]] = u,u = t;
                    } while (u != i);
                }
            }
            printf("YES\n");
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    int x = nn[i*m+j]/m,y = nn[i*m+j] % m;
                    if (x == i-1) ans[i*m+j] = 'U';
                    else if (x == i+1) ans[i*m+j] = 'D';
                    else if (y == j-1) ans[i*m+j] = 'L';
                    else ans[i*m+j] = 'R';
                    ans2[i*m+j] = -1;
                }
            }
            for (i = 0; i < n; i++) {
                for (j = 0; j < m-1; j++) {
                    if ((ans[i*m+j] == 'R') && (ans[i*m+j+1] == 'L')) {
                        ans2[i*m+j] = arr[i*m+j]/2;
                        ans2[i*m+j+1] = (arr[i*m+j]+1)/2;
                        Q.push(i*m+j),Q.push(i*m+j+1);
                    }
                }
            }
            for (i = 0; i < n-1; i++) {
                for (j = 0; j < m; j++) {
                    if ((ans[i*m+j] == 'D') && (ans[(i+1)*m+j] == 'U')) {
                        ans2[i*m+j] = arr[i*m+j]/2;
                        ans2[(i+1)*m+j] = (arr[i*m+j]+1)/2;
                        Q.push(i*m+j),Q.push((i+1)*m+j);
                    }
                }
            }
            while (!Q.empty()) {
                int i = Q.front() / m,j = Q.front() % m;
                Q.pop();

                for (k = 0; k < 4; k++) {
                    int x = i+dx[k],y = j+dy[k];
                    if ((x >= 0) && (x < n) && (y >= 0) && (y < m) && (arr[x*m+y] > arr[i*m+j]) && (nn[x*m+y] == i*m+j)) {
                        if (ans2[x*m+y] == -1) {
                            ans2[x*m+y] = arr[x*m+y]-arr[i*m+j];
                            Q.push(x*m+y);
                        }
                    }
                }
            }
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) printf("%d ",ans2[i*m+j]);
                printf("\n");
            }
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) printf("%c ",ans[i*m+j]);
                printf("\n");
            }
        }

        for (i = 0; i < 2*n*m+2; i++) adjList[i].clear();
    }

    return 0;
}