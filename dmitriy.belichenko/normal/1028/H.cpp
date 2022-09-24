#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <unordered_set>
#include <string>
#include <map>
#include <unordered_map>
#include <random>
#include <set>
#include <cassert>
#include <functional>
#include <queue>
#include <numeric>
#include <bitset>
#include <iterator>

using namespace std;

const int N = 200000, M = 5200000;

mt19937 gen(time(NULL));
#define forn(i, n) for (int i = 0; i < n; i++)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define mp make_pair
#define endl '\n'

typedef long long ll;

template<typename T = int>
inline T read() {
	T val = 0, sign = 1; char ch;
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-') sign = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		val = val * 10 + ch - '0';
	return sign * val;
}

int a[N];
vector<int> primes[N];
vector<int> bucket[M];

struct bi {
	int bnum, value, potential;
};

vector<bi> owned_buckets[N];

vector<int> primarize(int n) {
	vector<int> prime;
	for (int i = 2; i * i <= n; i++) 
		if (n % i == 0) {
			int times = 0;
			while (n % i == 0) n /= i, times++;
			if (times % 2) prime.push_back(i);
		}
	if (n > 1) prime.push_back(n);
	return prime;
}

vector<pii> query[N];

int ans[N];

int j = 0;

void go(vector<int> &p, int pos, int val, int ind, int potential) {
	if (pos >= p.size()) {
		owned_buckets[ind].push_back({ val, a[ind], potential});
		return;
	}
	go(p, pos + 1, val * p[pos], ind, potential - 1);
	go(p, pos + 1, val, ind, potential);
}

int ans_arr[20];

void add(int i) {
	for (auto& v : owned_buckets[i]) {
		auto& bvec = bucket[v.bnum];
		forn(j, 8)
			if (bvec[j] != -1) {
				ans_arr[j + v.potential] = max(ans_arr[j + v.potential], bvec[j]);
			}
		bvec[v.potential] = i;
	}
}

int get_ans(int l) {
	int ans = 1e9;
	forn(i, 20)
		if (ans_arr[i] != -1 && ans_arr[i] >= l) {
			ans = i;
			break;
		}
	assert(ans != 1e9);
	return ans;
}

int answer[M];

void solve() {
	int n = read(), m = read();

	//fill_n(bucket_num, M, -1);
	fill_n(ans_arr, 20, -1);

	forn(i, n) {
		a[i] = read();
		primes[i] = primarize(a[i]);
		go(primes[i], 0, 1, i, primes[i].size());
	}

	forn(i, m) {
		int l = read() - 1, r = read() - 1;
		query[r].push_back(mp(l, i));
	}

	forn(i, M) bucket[i].resize(8, -1);

	forn(i, n) {
		add(i);
		for (auto &q : query[i])
			answer[q.second] = get_ans(q.first);
	}

	forn(i, m) {
		printf("%d\n", answer[i]);
	}
}

void precalc() {

}

signed main() {
	int t = 1;
	precalc();

	while (t--) {
		clock_t z = clock();
		solve();
		debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
	}
}