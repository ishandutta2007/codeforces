#include <bits/stdc++.h>
using namespace std;

class BIT {
	public:
	vector<long long>bit; int size_ = 0;
	
	void init(int sz) {
		size_ = sz + 2;
		bit.resize(size_, 0);
	}
	void add(int pos, int x) {
		pos++;
		while (pos <= size_) {
			bit[pos] += x;
			pos += (pos & -pos);
		}
	}
	long long sum(int pos) {
		long long s = 0; pos++;
		while (pos >= 1) {
			s += bit[pos];
			pos -= (pos & -pos);
		}
		return s;
	}
};

int N, Q, P[1 << 20], cl[1 << 20], cr[1 << 20], el[1 << 20], er[1 << 20]; long long ans[1 << 20];
set<int>Set; vector<pair<int, int>> W;

vector<int> H[1 << 20], I[1 << 20];

void solve1() {
	for (int i = 1; i <= N; i++) { H[i].clear(); I[i].clear(); }
	for (int i = 1; i <= N; i++) H[cl[i]].push_back(i);
	for (int i = 1; i <= Q; i++) I[el[i]].push_back(i);
	
	BIT Z0, Z1, Z2; Z0.init(N + 1); Z1.init(N + 1); Z2.init(N + 1);
	for (int i = N; i >= 1; i--) {
		Z1.add(i, i); Z0.add(i, 1);
		for (int j = 0; j < H[i].size(); j++) {
			int pos = H[i][j], fl = cl[pos], fr = pos;
			Z0.add(pos, -1);
			Z1.add(pos, -pos);
			Z2.add(pos, fr - fl + 1);
		}
		for (int j = 0; j < I[i].size(); j++) {
			int pos = I[i][j], fr = er[I[i][j]];
			long long V1 = Z1.sum(fr) - 1LL * (i - 1LL) * Z0.sum(fr);
			long long V2 = Z2.sum(fr);
			//cout << i << " " << pos << " " << V1 << " " << V2 << endl;
			ans[pos] += (V1 + V2);
		}
	}
	//for (int i = 1; i <= Q; i++) { if (i >= 2) printf(" "); printf("%lld", ans[i]); } printf("\n");
}

void solve2() {
	for (int i = 1; i <= N; i++) { H[i].clear(); I[i].clear(); }
	for (int i = 1; i <= N; i++) H[cr[i]].push_back(i);
	for (int i = 1; i <= Q; i++) I[er[i]].push_back(i);
	
	BIT Z0, Z1, Z2; Z0.init(N + 1); Z1.init(N + 1); Z2.init(N + 1);
	for (int i = 1; i <= N; i++) {
		Z1.add(i, i); Z0.add(i, 1);
		for (int j = 0; j < H[i].size(); j++) {
			int pos = H[i][j], fl = pos, fr = cr[pos];
			Z0.add(pos, -1);
			Z1.add(pos, -pos);
			Z2.add(pos, fr - fl + 1);
		}
		for (int j = 0; j < I[i].size(); j++) {
			int pos = I[i][j], fl = el[I[i][j]];
			long long V1 = -(Z1.sum(N) - Z1.sum(fl - 1)) + 1LL * (i + 1LL) * (Z0.sum(N) - Z0.sum(fl - 1));
			long long V2 = (Z2.sum(N) - Z2.sum(fl - 1));
			//cout << i << " " << pos << " " << V1 << " " << V2 << " " << fl << endl;
			ans[pos] += (V1 + V2);
		}
	}
}

int main() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; i++) { scanf("%d", &P[i]); W.push_back(make_pair(P[i], i)); }
	for (int i = 1; i <= Q; i++) scanf("%lld", &el[i]);
	for (int i = 1; i <= Q; i++) scanf("%lld", &er[i]);
	
	sort(W.begin(), W.end());
	reverse(W.begin(), W.end());
	
	Set.insert(0); Set.insert(N + 1);
	for (int i = 0; i < W.size(); i++) {
		int pos = W[i].second;
		auto itr = Set.lower_bound(pos); cr[pos] = (*itr) - 1;
		itr--; cl[pos] = (*itr) + 1;
		Set.insert(pos);
	}
	//for (int i = 1; i <= N; i++) cout << cl[i] << " " << cr[i] << endl;
	solve1();
	solve2();
	for (int i = 1; i <= Q; i++) { if (i >= 2) printf(" "); printf("%lld", ans[i] - 1LL * (er[i] - el[i] + 1LL)); } printf("\n");
	return 0;
}