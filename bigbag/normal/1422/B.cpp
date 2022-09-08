#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 1011, inf = 1000111222;

int n, m, a[max_n][max_n];
long long ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--) {
        ans = 0;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < m / 2; ++j) {
                vector<int> v{a[i][j], a[n - 1 - i][j], a[i][m - 1 - j], a[n - 1 - i][m - 1 - j]};
                sort(v.begin(), v.end());
                int x = v[1];
                ans += x - v[0];
                ans += v[2] - x;
                ans += v[3] - x;
            }
        }
        if (n % 2) {
            for (int i = 0; i < m / 2; ++i) {
                vector<int> v{a[n / 2][i], a[n / 2][m - 1 - i]};
                int x = *min_element(v.begin(), v.end());
                ans += v[0] - x;
                ans += v[1] - x;
            }
        }
        if (m % 2) {
            for (int i = 0; i < n / 2; ++i) {
                vector<int> v{a[i][m / 2], a[n - 1 - i][m / 2]};
                int x = *min_element(v.begin(), v.end());
                ans += v[0] - x;
                ans += v[1] - x;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}