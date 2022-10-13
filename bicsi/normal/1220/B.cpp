#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
using int128 = long long;

int Solve3(int ab, int bc, int ac) {
    for (int d = 1; d < 1e5; ++d) {
        for (auto a : {d, ab / d}) {
            if (a == 0) continue;
            if (ab % a) continue;
            int b = ab / a;
            if (ac % a) continue;
            int c = ac / a;

            if (1LL * a * b == ab && 1LL * a * c == ac && 1LL * b * c == bc)
                return a;
        }
    }
    assert(false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> m[i][j];
        }
    }

    vector<int> sol(n);
    sol[0] = Solve3(m[0][1], m[1][2], m[0][2]);
    for (int i = 1; i < n; ++i) {
        sol[i] = m[i][i - 1] / sol[i - 1];
    } 
    for (int i = 0; i < n; ++i)
        cout << sol[i] << " ";
    cout << endl;
    
    return 0;
}