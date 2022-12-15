#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

vector<int> loc[5005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        loc[a].pb(i);
    }
    const int C = (1<<13);
    vector<int> dp(C, -1);
    dp[0] = 0;
    for (int i = 0; i <= 5000; i++)
        if (SZ(loc[i])) {
            auto tmp = dp;
            for (int j = 0; j < C; j++)
                if (dp[j] != -1) {
                    auto it = upper_bound(ALL(loc[i]), dp[j]);
                    if (it != loc[i].end() && (tmp[j^i] == -1 || tmp[j^i] > (*it)))
                        tmp[j^i] = (*it);
                }
            dp.swap(tmp);
        }
    vector<int> ans;
    for (int i = 0; i < C; i++)
        if (dp[i] != -1)
            ans.pb(i);
    cout << SZ(ans) << endl;
    for (int x : ans)
        cout << x << " ";
    cout << endl;
}