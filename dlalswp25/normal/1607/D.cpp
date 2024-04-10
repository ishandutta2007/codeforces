#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];
char C[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		scanf("%s", C + 1);
		bool ok = true;

		vector<int> v;
		for(int i = 1; i <= N; i++) {
			if(C[i] == 'B') v.push_back(A[i]);
		}
		sort(v.begin(), v.end());
		int p = 0;
		for(int i = 0; i <= N; i++) {
			while(p < v.size() && v[p] <= i) p++;
			if(p > i) ok = false;
		}

		v.clear();
		for(int i = 1; i <= N; i++) {
			if(C[i] == 'R') v.push_back(A[i]);
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		p = 0;
		for(int i = N + 1; i >= 1; i--) {
			while(p < v.size() && v[p] >= i) p++;
			if(p > N + 1 - i) ok = false;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}