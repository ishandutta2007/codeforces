/*input
20 2 16
20 5 8 2 18 16 2 16 16 1 5 16 2 13 6 16 4 17 21 7
*/
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define int long long
#define maxn 100900
#define inf 0x3f3f3f3f

int n, d, m, x[maxn];
int a[maxn], apo;
int b[maxn], bpo;

// vector<int> a, b;

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> n >> d >> m;
    for (int i = 1; i <= n; ++ i) cin >> x[i];
    for (int i = 1; i <= n; ++ i) {
        if (x[i] <= m) a[apo++] = x[i];
        else b[bpo++] = x[i];
    }
    // for (int i = 0; i < apo; ++ i) cout << a[i] << " "; cout << endl;
    // for (int i = 0; i < bpo; ++ i) cout << b[i] << " "; cout << endl;
    sort(a, a + apo, greater<int>());
    sort(b, b + bpo, greater<int>());
    for (int i = 1; i < apo; ++ i) a[i] += a[i - 1];
    for (int i = 1; i < bpo; ++ i) b[i] += b[i - 1];
   // for (auto to : a) cout << to << " "; cout << endl;
   // for (auto to : b) cout << to << " "; cout << endl;
    int ans = 0;
    for (int i = 0; i <= apo; ++ i) {
        int now = 0;
        if (i) now += a[i - 1];
        int las = n - i;
        las = las / (d + 1) + (las % (d + 1) != 0);
        las = min(las, (int)bpo);
       // cout << "i = " << i << "las = " << las << "  " << b.size() << endl;
        if (las) now += b[las - 1];
        ans = max(ans, now);
    }
    cout << ans << "\n";
    return 0;
}