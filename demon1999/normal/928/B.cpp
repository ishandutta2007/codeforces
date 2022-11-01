#include <bits/stdc++.h>  
 
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
#define prev previ
#define tm tmmm
#define div divv
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
 
int n, dp[200000], k;

int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    forn (i, n) {
        dp[i] = min(n - 1, i + k) - max(i - k, 0) + 1;
        int l = max(i - k, 0);
        int a;
        cin >> a;
        if (a > 0) {
            a--;
            dp[i] += dp[a] - max(min(a + k, n- 1) - l + 1, 0);
        }
        cout << dp[i] << " ";
    }

}