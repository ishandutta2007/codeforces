#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define SZ(a) ((int)a.size())

vector<int> v[105], ans;
int p[105], dph[105], isg[105];
int lft;

void dfs(int now) {
    if (!isg[now])
        lft--;
    assert(lft >= 0);
    ans.pb(now);
    for (int x : v[now])
        if (!isg[x] && lft) {
            dfs(x);
            ans.pb(now);
        }
    for (int x : v[now])
        if (isg[x])
            dfs(x);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            v[i].clear(), isg[i] = 0;
        ans.clear();
        for (int i = 2; i <= n; i++)
            cin >> p[i], v[p[i]].pb(i);
        dph[1] = 1;
        for (int i = 1; i <= n; i++)
            for (int x : v[i])
                dph[x] = dph[i] + 1;
        int g = 1;
        for (int i = 1; i <= n; i++)
            if (dph[i] <= k && dph[i] > dph[g])
                g = i;
        lft = k - dph[g];        
        isg[g] = 1;
        while (g != 1)
            g = p[g], isg[g] = 1;
        dfs(1);
        cout << SZ(ans) - 1 << "\n";
        for (int i = 0; i < SZ(ans); i++)
            cout << ans[i] << " \n"[i == SZ(ans) - 1];
    }
}