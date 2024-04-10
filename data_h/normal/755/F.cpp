#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <cassert>
using namespace std;

const int N = 1e6 + 7;

int n, k;
int p[N], f[N];
map<int, int> cycle_cnt;

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	vector<int> c;
	static int visit[N];
	fill(visit + 1, visit + n + 1, 0);
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			int x = i, cnt = 0;
			while (!visit[x]) {
				cnt++;
				visit[x] = 1;
				x = p[x];
			}
			c.push_back(cnt);
			cycle_cnt[cnt]++;
		}
	}
	int ans_min = 0, ans_max = 0;
	//min
	fill(f, f + n + 1, 0);
	f[0] = 1;
	int s = 0;
	for (auto e : cycle_cnt) {
		int len = e.first, cnt = e.second;
		for (int i = s; i >= 0; i--) {
			if (!f[i]) continue;
			for (int j = 1; j <= cnt; j++) {
				if (f[i + j * len]) break;
				f[i + j * len] = 1;
			}
		}
		s += len * cnt;
	}
	ans_min = k + (f[k] ? 0 : 1);
	//max
	int kk = k;
	int remain = 0;
	for (auto cc : c) {
		while (kk && cc >= 2) {
			ans_max += 2;
			cc -= 2;
			kk--;
		}
		remain += cc;
	}
	ans_max += min(remain, kk);
	printf("%d %d\n", ans_min, ans_max);
}