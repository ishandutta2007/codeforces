#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 0; i * a <= n; i += 1) {
        if ((n - a * i) % b == 0) {
            vector<int> ret(n);
            cerr << i << " " << (n - a * i) / b << endl;

            for (int i = 0; i < n; ++i) {
                ret[i] = i + 1;
            }

            for (int j = 0; j < i; ++j) {
                ret[a * j + a - 1] = a * j;
            }
            for (int j = 0; j < (n - a * i) / b; ++j) {
                ret[n - b * j - 1] = n - b * j - b;
            }

            for (int i = 0; i < n; ++i) {
                cout << ret[i] + 1 << " ";
            }
            cout << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}