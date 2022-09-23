#include <bits/stdc++.h>

using namespace std;

int ans;
int A[2020];
int N;

vector<int> v;

bool chk[2020];

int main() {
	ans = 987654321;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) { scanf("%d", &A[i]); v.push_back(A[i]); }
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for(int i = 1; i <= N; i++) A[i] = lower_bound(v.begin(), v.end(), A[i]) - v.begin() + 1;

	for(int i = 0; i <= N; i++) {
		for(int j = 1; j <= N; j++) chk[j] = false;
		bool ok = true;
		for(int j = 1; j <= i; j++) {
			if(chk[A[j]]) {
				ok = false; break;
			}
			chk[A[j]] = true;
		}
		if(!ok) break;
		for(int j = N; j >= 1; j--) {
			if(chk[A[j]]) {
				ans = min(ans, j - i);
				break;
			}
			chk[A[j]] = true;
		}
	}
	printf("%d\n", ans);

	return 0;
}