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

set<pii> adjList[3][100000];
vpii adjList2[200005];
queue<int> Q;
int sol[200005];
int visited[100000];
int doDFS(int u,int d) {
    if (sol[u] != -1) {
        assert(sol[u] == d);
        return 0;
    }

    sol[u] = d;
    for (pii v: adjList2[u]) doDFS(v.first,d^v.second);
    return 0;
}
int main() {
    int i;
    int n,m;
    int u,v,w;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d",&u,&v,&w);
        u--,v--;
        adjList[w][u].insert(mp(v,i+1));
        adjList[w][v].insert(mp(u,-(i+1)));
    }

    int ans = 0;
    for (i = 0; i < n; i++) {
        if (adjList[1][i].size() & 1) ans++;
    }

    int x = m+1;
    fill(sol,sol+200005,-1);
    for (w = 1; w <= 2; w++) {
        for (i = 0; i < n; i++) {
            if (adjList[w][i].size() >= 2) Q.push(i);
        }
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();

            while (adjList[w][u].size() >= 2) {
                pii a = *adjList[w][u].begin();
                pii b = *(++adjList[w][u].begin());
                adjList2[x].pb(mp(abs(a.second),(a.second > 0)));
                adjList2[abs(a.second)].pb(mp(x,(a.second > 0)));
                adjList2[x].pb(mp(abs(b.second),(b.second < 0)));
                adjList2[abs(b.second)].pb(mp(x,(b.second < 0)));
                adjList[w][a.first].erase(mp(u,-a.second));
                adjList[w][b.first].erase(mp(u,-b.second));
                adjList[w][u].erase(a),adjList[w][u].erase(b);
                if (a.first != b.first) {
                    adjList[w][a.first].insert(mp(b.first,x));
                    adjList[w][b.first].insert(mp(a.first,-x));
                    if (adjList[w][a.first].size() >= 2) Q.push(a.first);
                    if (adjList[w][b.first].size() >= 2) Q.push(b.first);
                }
                else doDFS(x,0);
                x++;
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (adjList[1][i].size()+adjList[2][i].size() == 1) {
            if (!visited[i]) {
                int u = i,p = 1e9;
                while (1) {
                    visited[u] = 1;
                    pii v = mp(-1,-1);
                    for (pii e: adjList[1][u]) {
                        if (e.second != p) {
                            v = e;
                            break;
                        }
                    }
                    for (pii e: adjList[2][u]) {
                        if (e.second != p) {
                            v = e;
                            break;
                        }
                    }
                    if (v.first == -1) break;
                    else {
                        doDFS(abs(v.second),(v.second > 0));
                        p = -v.second,u = v.first;
                    }
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (adjList[1][i].size()+adjList[2][i].size() == 2) {
            if (!visited[i]) {
                int u = i,p = 1e9;
                do {
                    visited[u] = 1;
                    pii v = mp(-1,-1);
                    for (pii e: adjList[1][u]) {
                        if (e.second != p) {
                            v = e;
                            break;
                        }
                    }
                    for (pii e: adjList[2][u]) {
                        if (e.second != p) {
                            v = e;
                            break;
                        }
                    }
                    if (v.first == -1) break;
                    else {
                        doDFS(abs(v.second),(v.second > 0));
                        p = -v.second,u = v.first;
                    }
                } while (u != i);
            }
        }
    }
    printf("%d\n",ans);
    for (i = 1; i <= m; i++) printf("%d",sol[i]+1);
    printf("\n");

    return 0;
}