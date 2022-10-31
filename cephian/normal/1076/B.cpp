#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;



int main() {	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll x;
	cin >> x;
	ll d = 2;
	while(d*d <= x) {
		if(x%d == 0) break;
		++d;
	}
	if(x%d != 0) d = x;

	if(d == 2) cout << x/d << "\n";
	else cout << 1 + (x-d)/2 << "\n";
}