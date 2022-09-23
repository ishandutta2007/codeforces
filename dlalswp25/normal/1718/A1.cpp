#include <bits/stdc++.h>

using namespace std;

int N;
int A[101010];
int D[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		map<int, int> mp;
		mp[0] = 0;
		int s = 0;
		for(int i = 1; i <= N; i++) {
			s ^= A[i];
			D[i] = D[i - 1];
			if(mp.find(s) != mp.end()) D[i] = max(D[i], D[mp[s]] + 1);
			mp[s] = i;
		}
		printf("%d\n", N - D[N]);
	}
	return 0;
}