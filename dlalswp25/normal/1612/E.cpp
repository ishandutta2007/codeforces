#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MX = 200000;

int N;
int M[202020];
int K[202020];
pii A[202020];
vector<int> ans;
ll x, y = 1;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d%d", &M[i], &K[i]);
	for(int i = 1; i <= 20; i++) {
		for(int j = 1; j <= MX; j++) A[j] = {0, j};
		for(int j = 1; j <= N; j++) A[M[j]].first += min(K[j], i);
		sort(A + 1, A + MX + 1); reverse(A + 1, A + MX + 1);
		ll s = 0;
		for(int j = 1; j <= i; j++) s += A[j].first;
		if(x * i < y * s) {
			x = s; y = i;
			ans.clear();
			for(int j = 1; j <= i; j++) ans.push_back(A[j].second);
		}
	}
	printf("%d\n", ans.size());
	for(int i : ans) printf("%d ", i); puts("");

	return 0;
}