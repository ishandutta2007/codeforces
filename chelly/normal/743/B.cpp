#include<bits/stdc++.h>
using namespace std;
int main() {
	long long n, k;
	cin >> n >> k;
	int ans(1);
	while(k % 2 == 0) {
		k /= 2;
		ans++;
	}
	cout << ans << endl;
}