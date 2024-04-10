#include <bits/stdc++.h>
using namespace std;

int Calc(const vector<int>& a)
{
    int ans = 0;
    int cans = 0;
    for (int i = 0; i < (int) a.size(); ++i) {
        if (a[i] == 0) {
            cans = 0;
        } else {
            ++cans;
        }
        ans = max(ans, cans);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int> > a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = Calc(a[i]);
    }
    for (; q; --q) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        a[x][y] = 1 - a[x][y];
        ans[x] = Calc(a[x]);
        int gl_ans = ans[0];
        for (int i = 1; i < n; ++i) {
            gl_ans = max(gl_ans, ans[i]);
        }
        cout << gl_ans << endl;
    }
    
    return 0;
}