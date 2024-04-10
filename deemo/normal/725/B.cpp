#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll x;	cin >> x;
	char c;	cin >> c;
	ll ans = 0;
	ans += (x-1)/4 * 16ll;
	if (x % 4 == 2 || x % 4 == 0)	ans += 7;
	if (c == 'f')	ans++;
	if (c == 'e')	ans += 2;
	if (c == 'd')	ans += 3;
	if (c == 'a')	ans += 4;
	if (c == 'b')	ans += 5;
	if (c == 'c')	ans += 6;
	cout << ans << endl;
	return 0;
}