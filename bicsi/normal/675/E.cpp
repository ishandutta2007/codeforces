#include <bits/stdc++.h>

using namespace std;

int T[200005], MaxPos[200005], Ind[200005];
long long Ans[100005];
int n;

void update(int pos, int val) {
	for(;pos<=n;pos+=(pos&-pos))
		T[pos] = max(T[pos], val);
}
int query(int pos) {
	int ans = 0;
	for(;pos;pos-=(pos&-pos))
		ans = max(ans, T[pos]);
	return ans;
}

int main() {
	scanf("%d", &n);

	for(int i = 1; i < n; ++i) {
		scanf("%d", MaxPos + i);
	}
	update(n, n);
	Ind[n] = n;

	for(int i = n - 1; i >= 1; --i) {
		int next_pos = query(MaxPos[i]);
		int next_ind = Ind[next_pos];

		Ans[i] = (n - i) - (MaxPos[i] - next_ind);
		Ans[i] += Ans[next_ind];

		Ind[MaxPos[i]] = i;
		update(i, MaxPos[i]);
	}

	long long ans = 0;
	for(int i = n - 1; i > 0; --i) {
		//cerr << Ans[i] << " ";
		ans += Ans[i];
	}

	printf("%I64d", ans);
	return 0;
}