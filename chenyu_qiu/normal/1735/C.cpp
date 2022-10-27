#include <bits/stdc++.h>
using namespace std;

int par[26];
int find(int x) {
    return x == par[x] ? x : (par[x] = find(par[x]));
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> to(26, -1);
    vector<bool> tag(26);
    iota(par, par + 26, 0);
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        int x = s[i] - 'a';
        if (to[x] == -1) {
            for (int y = 0; y < 26; ++y) {
                if (!tag[y]) {
                    if (cnt == 25) {
                        to[x] = y;
                        tag[y] = true;
                        break;
                    } else {
                        if (find(x) != find(y)) {
                            to[x] = y;
                            tag[y] = true;
                            par[find(x)] = find(y);
                            break;
                        }
                    }
                }
            }       
            ++cnt;     
        }
        cout << char(to[x] + 'a');
    }
    cout << "\n";
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}