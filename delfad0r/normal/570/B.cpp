#include <bits/stdc++.h>

using namespace std;

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	if(N == 1) {
		cout << 1 << '\n';
		return 0;
	}
	if(M - 1 >= N - M) {
		cout << M - 1 << '\n';
	} else {
		cout << M + 1 << '\n';
	}
}