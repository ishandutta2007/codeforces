#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, X;
vector<pii> ans;

void f(int n, int s) {
	if(n == 2) {
		ans.emplace_back(s, s + 1);
		return;
	}
	f(n / 2, s);
	f(n / 2, s + n / 2);
	for(int i = 0; i < n / 2; i++) {
		ans.emplace_back(s + i, s + n / 2 + i);
	}
}

int main() {
	scanf("%d", &N);
	if(N <= 2) { puts("0"); return 0; }
	X = 1;
	while(X * 2 < N) X *= 2;
	f(X, 1);
	printf("%d\n", 2 * ans.size());
	for(pii i : ans) printf("%d %d\n", i.first, i.second);
	int t = N - X;
	for(pii i : ans) printf("%d %d\n", i.first + t, i.second + t);
	return 0;
}