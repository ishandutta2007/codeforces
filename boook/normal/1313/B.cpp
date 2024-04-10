/*input
2
5 5 5
6 3 4
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 
#define inf 0x3f3f3f3f
 
int t, n, a, b;
 
int32_t main(){
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> t;
    while (t --) {
        cin >> n >> a >> b;
        int total = a + b + 1 - n - 1;
        if (total <= 0) cout << 1 << " ";
        else cout << min(n, total + 1) << " ";
        cout << min(n, a + b - 1) << endl;
    }
    return 0;
}