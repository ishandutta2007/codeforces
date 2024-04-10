#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int n, k;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    if (k >= n / 2) {
        cout << 1 << endl << n / 2 + 1 << endl;
        return 0;
    }
    vector<int> ans;
    for (int i = k + 1; i <= n; i += 2 * k + 1) {
        ans.push_back(i);
    }
    if (ans.back() + k < n) {
        int last = ans.back() + 2 * k + 1;
        int sd = last - n;
        for (int i = 0; i < ans.size(); ++i) {
            ans[i] -= sd;
        }
        ans.push_back(last - sd);
    }
    cout << ans.size() << endl;
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}