#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n, k, a[max_n];
vector<int> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    set<int> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (!q.count(a[i]) && ans.size() < k) {
            q.insert(a[i]);
            ans.push_back(i + 1);
        }
    }
    if (ans.size() < k) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i : ans) {
            cout << i << " ";
        }
    }
    return 0;
}