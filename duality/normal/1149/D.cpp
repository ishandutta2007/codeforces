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

int a,b;
vpii edgesa,edgesb;
vpii adjList[70];
int com[70],num[70],in[70];
int doDFS(int u,int c) {
    if (com[u] != -1) return 0;
    int i;
    com[u] = c,num[c]++;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i].first;
        if (adjList[u][i].second == a) doDFS(v,c);
    }
    return 0;
}
vi vv;
int dist[70][1 << 17],ans[70];
priority_queue<pair<int,pii> > H;
int main() {
    int i;
    int n,m;
    int u,v,c;
    scanf("%d %d %d %d",&n,&m,&a,&b);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d",&u,&v,&c);
        u--,v--;
        adjList[u].pb(mp(v,c));
        adjList[v].pb(mp(u,c));
        if (c == a) edgesa.pb(mp(u,v));
        else edgesb.pb(mp(u,v));
    }

    c = 0;
    fill(com,com+n,-1);
    for (i = 0; i < n; i++) {
        if (com[i] == -1) {
            doDFS(i,c);
            if (num[c] >= 4) in[c] = vv.size(),vv.pb(c);
            c++;
        }
    }
    //for (i = 0; i < n;i++)cout<<com[i]<<" ";
    //cout<<endl;
    //for(i=0;i<vv.size();i++)cout<<vv[i]<<" ";
    //cout<<endl;

    memset(dist,-1,sizeof(dist));
    fill(ans,ans+n,-1);
    if (!vv.empty() && (vv[0] == 0)) {
        dist[0][1] = 0;
        H.push(mp(0,mp(0,1)));
    }
    else {
        dist[0][0] = 0;
        H.push(mp(0,mp(0,0)));
    }
    while (!H.empty()) {
        int d = -H.top().first;
        int u = H.top().second.first;
        int m = H.top().second.second;
        H.pop();

        if (d > dist[u][m]) continue;
        if (ans[u] == -1) ans[u] = d;
        for (i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i].first;
            int w = adjList[u][i].second,m2 = m;
            if ((w == b) && (com[u] == com[v])) continue;
            if ((w == b) && (num[com[v]] >= 4)) {
                if (m & (1 << in[com[v]])) continue;
                else m2 |= (1 << in[com[v]]);
            }
            if ((dist[v][m2] == -1) || (dist[u][m]+w < dist[v][m2])) {
                dist[v][m2] = dist[u][m]+w;
                H.push(mp(-dist[v][m2],mp(v,m2)));
            }
        }
    }
    for (i = 0; i < n; i++) printf("%d%c",ans[i],((i == n-1) ? '\n':' '));

    return 0;
}