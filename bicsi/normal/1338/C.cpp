#include <bits/stdc++.h>
#define int long long 

using namespace std;

int Rec(int n) {
	if (n == 0) return 0;
	int ans = Rec(n / 4) * 4;
	n %= 4;
	if (n == 0) return ans;
	if (n == 1) return ans + 2;
	if (n == 2) return ans + 3;
	if (n == 3) return ans + 1;
	assert(false);
}

int Solve(int n) { 
    --n;
    if (n < 6) {
      int ans[] = {1, 2, 3, 4, 8, 12, 5, 10, 15};
      return ans[n];
    }

		int n1 = n / 3; n1 -= 1;
		int no_bits_of_a = 2;
		while (n1 >= (1LL << no_bits_of_a)) {
			n1 -= (1LL << no_bits_of_a);
			no_bits_of_a += 2;
		}

		int a = (1LL << no_bits_of_a) + n1;
		int b = (1LL << (no_bits_of_a + 1)) + Rec(n1);
		int c = a ^ b;

		// cerr << n << ": " << a << " " << b << " " << c << endl;

		if (n % 3 == 0) return a;
		if (n % 3 == 1) return b;
		if (n % 3 == 2) return c;
    assert(false);
}
int32_t main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
	  cout << Solve(n) << '\n';
  }

	return 0;
}