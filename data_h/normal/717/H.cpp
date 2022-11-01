#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N(55555);
const int M(1111111);
vector<int> adj[N], blg[N];
int ans[N], ass[M];
int main() {
	int n, e;
	scanf("%d%d", &n, &e);
	for(int i(0); i < e; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int t(0);
	for(int i(0); i < n; i++) {
		int x;
		scanf("%d", &x);
		for(int j(0); j < x; j++) {
			int y;
			scanf("%d", &y);
			y--;
			blg[i].push_back(y);
			t = max(t, y);
		}
	}
	for(;;) {
		for(int i(0); i <= t; i++) {
			ass[i] = rand() % 2;
		}
		bool flag(true);
		for(int i(0); i < n; i++) {
			int cnt[2] = {0, 0};
			for(int j(0); j < (int)blg[i].size(); j++) {
				cnt[ass[blg[i][j]]]++;
			}
			if(!cnt[0] || !cnt[1]) {
				flag = false;
				break;
			}
		}
		if(!flag) {
			continue;
		}
		for(int i(0); i < n; i++) {
			int cnt[2] = {0, 0};
			for(int j(0); j < (int)adj[i].size(); j++) {
				if(adj[i][j] <= i) {
					cnt[ass[ans[adj[i][j]]]]++;
				}
			}
			int d(cnt[0] < cnt[1] ? 0 : 1);
			for(int j(0); j < (int)blg[i].size(); j++) {
				if(ass[blg[i][j]] == d) {
					ans[i] = blg[i][j];
					break;
				}
			}
		}
		break;
	}
	for(int i(0); i < n; i++) {
		printf("%d%c", ans[i] + 1, i == n - 1 ? '\n' : ' ');
	}
	for(int i(0); i <= t; i++) {
		printf("%d%c", ass[i] + 1, i == t ? '\n' : ' ');
	}
}