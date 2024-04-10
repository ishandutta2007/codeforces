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

int n, m, x, y, ans, cnt, qq, use[200000];
vector<int> edge[200000];

void dfs(int i) {
    use[i] = 1;
    qq++;
    for (auto v : edge[i]) {
        cnt++;
        if (!use[v]) dfs(v);
    }
}
int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    //freopen("point.in", "r", stdin);
    //freopen("point.out", "w", stdout);
    cin >> n >> m;
    forn (i, m) {
        cin >> x >> y;
        x--; y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    forn (i, n) {
        if (!use[i]) {
            qq = 0;
            cnt = 0;
            dfs(i);
            cnt /= 2;
            if (cnt == qq - 1) ans++;
        }
    }
    cout << ans;
    return 0;
}