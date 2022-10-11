#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
template<typename Type> class RangeTree {
private:
	int size_;
	std::vector<std::vector<Type> > dat;
	std::vector<std::vector<int> > vl;
	inline int query_(int a, int b, Type x, int k, int l, int r, int e) {
		// Find range [a, b) : value < x : Now k-th node and the range is [l, r) and e integers below x in the range
		if (r <= a || b <= l || e == 0) return 0;
		if (a <= l && r <= b) return e;
		int lc = query_(a, b, x, k << 1, l, (l + r) >> 1, vl[k][e - 1]);
		int rc = query_(a, b, x, k << 1 | 1, (l + r) >> 1, r, e - vl[k][e - 1]);
		return lc + rc;
	}
public:
	RangeTree() : size_(0), dat(std::vector<Type>()) {};
	template<class T>
	RangeTree(T begin_, T end_) {
		int n = (end_ - begin_);
		for (size_ = 1; size_ < n; size_ <<= 1);
		dat.resize(size_ << 1);
		vl.resize(size_);
		for (int i = 0; i < n; i++) dat[i + size_].push_back(*(begin_ + i));
		for (int i = size_ - 1; i > 0; i--) {
			dat[i].resize(dat[i << 1].size() + dat[i << 1 | 1].size());
			vl[i].resize(dat[i].size());
			int cl = 0;
			for (int j = 0; j < dat[i].size(); j++) {
				if (j - cl == dat[i << 1 | 1].size() || (cl != dat[i << 1].size() && dat[i << 1][cl] < dat[i << 1 | 1][j - cl])) dat[i][j] = dat[i << 1][cl++];
				else dat[i][j] = dat[i << 1 | 1][j - cl];
				vl[i][j] = cl;
			}
		}
	}
	inline int size() { return size_; }
	inline int query(int l, int r, Type x) {
		// Find range [a, b) : value < x
		int ptr = lower_bound(dat[1].begin(), dat[1].end(), x) - dat[1].begin();
		return query_(l, r, x, 1, 0, size_, ptr);
	}
};
long long n, a[210000], num[210000], num2[210000], num3[210000], dist[210000], cnt; bool used[210000];
vector<pair<long long, long long>>x[210000];
void rec(long long t, long long depth) {
	cnt++; num[t] = cnt; dist[t] = depth; used[t] = true;
	for (int i = 0; i < x[t].size(); i++) {
		if (used[x[t][i].first] == false) {
			used[x[t][i].first] = true;
			rec(x[t][i].first, depth + x[t][i].second);
		}
	}
	num3[t] = cnt;
}
int main() {
	cin >> n; for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 2; i <= n; i++) { long long r1, r2; cin >> r1 >> r2; x[r1].push_back(make_pair(i, r2)); x[i].push_back(make_pair(r1, r2)); }
	rec(1, 0); vector<long long>W; W.push_back(-1);
	for (int i = 1; i <= n; i++)num2[num[i]] = i;
	for (int i = 1; i <= n; i++)W.push_back(dist[num2[i]] - a[num2[i]]);
	RangeTree<long long>E(W.begin(), W.end());
	for (int i = 1; i <= n; i++) {
		if (i >= 2)cout << ' ';
		long long pos1 = E.query(num[i], num3[i] + 1, dist[i] + 1);
		cout << pos1 - 1;
	}
	cout << endl;
	return 0;
}