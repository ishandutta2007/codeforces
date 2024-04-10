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

int t, n;

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> t;
    while (t --) {
        cin >> n;
        if (n < 4) cout << 4 - n << "\n";
        else cout << (n & 1) << "\n";
    }
    return 0;
}