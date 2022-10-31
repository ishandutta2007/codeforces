#include <bits/stdc++.h>

#define ll long long
#define ld  long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 1000 + 9, mod = 998244353;
int a[N][N], b[N][N];
int n;

void add(int i, int j) {
    if (i < 1 || i > n || j < 1 || j > n)return;
    b[i][j]++;
}

void dfs(int i, int j) {
    add(i + 1, j);
    add(i - 1, j);
    add(i, j + 1);
    add(i, j - 1);
}

void doWork() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            b[i][j] = 0;
        }
    }
    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (b[i - 1][j] % 2 == 0) {
                dfs(i, j);
                ans ^= a[i][j];
            }
        }
    }
    cout << ans << "\n";
}


int main() {
    IO
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        //  cout << "Case #" << i << ": ";
        doWork();
    }
    return 0;
}