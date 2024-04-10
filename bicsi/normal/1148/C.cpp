#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> perm(n), pos(n);
    for (int i = 0; i < n; ++i) {
        cin >> perm[i]; --perm[i];
        pos[perm[i]] = i;
    }

    vector<pair<int, int>> ops;
    auto Swap = [&](int i, int j) {
        // cerr << "Swap: " << i + 1 << " " << j + 1 << endl;
        if (i == j) return;
        if (i > j) swap(i, j);
        assert(abs(i - j) >= n / 2);
        pos[perm[i]] = j;
        pos[perm[j]] = i;
        swap(perm[i], perm[j]);
        ops.emplace_back(i, j);
    };
    
    int mid = n / 2;
    for (int i = 0, j = mid; i < mid; ++i, ++j) {
        if (pos[j] != j) {
            if (pos[j] < mid) 
                Swap(pos[j], n - 1);
            Swap(pos[j], i);
            Swap(pos[j], j);
        }
        if (pos[i] != i) {
            if (pos[i] < mid)
                Swap(pos[i], n - 1);
            Swap(pos[i], i);
        }
    
    }


    cout << ops.size() << endl;
    for (int i = 0; i < (int)ops.size(); ++i) {
        cout << ops[i].first + 1 << " " << ops[i].second + 1 << '\n';
    }
    return 0;
}