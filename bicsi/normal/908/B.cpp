#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<string> mat(n);
    for (int i = 0; i < n; ++i) {
        cin >> mat[i];
    }

    auto bad = [&](int i, int j) {
        if (i < 0 or i >= n) return false;
        if (j < 0 or j >= m) return false;
        if (mat[i][j] == '#') return false;
        return true;
    };

    vector<int> id = {0, 1, 2, 3};
    
    int si, sj;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (mat[i][j] == 'S')
                si = i, sj = j;

    string dirs; cin >> dirs;

    int ans = 0;
    do {
        int i = si, j = sj;
        bool flag = false;
        
        for (auto d : dirs) {
            d = id[d - '0'];
            i += dx[d]; j += dy[d];
            
            if (!bad(i, j)) { break; }
            if (mat[i][j] == 'E') { flag = true; break; }
        }

        if (flag) {
            ans += 1;
        }
    } while (next_permutation(id.begin(), id.end()));
    cout << ans << endl;

    return 0;
}