#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[105];
ll F[50];
bool ans;

void f(int m, multiset<int>& S, int x) {
	if(m < 0) { ans = true; return; }
	if(ans || !S.size()) return;
	auto tmp = S;
	auto it = prev(S.end());
	int y = *it;
	if(F[m] > y) return;
	S.erase(it);
	if(x) S.insert(x);
	f(m - 1, S, y - F[m]);
	if(ans) { S = tmp; return; }
	if(x) S.erase(S.find(x));

	if(S.size()) {
		it = prev(S.end());
		int z = *it;
		if(F[m] > z) { S = tmp; return; }
		S.erase(it);
		S.insert(y);
		if(x) S.insert(x);
		f(m - 1, S, z - F[m]);
		if(x) S.erase(S.find(x));
		S.insert(z);
	}
	S = tmp;
}

int main() {
	F[0] = F[1] = 1;
	for(int i = 2; i < 50; i++) F[i] = F[i - 1] + F[i - 2];
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		if(N > 44) { puts("NO"); continue; }
		ll s = 0;
		for(int i = 1; i <= N; i++) s += A[i];
		int M = -1;
		for(int i = 49; i >= 0; i--) {
			if(s == F[i] - 1) { M = i - 2; break; }
		}
		if(M == -1) { puts("NO"); continue; }
		multiset<int> S;
		for(int i = 1; i <= N; i++) S.insert(A[i]);
		ans = false;
		f(M, S, 0);
		puts(ans ? "YES" : "NO");
	}
	return 0;
}