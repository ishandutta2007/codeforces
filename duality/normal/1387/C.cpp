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

int b[100];
vector<pair<pii,int> > adjList[102];
int trie[51][2],leaf[51],fail[51],nxt[51][2],num = 0;
queue<int> Q;
struct state {
    ULLI d; int u,a,b;
    state(ULLI dd,int uu,int aa,int bb) {
        d = dd,u = uu,a = aa,b = bb;
    }
};
class comp {
    public:
        bool operator()(state a,state b) {
            return a.d > b.d;
        }
};
priority_queue<state,vector<state>,comp> H;
ULLI dist[102][51][51];
int main() {
    int i,j;
    int G,N,M;
    int a,k,l,c;
    scanf("%d %d %d",&G,&N,&M);
    int G2 = G;
    memset(trie,-1,sizeof(trie));
    for (i = 0; i < N; i++) {
        scanf("%d %d",&a,&k);
        for (j = 0; j < k; j++) scanf("%d",&b[j]);
        if (k == 1) adjList[b[0]].pb(mp(mp(a,-1),-1));
        else {
            for (j = 1; j < k; j++) {
                if (j == k-1) {
                    adjList[b[j-1]].pb(mp(mp(a,b[j]),1));
                    adjList[b[j]].pb(mp(mp(a,b[j-1]),0));
                }
                else {
                    adjList[b[j-1]].pb(mp(mp(a,G2),1));
                    adjList[G2].pb(mp(mp(a,b[j-1]),0));
                    a = G2++;
                }
            }
        }
    }
    for (i = 0; i < M; i++) {
        scanf("%d",&l);
        int u = 0;
        for (j = 0; j < l; j++) {
            scanf("%d",&c);
            if (trie[u][c] == -1) trie[u][c] = ++num;
            u = trie[u][c];
        }
        leaf[u] = 1;
    }
    num++;

    for (i = 0; i < 2; i++) {
        if (trie[0][i] != -1) nxt[0][i] = trie[0][i],fail[trie[0][i]] = 0,Q.push(trie[0][i]);
        else nxt[0][i] = trie[0][i] = 0;
    }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (i = 0; i < 2; i++) {
            if (trie[u][i] != -1) {
                int v = fail[u];
                while (trie[v][i] == -1) v = fail[v];
                v = trie[v][i];
                fail[trie[u][i]] = v,leaf[trie[u][i]] |= leaf[v];
                nxt[u][i] = trie[u][i],Q.push(trie[u][i]);
            }
            else nxt[u][i] = nxt[fail[u]][i];
        }
    }

    for (i = 0; i < G2; i++) {
        for (j = 0; j < num; j++) fill(dist[i][j],dist[i][j]+num,1ULL << 63);
        sort(adjList[i].begin(),adjList[i].end());
        adjList[i].resize(unique(adjList[i].begin(),adjList[i].end())-adjList[i].begin());
    }
    for (i = 0; i < num; i++) {
        if (leaf[i]) continue;
        for (j = 0; j < 2; j++) {
            if (!leaf[nxt[i][j]]) dist[j][i][nxt[i][j]] = 1,H.emplace(1,j,i,nxt[i][j]);
        }
    }
    while (!H.empty()) {
        ULLI d = H.top().d;
        int u = H.top().u,a = H.top().a,b = H.top().b;
        H.pop();

        if (d > dist[u][a][b]) continue;
        for (i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i].first.first,w = adjList[u][i].first.second;
            if (adjList[u][i].second == -1) {
                if (dist[u][a][b] < dist[v][a][b]) {
                    dist[v][a][b] = dist[u][a][b];
                    H.emplace(dist[v][a][b],v,a,b);
                }
            }
            else if (adjList[u][i].second == 0) {
                for (j = 0; j < num; j++) {
                    if (!leaf[j] && (dist[w][j][a]+dist[u][a][b] < dist[v][j][b])) {
                        dist[v][j][b] = dist[w][j][a]+dist[u][a][b];
                        H.emplace(dist[v][j][b],v,j,b);
                    }
                }
            }
            else {
                for (j = 0; j < num; j++) {
                    if (!leaf[j] && (dist[u][a][b]+dist[w][b][j] < dist[v][a][j])) {
                        dist[v][a][j] = dist[u][a][b]+dist[w][b][j];
                        H.emplace(dist[v][a][j],v,a,j);
                    }
                }
            }
        }
    }
    for (i = 2; i < G; i++) {
        ULLI d = 1ULL << 63;
        for (j = 0; j < num; j++) {
            if (!leaf[j]) d = min(d,dist[i][0][j]);
        }
        if (d == (1ULL << 63)) printf("YES\n");
        else printf("NO %llu\n",d);
    }

    return 0;
}