#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N;
set<int> ss[205];
vector<int> si[205];
vector<int> fin, ans;
int sls[205];

bool check() {
	for (int i = 3; i <= N; ++i) {
		int p = sls[i];
		int s = SZ(si[p]);
		vector<int> nv;
		for (int j = i; j > i - s; --j) nv.push_back(fin[j - 1]);
		sort(nv.begin(), nv.end());
		if (nv != si[p]) return 0;
	}
	return 1;
}

void gonext() {
	for (int i : fin) for (int j = 1; j <= N; ++j) ss[j].erase(i);
	for (int i = 3; i <= N; ++i) {
		int sel = 0, sep = 0;
		for (int j = 2; j <= N; ++j) if (SZ(ss[j]) == 1) {
			sel = *ss[j].begin();
			sep = j;
			break;
		}
		if (!sel) return;
		sls[i] = sep;
		for (int j = 1; j <= N; ++j) ss[j].erase(sel);
		fin.push_back(sel);
	}
	if (check()) ans = fin;
}

void solve() {
	scanf("%d", &N);
	for (int i = 2; i <= N; ++i) {
		int c; scanf("%d", &c);
		si[i].clear();
		while (c--) {
			int x; scanf("%d", &x);
			si[i].push_back(x);
		}
	}
	ans.clear();
	for (int i = 1; i <= N; ++i) if (SZ(si[i]) == 2) {
		fin.clear();
		fin.push_back(si[i][0]);
		fin.push_back(si[i][1]);
		for (int i = 2; i <= N; ++i) for (int j : si[i]) ss[i].insert(j);
		gonext();
		if (SZ(ans)) break;
		fin.clear();
		fin.push_back(si[i][1]);
		fin.push_back(si[i][0]);
		for (int i = 2; i <= N; ++i) for (int j : si[i]) ss[i].insert(j);
		gonext();
		if (SZ(ans)) break;
	}
	for (int i : ans) printf("%d ", i);
	puts("");
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}