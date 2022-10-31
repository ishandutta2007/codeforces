#include <iostream>
using namespace std;

int main() {
	int T; cin >> T; while(T--) {
		long long n;
		cin >> n;
		long long ans = n * (n + 1) / 2;
		for(long long i = 1; i <= n; i += i)
			ans -= i + i;
		cout << ans << endl;
	}
	return 0;
}