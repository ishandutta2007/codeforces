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

vi adjList[100000];
int deg[100000],visited[100000];
queue<int> Q;
vi order;
int pos[100000];
bool comp(int a,int b) {
    return pos[a] < pos[b];
}
int main() {
    int i,j;
    int t,n,m,K;
    int u,v;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d %d",&n,&m,&K);
        for (i = 0; i < m; i++) {
            scanf("%d %d",&u,&v);
            u--,v--;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }

        for (i = 0; i < n; i++) {
            deg[i] = adjList[i].size(),visited[i] = 0;
            if (deg[i] < K) Q.push(i),visited[i] = 1;
        }
        while (!Q.empty()) {
            u = Q.front();
            Q.pop();
            order.pb(u);
            for (i = 0; i < adjList[u].size(); i++) {
                v = adjList[u][i];
                if (!visited[v]) {
                    deg[v]--;
                    if (deg[v] < K) Q.push(v),visited[v] = 1;
                }
            }
        }
        if (order.size() < n) {
            printf("1 %d\n",n-order.size());
            for (i = 0; i < n; i++) {
                if (!visited[i]) printf("%d ",i+1);
            }
            printf("\n");
        }
        else if ((LLI) K*(K-1)/2 > m) printf("-1\n");
        else {
            for (i = 0; i < n; i++) pos[order[i]] = i;
            for (i = 0; i < n; i++) sort(adjList[i].begin(),adjList[i].end(),comp);
            for (i = 0; i < n; i++) {
                u = order[i];
                vi vv;
                for (j = 0; j < adjList[u].size(); j++) {
                    if (pos[adjList[u][j]] > i) vv.pb(adjList[u][j]);
                }
                if (vv.size() < K-1) continue;
                int f = 0;
                for (j = 0; j < vv.size(); j++) {
                    int k,l = 0;
                    for (k = j+1; k < vv.size(); k++) {
                        int p = lower_bound(adjList[vv[j]].begin()+l,adjList[vv[j]].end(),vv[k],comp)-adjList[vv[j]].begin();
                        if ((p < adjList[vv[j]].size()) && (adjList[vv[j]][p] == vv[k])) l = p;
                        else {
                            f = 1;
                            break;
                        }
                    }
                    if (f) break;
                }
                if (!f) {
                    printf("2\n%d",u+1);
                    for (j = 0; j < vv.size(); j++) printf(" %d",vv[j]+1);
                    printf("\n");
                    break;
                }
            }
            if (i == n) printf("-1\n");
        }

        for (i = 0; i < n; i++) adjList[i].clear();
        order.clear();
    }

    return 0;
}