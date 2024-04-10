#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

const long long INF = (1LL << 61);
const int DEBUG = 0;

int n, l;

vector<int> construct(long long all, vector<pair<long long, long long> > s) {
if (DEBUG) {
	cout << "construct by " << all << endl;
}
	vector<int> ret(l);
	for (auto &d : s) {
		long long times = d.first / l;
		d.second -= times * all;
		d.first %= l;
	}
	for (int i = 0; i < s.size(); i++) {
		long long rpos = (i + 1 == s.size() ? l : s[i + 1].first);
		long long rval = (i + 1 == s.size() ? all : s[i + 1].second);
		long long diff = s[i].second - rval;
//		printf("curpos = %lld rpos = %lld diff = %lld\n", s[i].first, rpos, diff);
		if (rpos - s[i].first < abs(diff) || (rpos - s[i].first) % 2 != abs(diff) % 2) {
			return vector<int>();
		}
		for (int j = s[i].first; j < rpos; j++) {
			if (diff > 0) {
				ret[j] = -1;
				diff--;
			} else if (diff <= 0) {
				ret[j] = 1;
				diff++;
			}
		}
	}
if (DEBUG) {
	printf("constructed!\n");
	for (auto v : ret) {
		printf("%d ", v);
	}
	puts("");
}
	return ret;
}

void bound(long long &lower, long long &upper, long long fix, long long len, long long times) {
	// fix - len <= all * times <= fix + len
	if (times == 0) {
		if (fix + len < 0 || fix - len > 0) {
			lower = INF;
			upper = -INF;
		}
		return ;
	}

	long long l = fix - len, r = fix + len;
	if (times < 0) {
		times = -times;
		swap(l, r);
		l = -l;
		r = -r;
	}
	upper = min(upper, r >= 0 ? r / times : -((-1 * r + times - 1) / times));
	lower = max(lower, l >= 0 ? (l + times - 1) / times : -(-1 * l / times));
}

vector<int> solve(vector<pair<long long, long long> > s) {
if (DEBUG) {
	cerr << "s info" << endl;
	for (int i = 0; i < s.size(); i++) {
		printf("time = %lld pos = %lld\n", s[i].first, s[i].second);
	}
}
	s.push_back(make_pair(0, 0));
	sort(s.begin(), s.end(), [&](const auto &a, const auto &b) {
		if (a.first % l != b.first % l) {
			return a.first % l < b.first % l;
		}
		return a.first < b.first;
	});
	s.erase(unique(s.begin(), s.end()), s.end());

	long long all = INF;
	for (int i = 0; i + 1 < s.size(); i++) {
		if (s[i].first % l == s[i + 1].first % l &&
			s[i].first != s[i + 1].first) {
			long long diff = s[i + 1].second - s[i].second;
			long long times = (s[i + 1].first - s[i].first) / l;
			if (diff % times != 0 || (all != INF && all != diff / times)) {
				return vector<int>();
			} else {
				all = diff / times;
			}
		}
	}
	if (all != INF) {
		return construct(all, s);
	}


	long long lower = -INF, upper = INF;
	bool even = true, odd = true;
	for (int i = 0; i < s.size(); i++) {
		bool last = i + 1 == s.size();
		long long fix = (last ? 0 : s[i + 1].second) - s[i].second;
		long long times = (last ? -1 : s[i + 1].first / l) - s[i].first / l;
		long long len = (last ? l : s[i + 1].first % l) - s[i].first % l;
		bound(lower, upper, fix, len, times);
if (DEBUG) {
	printf("fix = %lld len = %lld times = %lld\n", fix, len, times);
}
		int o = (abs(fix) % 2) ^ (len % 2);
		if (o) {
			if (times % 2 == 0) return vector<int>();
			even = false;
		} else {
			if (times % 2 == 1) odd = false;
		}
	}

	{ // for i = s.size() - 1
		// fix = all - s[i].second
		// times = 1 - s[i].first / l
		// len = l - s[i].first % l;
		// times * all + -len ~ len = all - s[i].second;
	}

if (DEBUG) {
	cout << "lower = " << lower << " upper = " << upper << endl;
	cout << "even = " << even << " odd = " << odd << endl;
}

	if (!even && !odd) return vector<int>();
	for (long long i = lower; i <= upper && all == INF; i++) {
		if (abs(i) % 2 == 0 && even) all = i;
		if (abs(i) % 2 == 1 && odd) all = i;
	}
	if (all == INF) return vector<int>();
	return construct(all, s);
}

int main() {
	scanf("%d %d", &n, &l);
	vector<pair<long long, long long> > xs, ys;
	for (int i = 0; i < n; i++) {
		long long t, x, y;
		scanf("%lld %lld %lld", &t, &x, &y);
		xs.push_back(make_pair(t, x + y));
		ys.push_back(make_pair(t, x - y));
	}
	vector<int> ansx = solve(xs);
	vector<int> ansy = solve(ys);
	if (ansx.size() == 0 || ansy.size() == 0) {
		puts("NO");
		return 0;
	}

	for (int i = 0; i < l; i++) {
		if (ansx[i] == 1 && ansy[i] == 1) {
			printf("R");
		} else if (ansx[i] == 1 && ansy[i] == -1) {
			printf("U");
		} else if (ansx[i] == -1 && ansy[i] == 1) {
			printf("D");
		} else {
			printf("L");
		}
	}
	puts("");
	return 0;
}