#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> V(n);
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
    }

    string can; cin >> can;

    vector<int> left(n, -1);
    for (int i = 1; i < n; ++i) {
        left[i] = i - 1;
        if (can[i - 1] == '1') 
            left[i] = left[i - 1];
    }

    for (int i = n - 1; i != -1; i = left[i]) {
        sort(V.begin() + left[i] + 1, V.begin() + i + 1);
    }

    if (is_sorted(V.begin(), V.end())) {
        cout << "YES\n";        
    } else {
        cout << "NO\n";
    }

    return 0;
}