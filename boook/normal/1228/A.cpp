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

int l, r;

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	
	cin >> l >> r;
	
	for (int i = l; i <= r; ++ i) {
		map<int, int> cc;
		int now = i, ok = 1;
		while (now) cc[now % 10] ++, now /= 10;
		for (auto to : cc) if (to.second > 1) ok = 0;
		if (ok == 1) {
			cout << i << "\n";
			return 0;
		}
	}
	cout << -1 << "\n";
    return 0;
}