#include <bits/stdc++.h>

using namespace std;

int N;
int in[505];
bool rem[505];

int query(int a, int b) {
	printf("? %d %d\n", a, b);
	fflush(stdout);
	char s[10];
	scanf("%s", s);
	if(s[0] == 'Y') return 1;
	return 0;
}

int main() {
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &in[i]);
	for(int i = 1; i <= N; i++) rem[i] = true;

	int M = N;
	for(int i = 1; i <= N; i++) {
		int j;
		for(j = 1; j <= N; j++) {
			if(!rem[j]) continue;
			if(in[j] == 0) {
				for(int k = 1; k <= N; k++) {
					if(!rem[k] || k == j) continue;
					in[k]--;
				}
				rem[j] = false;
				M--;
				break;
			}
			else if(in[j] == M - 1) {
				rem[j] = false; M--;
				break;
			}
		}
		if(j > N) break;
	}

	if(!M) { printf("! 0 0\n"); fflush(stdout); return 0; }

	vector<int> v;
	for(int i = 1; i <= N; i++) if(rem[i]) v.push_back(i);
	sort(v.begin(), v.end(), [&](const int a, const int b) {
		return in[a] < in[b];
	});

	M = v.size();
	for(int i = M - 1; i > 0; i--) {
		for(int j = 0; i + j < M; j++) {
			if(query(v[i + j], v[j])) {
				printf("! %d %d\n", v[i + j], v[j]);
				fflush(stdout);
				return 0;
			}
		}
	}

	return 0;
}