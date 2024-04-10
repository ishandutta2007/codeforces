#include <bits/stdc++.h>
using namespace std;
#define int long long

int t, n;

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
    cin >> t;
    while (t --) {
        cin >> n;
        int ok = 0;
        while (n % 2 == 0) n /= 2;
        if (n != 1) ok = 1;
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}