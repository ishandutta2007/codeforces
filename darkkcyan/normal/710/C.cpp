#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define log clog << __LINE__ << ": "
#define _ << ' ' <<
#endif

#define long long long
#define ii pair<int, int>
#define ve vector
#define sz(v) ((int) v.size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define xx first
#define yy second
#define pb push_back

int n;
ve<ve<int>> ans;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    cin >> n;
    ans.resize(n, ve<int>(n, 0));

    for (int i = 0, k = n - 1, f = n / 2, g = n / 2; i <= k; ++i, --k, --f, ++g) {
        for (int l = f; l <= g; ++l) {
            ans[i][l] = ans[k][l] = 1;
        }
    }

    int ce = 2;
    int co = 1;

    for (int i = 0; i < n; ++i) {
        for (int f = 0; f < n; ++f) {
            if (ans[i][f]) {
                cout << co << ' ';
                co += 2;
            } else {
                cout << ce << ' ';
                ce += 2;
            }
        }
        cout << '\n';
    }

    return 0;
}