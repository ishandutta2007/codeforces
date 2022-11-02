/*input

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
#define maxn 10000
#define inf 0x3f3f3f3f

int t, n, x[maxn];

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 1; i <= n; ++ i) cin >> x[i];
        if (n == 1 && x[1] % 2 == 1) cout << "-1\n";
        else {
            if (x[1] % 2 == 0) cout << "1\n1\n";
            else if (x[2] % 2 == 0) cout << "1\n2\n";
            else cout << "2\n1 2\n";
        }
    }
    return 0;
}