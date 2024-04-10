#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
vector<int> v[505050];
int other[1010101];
bool chk[1010101];

vector<int> ans;

int main() {
	scanf("%d", &N);
	if(N & 1) {
		puts("Second"); fflush(stdout);
		for(int i = 1; i <= 2 * N; i++) {
			int x; scanf("%d", &x);
			v[x].push_back(i);
		}
		for(int i = 1; i <= N; i++) {
			other[v[i][0]] = v[i][1];
			other[v[i][1]] = v[i][0];
		}

		ll s = 0;
		for(int i = 1; i <= N; i++) {
			if(chk[i] || chk[N + i]) continue;
			int x = i;
			chk[i] = true;
			while(1) {
				ans.push_back(x);
				s += x;
				int t = other[x];
				if(t > N) t -= N;
				else t += N;

				int y = (t > N ? t - N : t);
				if(chk[y] || chk[y + N]) break;
				x = t;
				chk[t] = true;
			}
		}

		if(s % (2 * N)) {
			for(int i : ans) printf("%d ", i > N ? i - N : i + N); puts("");
		}
		else {
			for(int i : ans) printf("%d " , i); puts("");
		}
		fflush(stdout);
	}
	else {
		puts("First"); fflush(stdout);
		for(int i = 1; i <= 2 * N; i++) printf("%d ", i > N ? i - N : i); puts("");
		fflush(stdout);
	}
	return 0;
}