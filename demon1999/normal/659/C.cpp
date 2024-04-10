#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define sz(a) a.size()
#define re  return
#define fi first
#define se second

typedef std::pair<int, int> pii;

using namespace std;

void my_assert(bool q) {
    if (!q) while(true);
}

int n, m, k, b;
string s;
vector<int> ans;
unordered_map<int, int> qq;

int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    //freopen("point.in", "r", stdin);
    //freopen("point.out", "w", stdout);
    cin >> n >> m;
    forn(i, n) {
        cin >> b;
        qq[b] = 1;
    }
    for (int j = 1; m > 0; j++) {
        if (qq[j]) continue;
        m -= j;
        if (m >= 0) ans.push_back(j);
    }
    cout << sz(ans) << "\n";
    forn (i, sz(ans)) cout << ans[i] << " ";
    return 0;
}