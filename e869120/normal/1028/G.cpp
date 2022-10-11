#include <iostream>
#include <vector>
using namespace std;

const long long MAX_N = 5000;
const long long MAX_Q = 10000;

struct Node {
	vector<long long> val; vector<int> nex;
};

long long cnt = 1, cur = 0, pows[5] = { 1LL, (MAX_Q + 1LL), (MAX_Q + 1LL) * (MAX_Q + 1LL), (MAX_Q + 1LL) * (MAX_Q + 1LL) * (MAX_Q + 1LL), (MAX_Q + 1LL) * (MAX_Q + 1LL) * (MAX_Q + 1LL) * (MAX_Q + 1LL) };
Node G[MAX_N];

void dfs(int pos, int dep, long long uplim) {
	if (uplim > MAX_Q) {
		cur += pows[dep] - 1LL;
		return;
	}
	if (dep == 1) {
		for (int i = 1; i <= uplim; i++) {
			cur++;
			G[pos].val.push_back(cur);
			G[pos].nex.push_back(-1);
		}
		return;
	}

	long long cur_uplim = uplim;
	for (int i = 1; i <= uplim + 1; i++) {
		cnt++;
		G[pos].nex.push_back(cnt);

		dfs(cnt, dep - 1, cur_uplim);

		if (i != uplim + 1) {
			cur++; G[pos].val.push_back(cur);
			cur_uplim = cur + 1;
		}
	}
}

int main() {
	dfs(1, 5, 1);

	long long cx = 1, range_l = 1, range_r = cur;
	for (int t = 4; t >= 0; t--) {
		vector<long long> D;
		if (cx != -1 && cx <= cnt && G[cx].val.size() >= 1) {
			D = G[cx].val;
		}
		else {
			for (int i = 1; i <= MAX_Q; i++) D.push_back((range_l - 1LL) + 1LL * i * pows[t]);
		}
		cout << D.size(); for (int i = 0; i < D.size(); i++) cout << " " << D[i]; cout << endl;
		int S; cin >> S;
		if (S == -1) break;

		if (cx != -1 && cx <= cnt && G[cx].val.size() >= 1) cx = G[cx].nex[S];
		else cx = -1;
		if (S >= 1) range_l = D[S - 1] + 1LL;
		if (S < (int)D.size() - 1) range_r = D[S] - 1LL;
	}
	return 0;
}