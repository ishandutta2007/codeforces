#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int tot = a[0], sum = a[0];
    vector<int> ans;
    ans.push_back(0);
    for (int i = 1; i < n; ++i) {
        if (a[0] >= 2 * a[i]) {
            tot += a[i];
            ans.push_back(i);
        }
        sum += a[i];
    }
    if (2 * tot > sum) {
        cout << ans.size() << endl;
        for (int id : ans) {
            cout << id + 1 << " ";
        }
    } else {
        cout << 0 << endl;
    }
    return 0;
}