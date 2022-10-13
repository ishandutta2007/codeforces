#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<string> mat(n);
    for (int i = 0; i < n; ++i) {
        cin >> mat[i];
    }

    vector<vector<int>> cnt(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool ok_hor = true, ok_ver = (m >= 2);
            for (int k = 0; k < m; ++k) {
                ok_hor &= (j + k < n && mat[i][j + k] == '.'); 
                ok_ver &= (i + k < n && mat[i + k][j] == '.');   
            }
            if (ok_hor) for (int k = 0; k < m; ++k) cnt[i][j + k] += 1;
            if (ok_ver) for (int k = 0; k < m; ++k) cnt[i + k][j] += 1;
        }
    }

    tuple<int, int, int> ans = {0, 1, 1};

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ans = max(ans, make_tuple(cnt[i][j], i + 1, j + 1));
    
    cerr << get<0>(ans) << endl;
    cout << get<1>(ans) << " " << get<2>(ans) << endl;

    return 0;
}