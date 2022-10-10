#include <iostream>
#include <cmath>
using namespace std;

#define ll long long 
int main() {
	ll n, k; cin >> n >> k;
	ll sum = 0;
	int a;
	for (int i = 0; i < n; ++i) cin >> a, sum += a;
	cout << (((ll) abs(sum) + k - 1) / k);
	return 0;
}