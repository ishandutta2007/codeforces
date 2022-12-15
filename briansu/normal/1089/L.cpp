#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

pll arr[100005];
int cnt[100005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i].Y, ++cnt[arr[i].Y];
    for (int i = 1; i <= n; ++i)
        cin >> arr[i].X;
    sort(arr + 1, arr + n + 1);
    int num = 0;
    for (int i = 1; i <= k; ++i)
        num += (cnt[i] >= 1);
    for (int i = 1; i <= n; ++i)
        if (cnt[arr[i].Y] > 1 && num < k)
            ans += arr[i].X, --cnt[arr[i].Y], ++num;
    cout << ans << "\n";
}