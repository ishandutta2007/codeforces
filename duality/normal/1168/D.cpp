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

int p[150000];
char c[150000];
vi adjList[150000],adjList2[150000];
int depth[150000],pp[150000],down[150000];
int doDFS(int u,int d,int p) {
    int i;
    depth[u] = d,pp[u] = p;
    if (adjList[u].size() != 1) down[u] = u;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        doDFS(v,d+1,(adjList[u].size() == 2) ? u:p);
        if (adjList[u].size() == 1) down[u] = down[v];
    }
    return 0;
}
int cc[150000][26],path[150000][26],sum[150000],con[150000];
int main() {
    int i;
    int n,q;
    int v;
    char ch;
    scanf("%d %d",&n,&q);
    for (i = 1; i < n; i++) {
        scanf("%d %c",&p[i],&c[i]),p[i]--;
        adjList[p[i]].pb(i);
    }

    int j,k,l,dd = -1,no = 0;
    doDFS(0,0,0);
    for (i = n-1; i >= 1; i--) {
        if (adjList[i].size() != 1) {
            int u = i;
            while (u != pp[i]) {
                if (c[u] != '?') cc[i][c[u]-'a']++;
                u = p[u];
            }
            for (j = 0; j < 26; j++) path[pp[i]][j] = max(path[pp[i]][j],path[i][j]+cc[i][j]);
            adjList2[pp[i]].pb(i);
        }
        if (adjList[i].size() == 0) {
            if (dd == -1) dd = depth[i];
            else if (dd != depth[i]) {
                for (i = 0; i < q; i++) printf("Fou\n");
                return 0;
            }
        }
    }
    for (i = 0; i < n; i++) {
        if ((i == 0) || (adjList[i].size() != 1)) {
            int s = 0;
            for (j = 0; j < 26; j++) s += path[i][j];
            if (s > dd-depth[i]) con[i] = 1,no++;
            sum[i] = s;
        }
    }

    for (i = 0; i < q; i++) {
        scanf("%d %c",&v,&ch),v--;
        vi poss;
        if (c[v] != '?') cc[down[v]][c[v]-'a']--,poss.pb(c[v]-'a');
        c[v] = ch;
        if (c[v] != '?') cc[down[v]][c[v]-'a']++,poss.pb(c[v]-'a');
        v = down[v];
        while (v != 0) {
            for (l = 0; l < poss.size(); l++) {
                j = poss[l];
                sum[pp[v]] -= path[pp[v]][j];
                path[pp[v]][j] = 0;
                for (k = 0; k < adjList2[pp[v]].size(); k++) {
                    int w = adjList2[pp[v]][k];
                    path[pp[v]][j] = max(path[pp[v]][j],path[w][j]+cc[w][j]);
                }
                sum[pp[v]] += path[pp[v]][j];
            }
            if (con[pp[v]]) no--;
            con[pp[v]] = (sum[pp[v]] > dd-depth[pp[v]]);
            if (con[pp[v]]) no++;
            v = pp[v];
        }
        if (no) printf("Fou\n");
        else {
            int ans = 0;
            for (j = 0; j < 26; j++) ans += (path[0][j]+dd-sum[0])*(j+1);
            printf("Shi %d\n",ans);
        }
    }

    return 0;
}