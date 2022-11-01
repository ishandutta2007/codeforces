#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 111111;
const int MOD = 1e9 + 7;

int n;
vector<int> sons[N];
int color[N];
int f[N], g[N], last[N];

void dfs(int x) {
	for(int i = 0; i < (int)sons[x].size(); i++) {
		int y = sons[x][i];
		dfs(y);
	}
	
	f[x] = g[x] = 0;
	
	if (color[x] == 0) {
		int s = 1;
		for(int i = (int)sons[x].size() - 1; i >= 0; i--) {
			int y = sons[x][i];
			last[i] = s;
			s = 1LL * s * (f[y] + g[y]) % MOD;
		}
		
		g[x] = s;
		s = 1;
		for(int i = 0; i < (int)sons[x].size(); i++) {
			int y = sons[x][i];
			f[x] += 1LL * f[y] * s % MOD * last[i] % MOD;
			f[x] %= MOD;
			s = 1LL * s * (f[y] + g[y]) % MOD;
		}
	} else {
		f[x] = 1;
		for(int i = 0; i < (int)sons[x].size(); i++) {
			int y = sons[x][i];
			f[x] = 1LL * f[x] * (f[y] + g[y]) % MOD;
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int father;
		scanf("%d", &father);
		sons[father].push_back(i);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &color[i]);
	}	
	dfs(0);
	printf("%d", f[0]);
	return 0;
}