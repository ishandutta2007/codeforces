#include <bits/stdc++.h>

using namespace std;

int A[4];

int main()
{
	int T;
	for (cin >> T; T--;) {
		int ans = 0;
		for (int i = 0; i < 4; i++) cin >> A[i];
		sort(A, A + 4);
		do {
			ans = max(ans, min(A[0], A[2]) * min(A[1], A[3]));
		} while (next_permutation(A + 1, A + 4));
		cout << ans << '\n';
	}
	return 0;
}