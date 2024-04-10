// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 10000
#define inf 0x3f3f3f3f

int t, n, x[maxn];
int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> t;

    while (t --) {
        cin >> n;
        for (int i = 1; i <= n; ++ i) cin >> x[i];
        for (int i = 1; i <= n; ++ i) {
            if (i % 2 == 0) {
                x[i] = abs(x[i]);
            }
            else {
                x[i] = -abs(x[i]);
            }
        }
        for (int i = 1; i <= n; ++ i) cout << x[i] << " \n"[i == n];
    }
    return 0;
}