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
#define MOD 998244353

vpii adjList[200000];
int dist[200000][25];
priority_queue<pair<int,pii> > H;
pii dist2[200000][2];
priority_queue<pair<pii,int> > H2;
int main() {
    int i;
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(mp(v,1));
        adjList[v].pb(mp(u,0));
    }
    if (n == 1) {
        printf("0\n");
        return 0;
    }

    memset(dist,-1,sizeof(dist));
    dist[0][0] = 0,H.push(mp(0,mp(0,0)));
    while (!H.empty()) {
        int d = -H.top().first;
        int u = H.top().second.first;
        int t = H.top().second.second;
        H.pop();

        if (d > dist[u][t]) continue;
        for (i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i].first;
            int t2 = t;
            if (adjList[u][i].second != ((t+1) & 1)) t2++;
            if ((t2 < 25) && ((dist[v][t2] == -1) || (d+1 < dist[v][t2]))) {
                dist[v][t2] = d+1;
                H.push(mp(-dist[v][t2],mp(v,t2)));
            }
        }
    }
    LLI ans = 1e18;
    for (i = 0; i < 25; i++) {
        if (dist[n-1][i] != -1) ans = min(ans,(LLI) dist[n-1][i]+(1 << i)-1);
    }
    if (ans < 1e18) {
        printf("%I64d\n",ans % MOD);
        return 0;
    }

    for (i = 0; i < n; i++) dist2[i][0] = dist2[i][1] = mp(-1,-1);
    dist2[0][0] = mp(0,0);
    H2.push(mp(mp(0,0),0));
    while (!H2.empty()) {
        pii d = H2.top().first;
        int u = H2.top().second/2;
        int t = H2.top().second & 1;
        H2.pop();
        d.first *= -1,d.second *= -1;

        if (d > dist2[u][t]) continue;
        pii d2 = d;
        d2.first++;
        if ((dist2[u][t^1] == mp(-1,-1)) || (d2 < dist2[u][t^1])) {
            dist2[u][t^1] = d2;
            H2.push(mp(mp(-d2.first,-d2.second),u*2+(t^1)));
        }
        for (i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i].first;
            pii d2 = d;
            d2.second++;
            if (adjList[u][i].second == ((d.first+1) & 1)) {
                if ((dist2[v][t] == mp(-1,-1)) || (d2 < dist2[v][t])) {
                    dist2[v][t] = d2;
                    H2.push(mp(mp(-d2.first,-d2.second),v*2+t));
                }
            }
        }
    }
    pii q = min(dist2[n-1][0],dist2[n-1][1]);
    LLI ans2 = q.second-1;
    LLI p = 1;
    for (i = 0; i < q.first; i++) p *= 2,p %= MOD;
    ans2 += p,ans2 %= MOD;
    printf("%I64d\n",ans2);

    return 0;
}