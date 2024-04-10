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
#define maxn 
#define inf 0x3f3f3f3f


int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	int t, l, r, a, b;
    cin >> t;
    while (t --) {
        cin >> l >> r >> a >> b;
        int ok = 0, v1 = 0, v2 = 0;
        for (int i = l; i <= r; ++ i) {
            if (ok) break;
            for (int j = a; j <= b; ++ j) {
                if (ok) break;
                if (i != j) {
                    ok = 1;
                    v1 = i, v2 = j;
                }
            }
        }
        cout << v1 << " " << v2 << "\n";
    }
    return 0;
}