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
#pragma GCC optimize("Ofast")

vpii adjList[100000];
map<pii,int> edges;
vector<pair<int,pii> > edges0;
int com[100000],cc = 0;
int xx[100000];
UI poss[100000];
unordered_map<UI,UI> M[1 << 22];
UI expand(UI m) {
    if (m & 1) return m;
    if (M[m >> 10].count(m)) return M[m >> 10][m];
    int i,j;
    UI o = m;
    while (1) {
        int f = 0;
        for (i = 0; i < 32; i++) {
            if (m & (1U << i)) {
                for (j = i+1; j < 32; j++) {
                    if (m & (1U << j)) {
                        if (!(m & (1U << (i^j)))) m |= (1U << (i^j)),f = 1;
                    }
                }
            }
        }
        if (!f) break;
    }
    M[o >> 10][o] = m;
    return m;
}
UI add(UI m,UI n) {
    if ((m | n) & 1) return m | n | 1;
    else if ((m & n) != 0) return m | n | 1;
    else return expand(m | n);
}
int disc[100000],num = 0;
int doDFS(int u,int x,int p) {
    int i;
    com[u] = cc,xx[u] = x,disc[u] = num++;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i].first;
        if (com[v] == -1) doDFS(v,x^adjList[u][i].second,u);
        else if ((v != p) && (disc[v] < disc[u])) poss[cc] = add(poss[cc],(1U << (xx[u]^xx[v]^adjList[u][i].second)));
    }
    return 0;
}
struct data {
    int t;
    UI poss;
};
vector<data> vv;
int done[100000];
unordered_map<UI,int> dp,dp2;
int main() {
    int i;
    int n,m,a,b,w;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d",&a,&b,&w);
        a--,b--;
        if (a > b) swap(a,b);
        if (a == 0) edges0.pb(mp(0,mp(b,w)));
        else {
            adjList[a].pb(mp(b,w));
            adjList[b].pb(mp(a,w));
            edges[mp(a,b)] = edges[mp(b,a)] = w;
        }
    }
    debug "here";

    for (i = 1; i < n; i++) com[i] = -1;
    for (i = 1; i < n; i++) {
        if (com[i] == -1) doDFS(i,0,-1),cc++;
    }
    for (i = 0; i < edges0.size(); i++) edges0[i].first = com[edges0[i].second.first];
    sort(edges0.begin(),edges0.end());
    for (i = 1; i < edges0.size(); i++) {
        if (edges0[i].first == edges0[i-1].first) {
            data d;
            d.t = edges0[i].second.second^edges0[i-1].second.second^edges[mp(edges0[i].second.first,edges0[i-1].second.first)];
            d.poss = poss[edges0[i].first];
            vv.pb(d);
            done[i-1] = done[i] = 1;
        }
    }
    for (i = 0; i < edges0.size(); i++) {
        if (!done[i]) vv.pb((data){-1,poss[edges0[i].first]});
    }
    debug "here";

    int j;
    dp2[0] = 1,dp[0] = 1;
    for (i = 0; i < vv.size(); i++) {
        //cout<<i<<": "<<vv[i].t<<","<<vv[i].poss<<endl;
        for (auto it = dp2.begin(); it != dp2.end(); it++) {
            if (vv[i].t == -1) {
                UI m = add(it->first,vv[i].poss);
                if (!(m & 1)) {
                    dp[m] += it->second;
                    if (dp[m] >= MOD) dp[m] -= MOD;
                }
            }
            else {
                UI m = add(it->first,vv[i].poss);
                int x = 2*it->second;
                if (x >= MOD) x -= MOD;
                if (!(m & 1)) {
                    dp[m] += x;
                    if (dp[m] >= MOD) dp[m] -= MOD;
                }
                m = add(m,(1U << vv[i].t));
                if (!(m & 1)) {
                    dp[m] += it->second;
                    if (dp[m] >= MOD) dp[m] -= MOD;
                }
            }
        }
        dp2 = dp;
        /*for (j = 0; j < dp.size(); j++) {
            if (dp2.empty()) dp2.pb(dp[j]);
            else {
                if (dp[j].first == dp2.back().first) {
                    dp2.back().second += dp[j].second;
                    if (dp2.back().second >= MOD) dp2.back().second -= MOD;
                }
                else dp2.pb(dp[j]);
            }
        }*/
        /*for(j=0;j<dp2.size();j++){
            cout<<dp2[j].first<<","<<dp2[j].second<<" ";
        }
        cout<<endl;*/
    }
    int ans = 0;
    for (auto it = dp2.begin(); it != dp2.end(); it++) ans += it->second,ans %= MOD;
    printf("%d\n",ans);

    //for(i = 0;i<vv.size();i++){
    //    cout<<vv[i].t<<" "<<vv[i].poss<<endl;
    //}


    return 0;
}