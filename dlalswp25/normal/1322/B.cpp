#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[404040];

vector<int> v0, v1;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

	int ans = 0;

	for(int b = 24; b >= 0; b--) {
		int x = (1 << (b + 1));
		int y = (1 << b);
		for(int i = 1; i <= N; i++) {
			if(A[i] >= x) A[i] -= x;
			if(A[i] & y) v1.push_back(A[i] - y);
			else v0.push_back(A[i]);
		}

		sort(v0.begin(), v0.end());
		sort(v1.begin(), v1.end());

		// printf("b %d\n", b);
		// for(int i : v0) printf("%d ", i); puts("");
		// for(int i : v1) printf("%d ", i); puts("");

		ll cnt = 0;
		ll tmp = 0;
		for(int i = 0; i < v0.size(); i++) {
			int idx = lower_bound(v0.begin(), v0.end(), y - v0[i]) - v0.begin();
			int num = (int)v0.size() - idx;
			tmp += num;

			if(v0[i] * 2 >= y) tmp--;
		}
		tmp /= 2;
		cnt += tmp;

		tmp = 0;
		for(int i = 0; i < v1.size(); i++) {
			int idx = lower_bound(v1.begin(), v1.end(), y - v1[i]) - v1.begin();
			int num = (int)v1.size() - idx;
			tmp += num;

			if(v1[i] * 2 >= y) tmp--;
		}
		tmp /= 2;
		cnt += tmp;

		for(int i = 0; i < v1.size(); i++) {
			int idx = lower_bound(v0.begin(), v0.end(), y - v1[i]) - v0.begin();
			cnt = (cnt + idx);
		}
		if(cnt & 1) ans |= y;

		v0.clear(); v1.clear();
	}
	printf("%d\n", ans);

	return 0;
}