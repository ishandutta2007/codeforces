// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 100090
#define inf 0x3f3f3f3f

int t, n, x[maxn];


int solve() {
    for (int b = 30; b >= 0; -- b) {
        int cnt = 0;
        for (int i = 1; i <= n; ++ i) if (x[i] & (1 << b)) cnt ++;
        if (cnt % 2 == 0);
        else {
            if ((cnt - 1) / 2 % 2 == 0) return 1;
            else {
                int zero = n - cnt;
//                cout << "zero = " << zero << endl;
                if (zero % 2 == 0) return -1;
                else return 1;
            }
        }
    }
    return 0;
}

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 1; i <= n; ++ i) cin >> x[i];
//        cout << (1 << 30) << endl;
//        for (int i = 30; i >= 0; -- i) {
//            
//        }
        int ans = solve();
        if (ans == -1) cout << "LOSE" << "\n";
        else if (ans == 0) cout << "DRAW" << "\n";
        else if (ans == 1) cout << "WIN" << "\n";
    }
    return 0;
}