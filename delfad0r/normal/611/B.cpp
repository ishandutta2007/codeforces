#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull A, B;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> A >> B;
	int ans = 0;
	for(int p = 1; p <= 60; ++p) {
		for(int j = 0; j < p - 1; ++j) {
			ull n = (1ULL << p) - (1ULL << j) - 1;
			if(A <= n  && n <= B) ++ans;
		}
	}
	cout << ans;
}