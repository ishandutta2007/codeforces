#include <bits/stdc++.h>

using namespace std;

const int max_n = 55, max_x = 1111;

int n, a[max_n], used[max_x];
vector<int> ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        used[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        if (used[a[i]] == i) {
            ans.push_back(a[i]);
        }
    }
    cout << ans.size() << endl;
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}