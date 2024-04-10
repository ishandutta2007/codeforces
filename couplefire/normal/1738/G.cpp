#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<string> grid(n);
    vector<string> ans(n, string(n, '1'));
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<int> lim1(n, -1), lim2(n, -1);
    for (int i = 0; i < n-k+1; ++i) {
        for (int j = i; j > 0; --j) {
            lim1[j] = max({lim1[j-1], lim1[j]+1, lim1[j+1]+1});
            bool found = false;
            for (; lim1[j]+j < n; ++lim1[j]) {
                if (grid[lim1[j]][lim1[j]+j] == '1') {
                    ans[lim1[j]][lim1[j]+j] = '0';
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "NO" << '\n';
                return;
            }
        }
        for (int j = i; j > 0; --j) {
            lim2[j] = max({lim2[j-1], lim2[j]+1, lim2[j+1]+1});
            bool found = false;
            for (; lim2[j]+j < n; ++lim2[j]) {
                if (grid[lim2[j]+j][lim2[j]] == '1') {
                    ans[lim2[j]+j][lim2[j]] = '0';
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "NO" << '\n';
                return;
            }
        }
        lim1[0] = lim2[0] = max({lim1[0]+1, lim2[0]+1, lim1[1]+1, lim2[1]+1});
        bool found = false;
        for(; lim1[0] < n; ++lim1[0], ++lim2[0]) {
            if (grid[lim1[0]][lim1[0]] == '1') {
                ans[lim1[0]][lim1[0]] = '0';
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << '\n';
    }
}

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}