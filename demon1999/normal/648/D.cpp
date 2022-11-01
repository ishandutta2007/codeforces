#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
using namespace std;

const ll mod = 998244353;
struct st{
    int l, q, p;
};

int n, m, xl, yl, ans, u, t;
string s[100000];
vector<st> a;
multiset<int> qq;

bool cmp(st a, st b) {
    re a.l < b.l || (a.l == b.l && a.q < b.q);
}

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //freopen("bridge.in", "r",  stdin);
    //freopen("bridge.out", "w", stdout);
    cin >> n >> m;
    forn (i, n) {
        cin >> u;
        a.push_back({u, 0, 0});
    }
    forn (i, m) {
        cin >> u >> t;
        a.push_back({u - t, -1, u + t});
    }
    sort(a.begin(), a.end(), cmp);
    forn (i, sz(a)) {
        while (!qq.empty() && *qq.begin() < a[i].l) qq.erase(qq.begin());
        if (a[i].q == -1) {
            qq.insert(a[i].p);
            continue;
        }
        if (!qq.empty()) {
            qq.erase(qq.begin());
            ans++;
        }
    }
    cout << ans;
    return 0;
}