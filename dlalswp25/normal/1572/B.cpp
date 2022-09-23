#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];
vector<int> ans;

void work(int i) {
	ans.push_back(i);
	int x = A[i] ^ A[i + 1] ^ A[i + 2];
	A[i] = A[i + 1] = A[i + 2] = x;
}

void go_left(int x) {
	if(x < 3) return;
	int cnt = A[x] + A[x - 1] + A[x - 2];
	if(cnt == 2) work(x - 2);
	else if(cnt == 1 && A[x]) {
		assert(x > 1);
		work(x - 2); work(x - 1);
	}
	go_left(x - 1);
}

void go_right(int x) {
	if(x > N - 2) return;
	int cnt = A[x] + A[x + 1] + A[x + 2];
	if(cnt == 2) work(x);
	else if(cnt == 1 && A[x]) {
		work(x); work(x - 1);
	}
	go_right(x + 1);
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		int tot = 0;
		ans.clear();
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			tot += A[i];
		}
		if(tot & 1) { puts("NO"); continue; }
		int last1 = 0;
		int cnt = 0;
		bool ok = false;
		for(int i = 1; i <= N; i++) {
			if(!A[i]) {
				if(cnt % 2 == 0) {
					go_left(i); go_right(i);
					ok = true; break;
				}
			}
			if(A[i]) {
				if(last1 && (i - last1) % 2 == 0) {
					for(int j = last1; j < i; j += 2) {
						work(j);
					}
					go_left(i); go_right(i);
					ok = true; break;
				}
				last1 = i;
				cnt++;
			}
		}

		if(!ok) { puts("NO"); continue; }
		puts("YES");
		printf("%d\n", ans.size());
		for(int i : ans) printf("%d ", i); puts("");
	}
	return 0;
}