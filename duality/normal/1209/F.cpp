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
#define MOD 1000000007

vpii adjList[100000],adjList2[100000];
int digits[100001];
int trie[2000000][10],num = 0;
int parent[2000000][21];
int depth[2000000],cc[2000000],mm[2000000];
int len[100000];
int dist[2000000];
priority_queue<pii> H;
vi order;
int insert(int u,int n) {
    int i,j,c = u;
    vi d;
    printVar(u);
    printVar(n);
    while (n > 0) d.pb(n % 10),n /= 10;
    printArr(d,d.size());
    reverse(d.begin(),d.end());
    for (i = 0; i < d.size(); i++) {
        if (trie[c][d[i]] == 0) {
            trie[c][d[i]] = ++num,depth[num] = depth[c]+1,cc[num] = d[i];
            mm[num] = (mm[c]*10LL+d[i]) % MOD;
            parent[num][0] = c;
            for (j = 1; j < 21; j++) {
                if (parent[num][j-1] == -1) break;
                else parent[num][j] = parent[parent[num][j-1]][j-1];
            }
        }
        c = trie[c][d[i]];
        printVar(c);
    }
    return c;
}
int comp(int u,int v) {
    if (u == v) return 0;
    assert(depth[u] == depth[v]);
    int i;
    for (i = 20; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) u = parent[u][i],v = parent[v][i];
    }
    return cc[u] < cc[v];
}
int main() {
    int i,j;
    int n,m,x,y;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d %d",&x,&y);
        x--,y--;
        adjList[x].pb(mp(y,i+1));
        adjList[y].pb(mp(x,i+1));
    }

    for (i = 0; i < n; i++) len[i] = -1;
    for (i = 1; i <= m; i++) {
        int t = i;
        while (t > 0) t /= 10,digits[i]++;
    }
    len[0] = 0,H.push(mp(0,0));
    while (!H.empty()) {
        int u = H.top().second;
        int d = -H.top().first;
        H.pop();
        order.pb(u);

        for (i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i].first;
            if ((len[v] == -1) || ((len[u]+digits[adjList[u][i].second] < len[v]))) {
                len[v] = len[u]+digits[adjList[u][i].second];
                H.push(mp(-len[v],v));
            }
        }
    }
    printArr(len,n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < adjList[i].size(); j++) {
            if (len[adjList[i][j].first] == len[i]+digits[adjList[i][j].second]) {
                adjList2[adjList[i][j].first].pb(mp(i,adjList[i][j].second));
                //cout<<adjList[i][j].first<<"->"<<i<<endl;
            }
        }
    }
    fill(parent[0],parent[0]+21,-1);
    for (i = 1; i < order.size(); i++) {
        int u = order[i];
        //cout<<u<<endl;
        vi vv;
        for (j = 0; j < adjList2[u].size(); j++) vv.pb(insert(dist[adjList2[u][j].first],adjList2[u][j].second));
        int b = vv[0];
        //cout<<b<<endl;
        for (j = 1; j < vv.size(); j++) {
            if (comp(vv[j],b)) b = vv[j];
        }
        dist[u] = b;
    }
    for (i = 1; i < n; i++) printf("%d\n",mm[dist[i]]);

    return 0;
}