#include <bits/stdc++.h>
using namespace std;

void ShowPath(int x, int y)
{
    cout << "(1,1) ";
    for (int i = 0, j = 0; i != x || j != y; ) {
        if (i < x) {
            ++i;
        } else {
            ++j;
        }
        cout << "(" << i + 1 << "," << j + 1 << ") ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<pair<int, int> > > d(n + m - 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            d[i + j].push_back(make_pair(i, j));
        }
    }
    
    int ans = k;
    int max_dist = 0;
    while (true) {
        if (k > d[max_dist].size()) {
            k -= d[max_dist].size();
            ++max_dist;
        } else {
            break;
        }
    }
    ans += k * max_dist;
    for (int i = 0; i < max_dist; ++i) {
        ans += d[i].size() * i;
    }
    cout << ans << endl;
    for (int i = 0; i < k; ++i) {
        ShowPath(d[max_dist][i].first, d[max_dist][i].second);
    }
    for (int i = max_dist - 1; i >= 0; --i) {
        for (int j = 0; j < (int) d[i].size(); ++j) {
            ShowPath(d[i][j].first, d[i][j].second);
        }
    }
    
    
    return 0;
}