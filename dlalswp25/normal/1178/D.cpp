#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

bool noprime[2020];
vector<pii> ans;

int main() {	
	for(int i = 2; i <= 2000; i++) {
		if(noprime[i]) continue;
		for(int j = i * i; j <= 2000; j += i) noprime[j] = true;
	}

	int N; scanf("%d", &N);
	for(int i = 1; i < N; i++) ans.push_back({i, i + 1});
	ans.push_back({N, 1});

	int c = 0;

	while(noprime[N + c]) {
		c++;
		ans.push_back({c, c + N / 2});
	}

	printf("%d\n", ans.size());
	for(pii i : ans) printf("%d %d\n", i.first, i.second);

	return 0;
}