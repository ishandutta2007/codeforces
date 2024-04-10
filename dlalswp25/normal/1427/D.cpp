#include <bits/stdc++.h>

using namespace std;

int N;
int A[55];
int B[55];
int pos[55];
vector<vector<int> > ans;

void query(vector<int> v) {
	// for(int i : v) printf("%d ", i); puts("");

	ans.push_back(v);
	int s = 0;
	for(int i : v) {
		int idx = N - s - i;
		for(int j = 1; j <= i; j++) B[idx + j] = A[s + j];
		s += i;
	}
	for(int i = 1; i <= N; i++) A[i] = B[i];
	// for(int i = 1; i <= N; i++) printf("%d ", A[i]); puts("");
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

	while(1) {
		bool ok = true;
		for(int i = 1; i <= N; i++) {
			if(A[i] != i) ok = false;
			pos[A[i]] = i;
		}
		if(ok) break;
		int j;
		for(int i = 1; i < N; i++) {
			if(pos[i] > pos[i + 1]) { j = i; break; }
		}
		int i;
		for(i = pos[j + 1]; ; i++) {
			if(A[i] + 1 != A[i + 1]) break;
		}
		vector<int> v;
		if(pos[j + 1] > 1) v.push_back(pos[j + 1] - 1);
		v.push_back(i - pos[j + 1] + 1);
		v.push_back(pos[j] - i);
		if(pos[j] < N) v.push_back(N - pos[j]);
		query(v);
	}

	printf("%d\n", ans.size());
	for(auto& v : ans) {
		printf("%d ", v.size());
		for(int i : v) printf("%d ", i); puts("");
	}

	return 0;
}