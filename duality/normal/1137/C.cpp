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

int D;
vi adjList[100000],adjList2[100000];
char s[100000][51];
int disc[100000],low[100000],inStack[100000],num = 0;
int com[100000],rep[100000],scc = 0;
vi cc[100000];
vi S;
int doDFS(int u) {
    int i;
    disc[u] = low[u] = num++;
    S.pb(u),inStack[u] = 1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (disc[v] == -1) doDFS(v),low[u] = min(low[u],low[v]);
        else if (inStack[v]) low[u] = min(low[u],disc[v]);
    }
    if (disc[u] == low[u]) {
        while (1) {
            int v = S.back();
            S.pop_back(),inStack[v] = 0;
            com[v] = scc,rep[scc] = v;
            cc[scc].pb(v);
            if (u == v) break;
        }
        scc++;
    }
    return 0;
}
queue<pii> Q;
int poss[100000][50],poss2[100000][50];
int dp[100000][50],done[100000];
int doDFS4(int u) {
    //cout<<u<<endl;
    int d;
    if (done[u]) return 0;
    if (u != rep[com[u]]) {
        doDFS4(rep[com[u]]);
        for (d = 0; d < D; d++) {
            int i,ans = 0;
            dp[u][d] = 0;
            for (i = 0; i < D; i++) {
                if (poss2[u][i]) ans = max(ans,dp[rep[com[u]]][(i+d) % D]);
            }
            dp[u][d] = ans;
        }
        return 0;
    }

    done[u] = 1;
    for (d = 0; d < D; d++) {
        int i,j,k,x = 0;
        for (i = 0; i < cc[com[u]].size(); i++) {
            int v = cc[com[u]][i];
            for (j = 0; j < D; j++) {
                if (poss[v][j] && (s[v][(j+d) % D] == '1')) {
                    x++;
                    break;
                }
            }
        }
        dp[u][d] = x;
        for (i = 0; i < cc[com[u]].size(); i++) {
            int v = cc[com[u]][i];
            for (j = 0; j < D; j++) {
                if (poss[v][j]) {
                    for (k = 0; k < adjList[v].size(); k++) {
                        int w = adjList[v][k];
                        if (com[v] != com[w]) {
                            doDFS4(w);
                            dp[u][d] = max(dp[u][d],dp[w][(j+d+1) % D]+x);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
int main() {
    int i;
    int n,m;
    int u,v;
    scanf("%d %d %d",&n,&m,&D);
    for (i = 0; i < m; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        //u = rand() % n,v = rand() % n;
        adjList[u].pb(v);
        adjList2[v].pb(u);
    }
    for (i = 0; i < n; i++) {
        scanf("%s",s[i]);
        //for (int j=0;j<D;j++)s[i][j] = (rand() & 1) ? '0':'1';
    }

    int j;
    for (i = 0; i < n; i++) disc[i] = low[i] = -1;
    for (i = 0; i < n; i++) {
        if (disc[i] == -1) doDFS(i);
    }
    debug "here";
    //printArr(com,n);
    for (i = 0; i < scc; i++) {
        Q.push(mp(rep[i],0)),poss[rep[i]][0] = 1;
        while (!Q.empty()) {
            pii u = Q.front();
            //cout<<u.first<<","<<u.second<<endl;
            Q.pop();

            for (j = 0; j < adjList[u.first].size(); j++) {
                int v = adjList[u.first][j];
                if ((com[u.first] == com[v]) && !poss[v][(u.second+1) % D]) {
                    poss[v][(u.second+1) % D] = 1;
                    Q.push(mp(v,(u.second+1) % D));
                }
            }
        }
        Q.push(mp(rep[i],0)),poss2[rep[i]][0] = 1;
        while (!Q.empty()) {
            pii u = Q.front();
            Q.pop();

            for (j = 0; j < adjList2[u.first].size(); j++) {
                int v = adjList2[u.first][j];
                if ((com[u.first] == com[v]) && !poss2[v][(u.second+1) % D]) {
                    poss2[v][(u.second+1) % D] = 1;
                    Q.push(mp(v,(u.second+1) % D));
                }
            }
        }
        //doDFS2(rep[i],0),doDFS3(rep[i],0);
    }
   // for (i = 0;i <n;i++){
   //     for(int j=0;j<D;j++)cout<<poss[i][j];
   //     cout<<endl;
   // }
    debug "here";
    memset(dp,-1,sizeof(dp));
    int ans = 0;
    doDFS4(rep[com[0]]);
    for (i = 0; i < D; i++) {
        if (poss2[0][i]) ans = max(ans,dp[rep[com[0]]][i]);
    }
    printf("%d\n",ans);

    return 0;
}