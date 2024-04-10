#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <iterator>
#include <map>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	ll a = 1;
	ll n;
	cin >> n;
	for(ll i = 2; i <= n; ++i) {
		a += 12*(i-1);
	}
	cout << a << "\n";
	return 0;
}