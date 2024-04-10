#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

typedef unsigned long long ull;
ull POW(ull a, ull b, ull mod) {
	if (b == 0)return 1;
	ull x = POW(a, b / 2, mod);
	return x * x % mod * ((b & 1) ? a : 1) % mod;
}ull POW(ull a, ull b) {
	if (b == 0)return 1;
	ull x = POW(a, b / 2);
	return x * x * ((b & 1) ? a : 1);
}
long long Miller(ull d, ull n) {
	ull a = 2 + rand() % (n - 4);
	ull x = POW(a, d, n);
	if (x == 1 || x == n - 1) return 1;
	while (d != n - 1) {
		x = (x * x) % n;
		d *= 2;
		if (x == 1)return 0;
		if (x == n - 1)return 1;
	}
	return 0;
}
long long isPrime(ull n) {
	if (n <= 1)return 0;
	if (n <= 3)return 1;
	if (n % 2 == 0)return 0;
	ull d = n - 1;
	while (d % 2 == 0)d /= 2;
	for (long long i = 0; i < 5; i++) {
		if (!Miller(d, n))return 0;
	}
	return 1;
}

long long a[1212];

long long mySqrt(long long a, long long b) {
	if (b == 1)return a;
	long long s = 1, e;
	if (b == 2)e = 1e9;
	if (b == 3)e = 1e6;
	if (b == 4)e = 31633;
	if (b == 5)e = 3981;
	while (s <= e) {
		long long m = (s + e) / 2;
		ull R = POW(m, b);
		if (a == R)return m;
		if (a < R)e = m - 1;
		else s = m + 1;
	}
	return -1;
}

long long is_not_p[1212];
vector<long long>P_less_1e4;
vector<pair<long long, long long>>Plist;
vector<long long>bef[1212];
vector<long long>can[1212];
vector<long long>ONE[1212];
int main() {
	srand(10289412);
	long long n, k; scanf("%lld%lld", &n, &k);
	if (k == 1) {
		printf("0");
		return 0;
	}
	long long i, j;
	for (i = 0; i < n; i++) scanf("%lld", &a[i]);
	for (i = 2; i * i <= 1000; i++) {
		for (j = i * i; j <= 1000; j += i)is_not_p[j] = 1;
	}
	for (i = 2; i <= 1000; i++) {
		if (!is_not_p[i]) P_less_1e4.push_back(i);
	}
	vector<pair<long long, long long>>L;
	for (i = 0; i < n; i++) {
		long long fp = -1;
		for (auto p : P_less_1e4) {
			long long now = a[i];
			while (now % p == 0) now /= p;
			if (now == 1) {
				fp = p;
				break;
			}
		}
		if (fp != -1) {
			L.push_back({ fp, i });
			continue;
		}
		for (j = 1; j <= 5; j++) {
			long long v = mySqrt(a[i], j);
			if (v == -1)continue;
			if (isPrime(v)) {
				L.push_back({ v, i });
				break;
			}
		}
	}
	sort(L.begin(), L.end());

	for (i = 0; i < L.size();) {
		long long e, j;
		for (j = i; j < L.size() && L[i].first == L[j].first; j++)e = j;
		if (e - i + 1 >= 2) Plist.push_back({ L[i].first, e - i + 1 });
		i = j;
	}
	long long all_can = 0;
	for (i = 0; i < n; i++) {
		long long now = a[i];
		for (j = 0; j < Plist.size(); j++) {
			long long p = Plist[j].first;
			long long flag = 0;
			while (now % p == 0) {
				now /= p;
				flag = 1;
			}
			if (flag)bef[i].push_back(j);
		}
		if (now == 1) {
			if (bef[i].size() == 1) {
				ONE[bef[i][0]].push_back(i);
			}
			else {
				can[bef[i].size()].push_back(i);
			}
			all_can++;
		}
	}
	if (k > all_can) {
		printf("0");
		return 0;
	}
	vector<long long>two, three_more;
	long long all = 0;
	for (i = 0; i < Plist.size(); i++) {
		auto [p, sz] = Plist[i];
		if (sz == 2) two.push_back(i);
		else three_more.push_back(i);
		all += sz;
	}
	if (three_more.size()) {
		if (all <= k) {
			long long ccnt = 0;
			for (auto p_idx : two) {
				for (auto idx : ONE[p_idx]) {
					printf("%lld ", a[idx]), ccnt++;
				}
			}
			for (auto p_idx : three_more) {
				for (auto idx : ONE[p_idx]) {
					printf("%lld ", a[idx]), ccnt++;
				}
			}
			for (long long i = 2; i < 1000; i++) {
				for (auto idx : can[i]) {
					printf("%lld ", a[idx]);
					ccnt++;
					if (ccnt == k) {
						puts("");
						return 0;
					}
				}
			}
		}
		else {
			if (k % 2 == 0) {
				vector<long long>ans;
				for (auto p_idx : three_more) {
					for (long long i = 0; i < 2; i++) {
						auto idx = ONE[p_idx][i];
						ans.push_back(a[idx]);
					}
				}
				for (auto p_idx : two) {
					for (auto idx : ONE[p_idx]) {
						ans.push_back(a[idx]);
					}
				}
				for (auto p_idx : three_more) {
					for (long long i = 2; i < ONE[p_idx].size(); i++) {
						auto idx = ONE[p_idx][i];
						ans.push_back(a[idx]);
					}
				}
				for (i = 0; i < k; i++)printf("%lld ", ans[i]);
				puts("");
				return 0;
			}
			else {
				vector<long long>ans;
				long long flag = 1;
				for (auto p_idx : three_more) {
					for (long long i = 0; i < 2 + flag; i++) {
						auto idx = ONE[p_idx][i];
						ans.push_back(a[idx]);
					}
					if (flag)flag = 0;
				}
				for (auto p_idx : two) {
					for (auto idx : ONE[p_idx]) {
						ans.push_back(a[idx]);
					}
				}
				flag = 1;
				for (auto p_idx : three_more) {
					for (long long i = 2 + flag; i < ONE[p_idx].size(); i++) {
						auto idx = ONE[p_idx][i];
						ans.push_back(a[idx]);
					}
					if (flag)flag = 0;
				}
				for (i = 0; i < k; i++)printf("%lld ", ans[i]);
				puts("");
				return 0;
			}
		}
		return 0;
	}
	else {
		//  two
		if (k % 2 == 0) {
			vector<long long>ans;
			for (auto p_idx : two) {
				for (auto idx : ONE[p_idx]) {
					ans.push_back(a[idx]);
				}
			}
			for (long long i = 2; i < 1000; i++) {
				for (auto idx : can[i]) {
					ans.push_back(a[idx]);
				}
			}
			for (i = 0; i < k; i++)printf("%lld ", ans[i]);
			puts("");
			return 0;
		}
		else {
			long long ck[1212] = { 0, };
			long long ff = 1, w = -1, mnsz;
			vector<long long>lless;
			for (long long i = 2; i < 1000; i++) {
				for (auto idx : can[i]) {
					if (ff) {
						w = idx, ff = 0;
						mnsz = i;
					}
					else {
						lless.push_back(idx);
					}
				}
			}
			if (w == -1 || mnsz * 2 + 1 > k) {
				printf("0");
				return 0;
			}
			vector<long long>ans;
			for (auto p_idx : bef[w]) {
				ck[p_idx] = 1;
				for (auto idx : ONE[p_idx]) {
					ans.push_back(a[idx]);
				}
			}
			ans.push_back(a[w]);
			for (auto p_idx : two) {
				if (ck[p_idx])continue;
				for (auto idx : ONE[p_idx]) {
					ans.push_back(a[idx]);
				}
			}
			for (auto idx : lless) {
				ans.push_back(a[idx]);
			}
			for (i = 0; i < k; i++) {
				printf("%lld ", ans[i]);
			}
			puts("");
		}
	}
	return 0;
}