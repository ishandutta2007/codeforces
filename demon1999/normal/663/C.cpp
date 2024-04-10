#include <bits/stdc++.h>


#define forn(i, n) for(int i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second
#define prev previouss
using namespace std;


typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

ll k1, k2, n, m, use[200000], use1[200000];
vector<pair<int, int> > edge[200000];
vector<int> dp[2][2], aa, bb;

int dfs(int i, int j) {
    //cout << i << " " << j << " HEHE " << use[i] << endl;
    int sum = 0;
    if (use[i]) aa.push_back(i);
    for (auto v : edge[i]) {
        int k = (use[i] + v.se) % 2, p = 0;
        if (k != j) p = 1;
        //cout << v.se << " " << use[v.fi] <<  " " << p <<  " hophey\n";
        if (use[v.fi] != -1) {
            if (use[v.fi] != p) {
                re n + 1;
            }
        }
        else {
            use[v.fi] = p;
            sum += p + dfs(v.fi, j);
        }
    }
    re sum;
}

int dfs1(int i, int j) {
    //cout << i << " " << j << " " << use1[i] << endl;
    int sum = 0;
    if (use1[i]) bb.push_back(i);
    for (auto v : edge[i]) {
        int k = (use1[i] + v.se) % 2, p = 0;
        if (k != j) p = 1;
        if (use1[v.fi] != -1) {
            if (use1[v.fi] != p) re n + 1;
        }
        else {
            use1[v.fi] = p;
            sum += p + dfs1(v.fi, j);
        }
    }
    re sum;
}

signed main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("division.in", "r",  stdin));
    cin >> n >> m;
    forn (i, m) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--; b--;
        int k = 0;
        if (c == 'R') k = 1;
        edge[a].push_back({b, k});
        edge[b].push_back({a, k});
    }
    ll ans = n + 1;
    int nu;
    for (int j = 0; j <= 1; j++) {
        forn (i, n) {
            use[i] = -1;
            use1[i] = -1;
        }
        ll k = 0;
        forn (i, n) {
            if (use[i] == -1) {
                use[i] = 0;
                aa.resize(0); bb.resize(0);
                if (dfs(i, j) > n) aa.resize(n + 1);
                use1[i] = 1;
                if (dfs1(i, j) > n) bb.resize(n + 1);
                k += min(sz(aa), sz(bb));
            }
        }
        ans = min(ans, k);
        if (ans == k) {
            nu = j;
        }
    }
    if (ans == n + 1) {
        cout << -1;
        re 0;
    }
    cout << ans << "\n";
    forn (i, n) {
        use[i] = -1;
        use1[i] = -1;
    }
    int j = nu;
    vector<ll> ans1;
    forn (i, n) {
        if (use[i] == -1) {
            use[i] = 0;
            aa.resize(0);
            bb.resize(0);
            if (dfs(i, j) > n) aa.resize(n + 1);
            use1[i] = 1;
            if (dfs1(i, j) > n) bb.resize(n + 1);
            if (sz(aa) < sz(bb)) {
                forn (i, sz(aa)) ans1.push_back(aa[i] + 1);
            }
            else forn (i, sz(bb)) ans1.push_back(bb[i] + 1);
        }
    }
    sort(ans1.begin(), ans1.end());
    forn (i, sz(ans1)) cout << ans1[i] << " ";
    return 0;
}