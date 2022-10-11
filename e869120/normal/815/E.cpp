#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

long long N, K, lim; map<long long, long long>M;

long long dfs(long long x) {
	if (M[x] >= 1) return M[x] - 1;
	if (x < lim) return 0;

	long long res = 0;
	res += dfs(x / 2);
	res += dfs((x + 1) / 2);
	if (x == lim || x == lim + 1) res++;
	M[x] = res + 1;
	return res;
}

long long solve(long long pos, long long r) {
	lim = pos;
	dfs(N - 1);

	long long cl = 1, cr = N;
	while (true) {
		long long lens = cr - cl;
		long long left_hand = max(0LL, M[lens / 2] - 1);
		long long mid_hand = 0; if (lens == lim || lens == lim + 1) mid_hand = 1;
		long long right_hand = max(0LL, M[(lens + 1) / 2] - 1);

		if (left_hand == 0 && right_hand == 0 && mid_hand == 0) break;

		if (r <= left_hand) { cr = (cl + cr) / 2; }
		else if (r <= left_hand + mid_hand) return (cl + cr) / 2;
		else { r -= left_hand + mid_hand; cl = (cl + cr) / 2; }
	}
	return (cl + cr) / 2;
}

int main() {
	cin >> N >> K;
	if (K == 1) { cout << "1" << endl; return 0; }
	if (K == 2) { cout << N << endl; return 0; }
	K -= 2;

	map<long long, long long>Map; vector<long long>ret;
	Map[N - 1] = 1; ret.push_back(N - 1);

	for (int i = 0; i < ret.size(); i++) {
		Map[ret[i] / 2] += Map[ret[i]]; ret.push_back(ret[i] / 2);
		Map[(ret[i] + 1) / 2] += Map[ret[i]]; ret.push_back((ret[i] + 1) / 2);
		sort(ret.begin(), ret.end());
		ret.erase(unique(ret.begin(), ret.end()), ret.end());
		reverse(ret.begin(), ret.end());
	}
	
	for (int i = 0; i < ret.size(); i++) {
		if (K <= Map[ret[i]]) {
			long long c = ret[i];
			if (c % 2 == 1) { c--; }
			else { K += Map[c + 1]; }
			cout << solve(c, K) << endl;
			return 0;
		}
		K -= Map[ret[i]];
	}
	return 0;
}