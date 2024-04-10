#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <vector>
#include <set>
#include <map>
#include <cstdio>

using namespace std;
typedef long long ll;


int n;
bool x[1000005]={0};

int main() {
	ios::sync_with_stdio(0);
	int ans = 0;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		ans ^= p;
	}
	for(int i = 2; i <= n; ++i) {
		bool fp = ((n+1)/i)&1;
		x[0] ^= fp;
		x[i] ^= fp;
		x[0] ^= 1;
		x[(n+1)%i] ^= 1;
	}
	for(int i = 1; i <= n; ++i) {
		x[i] ^= x[i-1];
		ans ^= x[i]*i;
	}
	cout << ans << "\n";
	return 0;
}