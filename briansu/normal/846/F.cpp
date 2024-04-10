#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int lst[1123456];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (lst[x] == 0)
            ans += 2LL * i * (n - i + 1);
        else
            ans += 2LL * (i - lst[x]) * (n - i + 1);
        lst[x] = i;
        ans -= 1;
    }
    cout << fixed << setprecision(12) << (double)ans / (double)n / (double)n << endl;
}