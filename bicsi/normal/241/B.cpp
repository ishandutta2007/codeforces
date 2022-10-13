#include <bits/stdc++.h>

using namespace std;

struct Node {
	int cnt, bit_cnt[32], leg[2];

	long long get_count(int bit, bool val) {
		return val ? bit_cnt[bit] : cnt - bit_cnt[bit];
	}
};

Node T[1000000];
int nodes, n;

int alloc(bool skip) {
	++nodes;
	T[nodes].cnt = T[nodes].leg[0] = T[nodes].leg[1] = 0;
	if(!skip) for(int i = 0; i < 32; ++i) T[nodes].bit_cnt[i] = 0;
	return nodes;
}

pair<int, long long> Query(int val, int k, bool skip) {
	int node = 1;

	pair<int, long long> ret = {0, 0LL};
	
	int x = (val ^ k);
	for(int i = 30; i >= 0; --i) {
		bool b = !!((k - 1) & (1 << i));
		bool bb = !!(val & (1 << i));
		if(b == 0) {
			ret.first += T[T[node].leg[!bb]].cnt;
			// cerr << "val: " << val << " bit: " << i << " -> " << ret.first << endl;
			if(!skip) for(int j = 0; j <= 30; ++j) {
				bool bbb = !!(val & (1 << j));
				ret.second += (T[T[node].leg[!bb]].get_count(j, !bbb) << j);
				ret.second %= 1000000007;
			}
			node = T[node].leg[bb];
		} else {
			node = T[node].leg[!bb];
		}
	}

	return ret;
}

void Insert(int val, bool skip) {
	int node = 1;
	for(int i = 30; i >= 0; --i) {
		bool b = !!(val & (1 << i));
		if(T[node].leg[b] == 0)
			T[node].leg[b] = alloc(skip);
		node = T[node].leg[b];
		T[node].cnt += 1;

		if(!skip) for(int j = 0; j <= 30; ++j)
			if(!!(val & (1 << j)))
				T[node].bit_cnt[j] += 1;
	}
}

int V[500000];
pair<int, long long> SolveFor(int k, bool skip) {
	nodes = 0;
	alloc(skip);

	pair<int, long long> ret = {0, 0LL};
	for(int i = 0; i < n; ++i) {
		auto p = Query(V[i], k, skip);
		Insert(V[i], skip);
		ret.first += p.first;
		ret.second += p.second;
	}
	return ret;
}


int main() {

	int m;
	cin >> n >> m;

	for(int i = 0; i < n; ++i)
		cin >> V[i];

	 /*auto pp = SolveFor(3);
	 cerr << pp.first << " " << pp.second << endl;
	 return 0;*/

	int ans = 0;
	for(int step = (1 << 30); step; step /= 2) {
		auto p = SolveFor(ans + step, true);
		if(p.first >= m) 
			ans += step; 
	}
	cerr << ans << endl;
	auto p = SolveFor(ans + 1, false);

	cout << (p.second + 1LL * (m - p.first) * ans) % 1000000007;

	return 0;
}