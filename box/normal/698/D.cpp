#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;

pii noml(int x, int y) {
    if(x == 0 && y == 0) return {0, 0};
    if(x == 0 && y > 0) return {0, 1};
    if(x == 0 && y < 0) return {0, -1};
    if(x > 0 && y == 0) return {1, 0};
    if(x < 0 && y == 0) return {-1, 0};
    assert(x != 0 && y != 0);
    int c = __gcd(abs(x),abs(y));
    return {x/c, y/c};
}

pii pts[1005];
int n;

vector<int>revs[1005][7];

void gen(int x0,int y0,int c){
    map<pii,vector<int>>res;
    rep(i,n)
        res[noml(pts[i].fi - x0, pts[i].se - y0)].push_back(i);
    auto ev = [&](int x, int y) { return 1ll * x * x + 1ll * y * y; };
    for(auto&[slo, po] : res) {
        sort(po.begin(), po.end(), [&](int a, int b) {
            return ev(pts[a].fi - x0, pts[a].se - y0) < ev(pts[b].fi - x0, pts[b].se - y0);
        });
        rep(i, po.size()) for(int j=i-1; j>=0; j--) revs[po[i]][c].push_back(po[j]);
    }
}

int ax[10], ay[10];
bool ers[1005];
vector<int> res;
vector<int> seq;

bool dfs(int i) {
    if(ers[i]) return 1;
    if(!seq.size()) return 0;
    int s=seq.back();seq.pop_back();
    for(int j:revs[i][s])if(!dfs(j))return 0;
    ers[i]=1;res.push_back(i);
    return 1;
}
bool check(vector<int> order, int tar) {
    seq=order;
    bool x=dfs(tar);
    for(int i:res)ers[i]=0;
    res.clear();
    return x;
}

bool c[1005];

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int k, n; cin >> k >> n;
    rep(i, k) cin >> ax[i] >> ay[i];
    ::n = n;
    rep(i, n) cin >> pts[i].fi >> pts[i].se;
    rep(i, k) gen(ax[i], ay[i], i);
    vector<int> order(k); iota(order.begin(), order.end(), 0);
    do {
        rep(i, n) c[i] = c[i] || check(order, i);
    } while(next_permutation(all(order)));
    int ans = 0;
    rep(i, n) ans += c[i];
    cout << ans << endl;
}