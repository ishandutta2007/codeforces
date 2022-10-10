#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define long long long
#define inf(type) (numeric_limits<type>::max())
vi a;

int main() {
    for (int i = 0; i <= 9; ++i) {
        cout << string(4, char(i + '0')) << endl;
        int u, v; cin >> u >> v;
        if (u == 4) return 0;
        for (int f = 0; f < v + u; ++f) a.push_back(i);
    }

    sort((a).begin(), (a).end());
    do {
        for (int i = 0; i < 4; ++i) cout << a[i];
        cout << endl;
        int u, v; cin >> u >> v;
        if (u == 4) break;
    } while (next_permutation((a).begin(), (a).end()));

    return 0;
}