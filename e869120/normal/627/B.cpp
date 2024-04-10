#include <limits>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template <typename Type> class FenwickTree {
private:
	unsigned size_;
	std::vector<Type> v;
	Type sum(long long r) {
		Type ret = 0;
		while (r >= 1) {
			ret += v[r];
			r -= r & -r;
		}
		return ret;
	}
public:
	FenwickTree() {};
	FenwickTree(int size__) : size_(size__), v(vector<Type>(size_, 0)) {};
	void add(long long i, Type x) {
		i++;
		while (i <= size_) {
			v[i] += x;
			i += i & -i;
		}
	}
	Type sum(long long l, unsigned r) {
		return sum(r) - sum(l);
	}
};

long long n, k, a, b, q, c; long long V[200009];

int main() {
	cin >> n >> k >> b >> a >> q;
	FenwickTree<long long>A1(300002), A2(300002);
	for (int i = 0; i < q; i++) {
		int s; cin >> s;
		if (s == 1) {
			long long t, u; cin >> t >> u; c += u;
			A1.add(t, min(a, V[t] + u) - min(a, V[t]));
			A2.add(t, min(b, V[t] + u) - min(b, V[t])); V[t] += u;
		}
		if (s == 2) {
			long long t; cin >> t;
			cout << A1.sum(1, t) + A2.sum(t + k, n + 1) << endl;
		}
	}
	return 0;
}