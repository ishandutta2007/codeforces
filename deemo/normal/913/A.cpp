#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a, b;
	cin >> a >> b;
	a = min(a, 70ll);
	ll ans = 0;
	ll cur = 1;
	while (a--){
		if (b & 1)
			ans += cur;
		b >>= 1;
		cur <<= 1;
	}
	cout << ans << "\n";
	return 0;
}