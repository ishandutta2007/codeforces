// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;
 
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

int bcj[200006];
void binit(){memset(bcj,-1,sizeof bcj);}
int bget(int i){return (bcj[i]<0)?i:(bcj[i]=bget(bcj[i]));}
bool bmerge(int i,int j){int ri=bget(i),rj=bget(j);if(ri==rj){return 0;}if(bcj[ri]>bcj[rj]){swap(ri,rj);}bcj[ri]+=bcj[rj];bcj[rj]=ri;return 1;}

vector<pii> elist[200006];
vector<pair<int, pii>> edgelist;

int fa[200005][19];
int mi[200005][19];
int mx[200005][19];
int dep[200005];

void dfs(int node, int par, int le) {
    fa[node][0] = par;
    mi[node][0] = mx[node][0] = le;
    if(par == -1) dep[node] = 0;
    else dep[node] = dep[par]+1;
    int pt = 0;
    while(fa[node][pt] != -1) {
        fa[node][pt+1] = fa[fa[node][pt]][pt];
        mi[node][pt+1] = min(mi[node][pt], mi[fa[node][pt]][pt]);
        mx[node][pt+1] = max(mx[node][pt], mx[fa[node][pt]][pt]);
        pt++;
    }
    while(pt != 19) fa[node][pt++] = -1;
    for(pii& v:elist[node]) if(v.fi != par) dfs(v.fi, node, v.se);
}

pii distt(int u, int v) {
    int ans1 = 1000006, ans2 = 0;
    if(dep[u] > dep[v]) swap(u, v);
    for(int cnt=18; cnt>=0; cnt--) {
        if(fa[v][cnt] != -1 && dep[u] <= dep[fa[v][cnt]]) {
            ans1 = min(ans1, mi[v][cnt]);
            ans2 = max(ans2, mx[v][cnt]);
            v = fa[v][cnt];
        }
    }
    for(int cnt=18; cnt>=0; cnt--) {
        if(fa[v][cnt] != -1 && fa[u][cnt] != -1 && fa[v][cnt] != fa[u][cnt]) {
            ans1 = min(ans1, mi[v][cnt]);
            ans2 = max(ans2, mx[v][cnt]);
            v = fa[v][cnt];
            ans1 = min(ans1, mi[u][cnt]);
            ans2 = max(ans2, mx[u][cnt]);
            u = fa[u][cnt];
        }
    }
    if(v != u) {
        ans1 = min(ans1, min(mi[u][0], mi[v][0]));
        ans2 = max(ans2, max(mx[u][0], mx[v][0]));
        return {ans1, ans2};
    }
    return {ans1, ans2};
}

vector<pair<int, pii>> li2;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    rep(i, m) {
        int a, b, c; cin >> a >> b >> c;
        edgelist.pb({c, {a, b}});
        li2.pb({c, {a, b}});
    }
    sort(all(edgelist));
    binit(); int cnt = 0; ll tow = 0;
    for(auto& v:edgelist) {
        bool t = bmerge(v.se.fi, v.se.se);
        if(t) { 
            cnt++; 
            tow += v.fi;
            elist[v.se.fi].pb({v.se.se, v.fi});
            elist[v.se.se].pb({v.se.fi, v.fi});
            if(cnt == n-1) break;
        }
    }
    dfs(1, -1, 0);
    for(auto& v:li2)
        cout << tow - distt(v.se.fi, v.se.se).se + v.fi << endl;
}