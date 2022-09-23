#include <bits/stdc++.h>

using namespace std;

int N, K;

int A[505050];
int B[505050];

int lis(vector<int>& v) {
	vector<int> a;
	for(int i : v) {
		int t = upper_bound(a.begin(), a.end(), i) - a.begin();
		if(t == a.size()) a.push_back(i);
		else a[t] = i;
	}
	return a.size();
}

int main() {
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= K; i++) scanf("%d", &B[i]);

	for(int i = 1; i <= N; i++) A[i] += (N - i);

	for(int i = 2; i <= K; i++) {
		if(A[B[i - 1]] > A[B[i]]) {
			puts("-1"); return 0;
		}
	}

	vector<int> v;
	int ans = 0;
	B[K + 1] = N + 1;
	A[N + 1] = 2020202020;
	for(int i = 1; i < B[1]; i++) {
		if(A[i] <= A[B[1]]) {
			v.push_back(A[i]);
		}
		else ans++;
	}
	ans += (int)v.size() - lis(v);

	for(int i = 2; i <= K + 1; i++) {
		v.clear();
		for(int j = B[i - 1] + 1; j < B[i]; j++) {
			if(A[B[i - 1]] <= A[j] && A[j] <= A[B[i]]) {
				v.push_back(A[j]);
			}
			else ans++;
		}
		ans += (int)v.size() - lis(v);
	}
	printf("%d\n", ans);

	return 0;
}