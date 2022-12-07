#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
const int M = 1000000007;

int T;
int n;
int a[11];

bool dfs(int x, int i, int sum) {
    if (i == n) {
        if (sum == a[x])
            return 1;
        else
            return 0;
    }
    if (x == i) return dfs(x, i + 1, sum);
    return dfs(x, i + 1, sum) || dfs(x, i + 1, sum + a[i]) || dfs(x, i + 1, sum - a[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        bool ok = 0;
        for (int i = 0; i < n && !ok; ++i) {
            if (a[i] == 0 || dfs(i, 0, 0)) ok = 1;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}