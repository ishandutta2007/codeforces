#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, k; cin >> n >> k;
	n = min(n, k-1);
	
	ll ans = 0;
	ll rem = k - n;
	if (0 < rem && rem <= n-1){
		ll cnt = (n - rem + 1);
		ans = cnt>>1;
	}
	cout << ans << endl;
	return 0;
}