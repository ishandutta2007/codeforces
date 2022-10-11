#include <bits/stdc++.h>
using namespace std;

class BIT {
	public:
	vector<int>bit; int size_ = 1;
	
	void init(int sz) {
		size_ = sz + 2;
		bit.resize(size_ + 2, 0);
	}
	void add(int pos, int x) {
		pos++;
		while (pos <= size_) {
			bit[pos] += x;
			pos += (pos & -pos);
		}
	}
	int sum(int pos) {
		pos++; int s = 0;
		while (pos >= 1) {
			s += bit[pos];
			pos -= (pos & -pos);
		}
		return s;
	}
	int counts(int pos) {
		int cl = 0, cr = size_ + 1, cm, minx = (1 << 30);
		for (int i = 0; i < 22; i++) {
			cm = (cl + cr) >> 1;
			int D = sum(cm);
			if (D >= pos) { minx = min(minx, cm); cr = cm; }
			else cl = cm;
		}
		return minx;
	}
};

int N, M, K, E[1 << 19], a[1 << 19]; vector<int> v[1 << 19];
int ans[1 << 19]; vector<pair<long long, long long>> vec;
BIT Z;

int main() {
	scanf("%d%d%d", &N, &M, &K); Z.init(M + 2);
	for (int i = 0; i < N; i++) {
		scanf("%d", &E[i]); a[E[i]]++;
	}
	for (int i = 1; i <= M; i++) v[a[i]].push_back(i);
	for (int i = 1; i <= K; i++) {
		long long p; scanf("%lld", &p); p -= N;
		vec.push_back(make_pair(p, i));
	}
	sort(vec.begin(), vec.end());
	
	int cx = 0; long long sum = 0, current = 0;
	current = v[0].size(); for (int i = 0; i < (int)v[0].size(); i++) Z.add(v[0][i], 1);
	
	for (int i = 0; i < (int)vec.size(); i++) {
		while (vec[i].first > sum + current && cx <= N) {
			sum += 1LL * current;
			cx++; current += v[cx].size();
			for (int j = 0; j < (int)v[cx].size(); j++) Z.add(v[cx][j], 1);
		}
		long long T = vec[i].first - sum; T %= current; if (T == 0) T = current;
		ans[vec[i].second] = Z.counts(T);
		//cout << cx << " " << T << " " << ans[vec[i].second] << endl;
	}
	for (int i = 1; i <= K; i++) printf("%d\n", ans[i]);
	return 0;
}