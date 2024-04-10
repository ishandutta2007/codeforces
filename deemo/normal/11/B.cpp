#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int main(){
	ll x, ans = 0;	cin >> x;
	x = abs(x);
	ll cur = 0, j = 1;
	while (cur < x)
		cur += j++, ans++;
	if ((cur - x) % 2 == 1){
		cur += j++, ans++;
		if ((cur - x) % 2)
			ans++;
	}
	cout << ans << "\n";
	return 0;
}