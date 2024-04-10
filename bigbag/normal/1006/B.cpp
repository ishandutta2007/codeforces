#include <bits/stdc++.h>

using namespace std;

const int max_n = 2222, inf = 1000111222;

int n, k;
pair<int, int> p[max_n];
vector<int> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p, p + n);
    reverse(p, p + n);
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += p[i].first;
        ans.push_back(p[i].second);
    }
    sort(ans.begin(), ans.end());
    cout << sum << "\n";
    sum = -1;
    ans[ans.size() - 1] = n - 1;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] - sum << " ";
        sum = ans[i];
    }
    cout << "\n";
    return 0;
}