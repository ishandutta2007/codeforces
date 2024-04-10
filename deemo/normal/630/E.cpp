#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int main(){
	ll a, b, c, d;	cin >> a >> b >> c >> d;
	ll aa = abs(d - b)/2LL + 1;
	ll bb = aa - 1;
	
	ll ans = ll((c - a)/ 2 + 1) * aa;
	ans += ll((c - a)/ 2) * bb;
	cout << ans << "\n";
	return	0;
}