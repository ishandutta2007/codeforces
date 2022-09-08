/**
 *  created: 03/01/2022, 16:47:21
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 10111, inf = 1000111222;

int t, n, ans[max_n], used[max_n];

int ask(int i) {
    cout << "? " << i + 1 << endl;
    int res;
    cin >> res;
    --res;
    return res;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        memset(ans, -1, sizeof(ans));
        memset(used, 0, sizeof(used));
        for (int i = 0; i < n; ++i) {
            if (ans[i] == -1) {
                vector<int> v;
                while (true) {
                    int x = ask(i);
                    if (used[x]) {
                        break;
                    }
                    used[x] = 1;
                    v.push_back(x);
                }
                rotate(v.begin(), find(v.begin(), v.end(), i), v.end());
                rotate(v.begin(), v.begin() + 1, v.end());
                int pos = i;
                for (int x : v) {
                    ans[pos] = x;
                    pos = x;
                }
                if (0) {
                    for (int i = 0; i < n; ++i) {
                        cout << 1 + ans[i] << " ";
                    }
                    cout << endl;
                }
            }
        }
        cout << "!";
        for (int i = 0; i < n; ++i) {
            cout << " " << ans[i] + 1;
        }
        cout << endl;
    }
    return 0;
}