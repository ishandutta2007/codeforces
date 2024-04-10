#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    vector<int> ans[2];
    ans[0].resize(n);
    ans[1].resize(n);
    ans[0][0] = 1;
    ans[1][0] = 0;
    for (int i = 1; i < n; ++i) {
        ans[0][i] = max(ans[0][i - 1], ans[1][i - 1]);
        if (a[i].first - a[i].second > a[i - 1].first) {
            ans[0][i] = max(ans[0][i], 1 + ans[0][i - 1]);
            if (a[i].first - a[i].second > a[i - 1].first + a[i - 1].second) {
                ans[0][i] = max(ans[0][i], 1 + ans[1][i - 1]);
            }
        }
        ans[1][i] = max(ans[0][i - 1], ans[1][i - 1]);
        if (i == n - 1 || a[i].first + a[i].second < a[i + 1].first) {
            ++ans[1][i];
        }
    }
    cout << max(ans[0][n - 1], ans[1][n - 1]) << endl;
    return 0;
}