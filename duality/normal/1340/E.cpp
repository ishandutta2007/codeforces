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

vi adjList[5000];
int dist[5000][5000];
queue<int> Q;
int sq(int n) {
    return n*n;
}
pii d(int a,int b,int c) {
    return mp(dist[a][b]+dist[b][c]+dist[c][a],-(sq(dist[a][b])+sq(dist[b][c])+sq(dist[c][a])));
}
int main() {
    int i;
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }

    int j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) dist[i][j] = -1;
        dist[i][i] = 0,Q.push(i);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();

            for (j = 0; j < adjList[u].size(); j++) {
                int v = adjList[u][j];
                if (dist[i][v] == -1) {
                    dist[i][v] = dist[i][u]+1;
                    Q.push(v);
                }
            }
        }
    }
    int a = 0,b = 1,c = 2;
    for (i = 0; i < 1e6/n; i++) {
        int aa = rand() % n,bb = rand() % n,cc = rand() % n;
        while (1) {
            int f = 0;
            for (j = 0; j < adjList[aa].size(); j++) {
                int v = adjList[aa][j];
                if (d(aa,bb,cc) < d(v,bb,cc)) {
                    aa = v,f = 1;
                    break;
                }
            }
            for (j = 0; j < adjList[bb].size(); j++) {
                int v = adjList[bb][j];
                if (d(aa,bb,cc) < d(aa,v,cc)) {
                    bb = v,f = 1;
                    break;
                }
            }
            for (j = 0; j < adjList[cc].size(); j++) {
                int v = adjList[cc][j];
                if (d(aa,bb,cc) < d(aa,bb,v)) {
                    cc = v,f = 1;
                    break;
                }
            }
            if (!f) break;
        }
        if (d(a,b,c) < d(aa,bb,cc)) a = aa,b = bb,c = cc;
    }
    int k,l;
    cout << a+1 << " " << b+1 << " " << c+1 << endl;
    cin >> u,u--;
    for (i = 0; i < n; i++) adjList[i].pb(i);
    while (1) {
        int na = a,nb = b,nc = c,z = 1e9;
        for (i = 0; i < adjList[a].size(); i++) {
            for (j = 0; j < adjList[b].size(); j++) {
                for (k = 0; k < adjList[c].size(); k++) {
                    int aa = adjList[a][i],bb = adjList[b][j],cc = adjList[c][k];
                    int m = 0;
                    for (l = 0; l < adjList[u].size(); l++) {
                        int v = adjList[u][l];
                        m = max(m,dist[v][aa]+dist[v][bb]+dist[v][cc]);
                    }
                    if (m < z) na = aa,nb = bb,nc = cc,z = m;
                }
            }
        }
        a = na,b = nb,c = nc;
        cout << a+1 << " " << b+1 << " " << c+1 << endl;
        if ((a == u) || (b == u) || (c == u)) break;
        else {
            cin >> u,u--;
            if ((a == u) || (b == u) || (c == u)) break;
        }
    }

    return 0;
}