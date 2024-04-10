#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define SZ(a) ((int)a.size())

const int C = 4000;
int arr[2005], tmp[2005];

int solve(int n, int st) {
    int ans = 0;
    while (!is_sorted(tmp + 1, tmp + n + n + 1)) {
        if (st == 0) {
            for (int i = 1; i < n + n; i += 2)
                swap(tmp[i], tmp[i + 1]);
        }
        else {
            for (int i = 1; i <= n; ++i)
                swap(tmp[i], tmp[i + n]);
        }
        st ^= 1;
        ++ans;
        if (ans >= C) return C;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n + n; ++i)
        cin >> arr[i];

    copy(arr + 1, arr + n + n + 1, tmp + 1);
    int ans = solve(n, 0);
    copy(arr + 1, arr + n + n + 1, tmp + 1);
    ans = min(ans, solve(n, 1));
    if (ans >= C)
        cout << "-1\n";
    else
        cout << ans << "\n";
}