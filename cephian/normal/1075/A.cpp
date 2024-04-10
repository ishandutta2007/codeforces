#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	ll n, x, y;
	cin >> n >> x >> y;
	if(max(abs(x-1), abs(y-1)) <= max(abs(x-n), abs(y-n)))
		cout << "White\n";
	else cout << "Black\n";
}