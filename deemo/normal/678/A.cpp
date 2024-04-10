#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int main(){
	ll n, k;	cin >> n >> k;
	ll ans = n % k;
	ans = (k - ans) % k;
	ans += n;
	if (ans == n)
		ans += k;
	cout << ans << endl;
	return 0;	
}