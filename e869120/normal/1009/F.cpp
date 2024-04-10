#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

template<typename Type> class RangeMin {
private:
	int size_;
	std::vector<Type> dat;
public:
	RangeMin() : size_(0), dat(std::vector<Type>()) {};
	RangeMin(int size__) {
		for (size_ = 1; size_ < size__; ) size_ <<= 1;
		dat.resize(size_ << 1, std::numeric_limits<Type>::min());
	}
	template<class T>
	RangeMin(T begin_, T end_) {
		int n = end_ - begin_;
		for (size_ = 1; size_ < n; size_ <<= 1); dat.resize(size_ << 1, std::numeric_limits<Type>::min());
		for (int i = 0; i < n; i++) dat[i + size_] = *(begin_ + i);
		for (int i = size_ - 1; i > 0; i--) dat[i] = std::max(dat[i << 1], dat[(i << 1) + 1]);
	}
	inline unsigned size() { return size_; }
	inline void update(int i, Type x) {
		i += size_; dat[i] = x;
		while (i > 1) {
			i >>= 1;
			dat[i] = std::max(dat[i << 1], dat[i << 1 | 1]);
		}
	}
	inline Type query(int l, int r) {
		Type ret = std::numeric_limits<Type>::min();
		l += size_; r += size_;
		while (l != r) {
			if (l & 1) ret = std::max(ret, dat[l++]); l >>= 1;
			if (r & 1) ret = std::max(ret, dat[--r]); r >>= 1;
		}
		return ret;
	}
};

const int MAX_N = 1000009;

int n, x[MAX_N], y[MAX_N], dist[MAX_N], maxdst[MAX_N], J[MAX_N], K[MAX_N], ans[MAX_N];
vector<int>X[MAX_N], Y[MAX_N]; vector<pair<int, int>>S; RangeMin<pair<int, int>> G[MAX_N];

void dfs(int pos, int depth) {
	dist[pos] = depth;
	for (int i = 0; i < X[pos].size(); i++) {
		if (dist[X[pos][i]] != -1) continue;
		Y[pos].push_back(X[pos][i]);
		dfs(X[pos][i], depth + 1);
	}
}

void dfs2(int pos) {
	for (int i = 0; i < Y[pos].size(); i++) {
		dfs2(Y[pos][i]); maxdst[pos] = max(maxdst[pos], maxdst[Y[pos][i]] + 1);
	}

	if (Y[pos].size() == 0) {
		J[pos] = pos; K[pos] = 1;
	}
	else {
		vector<pair<int, int>> P;
		for (int i : Y[pos]) {
			P.push_back(make_pair(K[J[i]], J[i]));
		}
		sort(P.begin(), P.end()); reverse(P.begin(), P.end());
		J[pos] = P[0].second; K[J[pos]] = P[0].first + 1;
	}
}

int main() {
	cin >> n; for (int i = 1; i <= n; i++) dist[i] = -1;
	for (int i = 1; i <= n - 1; i++) {
		scanf("%d%d", &x[i], &y[i]);
		X[x[i]].push_back(y[i]);
		X[y[i]].push_back(x[i]);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) S.push_back(make_pair(dist[i], i));
	sort(S.begin(), S.end()); reverse(S.begin(), S.end());

	dfs2(1);
	for (int i = 1; i <= n; i++) G[i] = RangeMin<pair<int, int>>(K[i]);
	
	for (pair<int, int> i: S) {
		int pos = i.second;
		if (Y[pos].size() == 0) {
			G[pos].update(0, make_pair(1, 0)); ans[pos] = 0;
		}
		else {
			vector<pair<int, int>>T;
			for (int j = 0; j < Y[pos].size(); j++) {
				T.push_back(make_pair(maxdst[Y[pos][j]] + 1, J[Y[pos][j]]));
			}
			sort(T.begin(), T.end()); reverse(T.begin(), T.end());

			for (int j = 0; j < Y[pos].size(); j++) {
				if (J[Y[pos][j]] == T[0].second) continue;
				int to = J[Y[pos][j]];
				for (int k = 0; k < K[to]; k++) {
					int upg = (maxdst[pos] + 1) - (K[to] - k) - 1;
					pair<int, int>TT = G[J[pos]].query(upg, upg + 1);
					pair<int, int>UU = G[to].query(k, k + 1);
					TT.first += UU.first;
					G[J[pos]].update(upg, TT);
				}
			}
			G[J[pos]].update(maxdst[pos], make_pair(1, maxdst[pos]));
			ans[pos] = G[J[pos]].query(0, maxdst[pos] + 1).second;
		}
	}
	for (int i = 1; i <= n; i++) printf("%d\n", maxdst[i] - ans[i]);
	return 0;
}