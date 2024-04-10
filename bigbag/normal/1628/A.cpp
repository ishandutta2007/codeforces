/**
 *  created: 22/01/2022, 16:36:27
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, a[max_n], last[max_n], suf[max_n];
int curt;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        int x = 0;
        ++curt;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            last[a[i]] = curt;
            while (last[x] == curt) {
                ++x;
            }
            suf[i] = x;
        }
        vector<int> ans;
        for (int i = 0; i < n; ) {
            ++curt;
            int need = suf[i], x = 0;
            do {
                //cout << i << " " << x << " " << need << endl;
                last[a[i]] = curt;
                while (last[x] == curt) {
                    ++x;
                }
                ++i;
            } while (x != need);
            ans.push_back(need);
        }
        cout << ans.size() << "\n";
        for (int x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}