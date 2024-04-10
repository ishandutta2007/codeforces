#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll a,b;
		cin >> a >> b;
		if(a < b) swap(a,b);
		int ans = 0;
		while(true) {
			if(a == b) break;
			++ans;
			if(a >= 8*b && a%8 == 0) a /= 8;
			else if(a >= 4*b && a%4 == 0) a /= 4;
			else if(a >= 2*b && a%2 == 0) a /= 2;
			else {
				ans = -1;
				break;
			}
		}
		cout << ans << '\n';
	}
}