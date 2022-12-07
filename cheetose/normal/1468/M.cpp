#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;


vector<int>L[121212];
int allNum[212121], an;
vector<pair<int, int>>W[212121];
int ck[212121];
int bk_sz = 299;
int state[212121];
void process() {
	int n; scanf("%d", &n);
	int i, j;;
	an = 0;
	for (i = 1; i <= n; i++) {
		L[i].clear();
		int sz; scanf("%d", &sz);
		for (j = 0; j < sz; j++) {
			int x; scanf("%d", &x);
			L[i].push_back(x);
			allNum[an++] = x;
		}
	}
	sort(allNum, allNum + an);
	an = unique(allNum, allNum + an) - allNum;
	vector<int>small, big;
	for (i = 1; i <= n; i++) {
		if (L[i].size() >= bk_sz)big.push_back(i);
		else small.push_back(i);
		for (j = 0; j < L[i].size(); j++) {
			L[i][j] = lower_bound(allNum, allNum + an, L[i][j]) - allNum;
		}
	}
	for (i = 0; i < an; i++)ck[i] = 0;
	for (auto bg : big) {
		for (auto x : L[bg])ck[x] = 1;
		for(int nxt = 1; nxt <= n; nxt++) {
			if (bg == nxt)continue;
			int cnt = 0;
			for (auto x : L[nxt]) cnt += ck[x];
			if (cnt >= 2) {
				printf("%d %d\n", bg, nxt);
				for (i = 1; i <= n; i++)L[i].clear();
				return;
			}
		}
		for (auto x : L[bg])ck[x] = 0;
	}
	for (auto sm : small) {
		for (i = 0; i < L[sm].size(); i++) {
			for (j = i + 1; j < L[sm].size(); j++) {
				int x = L[sm][i], y = L[sm][j];
				if (x > y)swap(x, y);
				W[x].push_back({ y,sm });
			}
		}
	}
	for (i = 0; i < an; i++) {
		for (auto [y, sm] : W[i]) {
			if (state[y]) {
				printf("%d %d\n", state[y], sm);
				for (auto [y, sm] : W[i])state[y] = 0;
				for (int i = 1; i <= n; i++)L[i].clear();
				for (i = 0; i < an; i++)W[i].clear();
				return;
			}
			state[y] = sm;
		}
		for (auto [y, sm] : W[i])state[y] = 0;
	}
	for (i = 0; i < an; i++)W[i].clear();
	puts("-1");
}
int main() {
	int t, tc; scanf("%d", &t);
	for (tc = 0; tc < t; tc++) {
		process();
	}
	return 0;
}