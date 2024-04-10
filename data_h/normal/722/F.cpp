#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

const int N = 1e5 + 7;
const int K = 40;
struct Info {
	int i, j, len;
};

int n, m;
std::vector<Info> infos[N];

int cnt[K + 1], which[K + 1], gcd[K + 1][K + 1];

int get_cons(int l) {
	int ret = 0;
	for (int i = 1; i <= K; i++) {
		if (i != l && cnt[i]) {
			if (which[l] % gcd[i][l] != which[i] % gcd[i][l]) {
				ret += cnt[i];
			}
		}
	}
	return ret;
}

int solve_sub(std::vector<Info> info) {
	int contradict = 0;
	std::fill(cnt + 1, cnt + K + 1, 0);
	std::fill(which + 1, which + K + 1, 0);
	int res = 0;
	for (int i = 0, j = 0; j < info.size(); j++) {
		while (cnt[info[j].len] && which[info[j].len] != info[j].j) {
			contradict -= get_cons(info[i].len);
			cnt[info[i].len]--;
			i++;
		}
		cnt[info[j].len]++;
		which[info[j].len] = info[j].j;
		contradict += get_cons(info[j].len);
		while (contradict) {
			contradict -= get_cons(info[i].len);
			cnt[info[i].len]--;
			i++;
		}
		res = std::max(res, j - i + 1);
	}
	return res;
}

int solve(std::vector<Info> &info) {
	int res = 0;
	for (int i = 0, j; i < info.size(); i = j) {
		std::vector<Info> tmp;
		for (j = i; j < info.size() && info[j].i - info[i].i == j - i; j++) {
			tmp.push_back(info[j]);
		}
		res = std::max(res, solve_sub(tmp));
	}
	return res;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			int x;
			scanf("%d", &x);
			infos[x].push_back({i, j, k});
		}
	}
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= K; j++) {
			gcd[i][j] = std::__gcd(i, j);
		}
	}
	for (int i = 1; i <= m; i++) {
		printf("%d\n", solve(infos[i]));
	}
	return 0;
}