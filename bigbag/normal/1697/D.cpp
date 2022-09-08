/**
 *  created: 12/06/2022, 17:59:36
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int n, diff[max_n];

int get_diff(int l, int r) {
    cout << "? 2 " << l + 1 << " " << r + 1 << endl;
    int x;
    cin >> x;
    return x;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        diff[i] = get_diff(0, i);
    }
    string ans;
    vector<int> last(26, -1);
    for (int i = 0; i < n; ++i) {
        if (!i || diff[i] != diff[i - 1]) {
            cout << "? 1 " << i + 1 << endl;
            char c;
            cin >> c;
            ans += c;
        } else {
            vector<int> v;
            for (int j = 0; j < last.size(); ++j) {
                if (last[j] != -1) {
                    v.push_back(last[j]);
                }
            }
            sort(v.begin(), v.end());
            int l = 0, r = v.size();
            while (r - l > 1) {
                int mid = (l + r) / 2;
                int mask = 0;
                for (int j = v[mid]; j < i; ++j) {
                    mask |= 1 << (ans[j] - 'a');
                }
                int ok = 1 + __builtin_popcount(mask);
                if (get_diff(v[mid], i) == ok) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            ans += ans[v[l]];
        }
        last[ans[i] - 'a'] = i;
    }
    cout << "! " << ans << endl;
    return 0;
}