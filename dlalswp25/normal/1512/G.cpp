#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MX = 10000000;

ll X[10101010];
ll Y[10101010];
vector<int> primes;

int ans[10101010];

int main() {
	X[1] = Y[1] = 1;
	for(int i = 2; i <= MX; i++) {
		if(!X[i]) { primes.push_back(i); X[i] = Y[i] = i + 1; }
		for(int j : primes) {
			if((ll)i * j > MX) break;
			if(i % j == 0) {
				Y[i * j] = Y[i] * j + 1;
				X[i * j] = X[i] / Y[i] * Y[i * j];
				break;
			}
			else {
				X[i * j] = X[i] * X[j];
				Y[i * j] = Y[j];
			}
		}
	}

	for(int i = 1; i <= MX; i++) {
		if(X[i] > MX) continue;
		if(!ans[X[i]]) ans[X[i]] = i;
	}

	int tc; scanf("%d", &tc);
	while(tc--) {
		int c; scanf("%d", &c);
		if(!ans[c]) puts("-1");
		else printf("%d\n", ans[c]);
	}
	return 0;
}