#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int dsum(ll x) {
	int a = 0;
	while(x) {
		a += x%10;
		x /= 10;
	}
	return a;
}

int main() {
	fio;
	ll a, x = 0;
	cin >> a;
	while(x*10+9 <= a)
		x = x*10+9;
	cout << dsum(x) + dsum(a-x) << "\n";
}