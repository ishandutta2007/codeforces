#include <bits/stdc++.h>

using namespace std;

#define long long long 
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for(int i = -1; ++i < n; )

namespace sol {
// actual solution start here

#define maxn 201010
int n, m;
set<int> a;
map<int, vi> b;
int dp[maxn], tr[maxn];

vi tans;
void gentans(int i) {
    if (tr[i] != -1) gentans(tr[i]);
    for (auto f: b[i]) tans.push_back(f);
}

int d, x, y;
pair<long, long> exgcd(long a, long b) {
    if(b == 0) return {1, 0};
    else {
        ii ans = exgcd(b, a % b);
        int t = ans.xx;
        ans.xx = ans.yy;
        ans.yy = t - (a/b) * ans.yy;
        return ans;
    }
}

long inv(long a, long m) {
    return (exgcd(a, m).xx % m + m) % m;
}

int main() {
    cin >> n >> m;
    rep(i, m) a.insert(i);
    rep(i, n) {
        int t; cin >> t;
        a.erase(t);
    }
    bool has0 = false;
    if (a.count(0)) {
        has0 = 1;
        a.erase(0);
    }
    for (auto i: a) {
        b[__gcd(i, m)].push_back(i);
    }

    memset(tr, -1, sizeof tr);
    memset(dp, 0, sizeof dp);

    int ma = -1;

    for (auto i: b) {
        clog << i.xx << endl;
        dp[i.xx] += sz(i.yy);
        if (ma == -1 or dp[ma] < dp[i.xx]) ma = i.xx;
        for (auto f : b) {
            if (f.xx % i.xx) continue;
            if (dp[i.xx] <= dp[f.xx]) continue;
            dp[f.xx] = dp[i.xx];
            tr[f.xx] = i.xx;
        }
    }

    if (ma == -1) {
        cout << "1\n0";
        exit(0);
    }
    cout << dp[ma] + has0 << '\n';
    gentans(ma);
    //clog << ma << endl;
    //for (auto i : tans)  clog << i << ' ';
    cout << tans[0] << ' ' ;
    rep(i, sz(tans) - 1) {
        long u = tans[i], v = tans[i + 1];
        long t = __gcd(u, (long) m);
        u /= t, v /= t;
        long t2 = (inv(u, m / t) * v) % m;
        cout << t2 << ' ';
    }
    if (has0) cout << 0;

    return 0;
} }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return sol::main();
}