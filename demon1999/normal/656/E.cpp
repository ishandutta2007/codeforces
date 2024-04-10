#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
const ll mod = 1e9 + 7, sz = 200;

ll dp[11][11], n, ans;

int fc3() {
    int x;
    cin >> x;
    return x;
}

int func2(int i, int j) {
    return i < n ? fc3() : 0;
}

int fc(int i, int j) {
    i += j / n;
    j %= n;
    dp[i][j] = func2(i, j);
    return i < n ? fc(i, j + 1) : 0;
}

int func(int k, int i, int j) {
    return k < n ? min(dp[i][j], dp[i][k] + dp[k][j]) : dp[i][j];
}

int fc1(int k, int i, int j) {
    i += j / n;
    j %= n;
    k += i / n;
    i %= n;
    dp[i][j] = func(k, i, j);
    return k < n ? fc1(k, i, j + 1) : 0;
}

int fc2(int i, int j) {
    i += j / n;
    j %= n;
    ans = i < n ? max(ans, dp[i][j]) : ans;
    return i < n ? fc2(i, j + 1) : 0;
}

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("matrix.in", "r",  stdin));
    //freopen("matrix.out", "w", stdout);
    cin >> n;
    fc(0, 0);
    fc1(0, 0, 0);
    fc2(0, 0);
    cout << ans;
    return 0;
}