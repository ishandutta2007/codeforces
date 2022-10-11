#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

class BIT {
public:
	vector<long long>dat; int sz = 0;
	void init(int size_) {
		dat.resize(size_ + 2, 0);
		sz = size_;
	}
	void add(int pos, long long x) {
		pos++;
		while (pos <= sz) { dat[pos] += x; pos += (pos&-pos); }
	}
	long long sum(int pos) {
		pos++; long long s = 0;
		while (pos >= 1) { s += dat[pos]; pos -= (pos&-pos); }
		return s;
	}
	long long prevs(int pos) {
		if (pos == -1) return -1;
		long long s = 0;
		for (int i = 20; i >= 0; i--) {
			if (s + (1 << i) > sz) continue;
			if (dat[s + (1 << i)] < pos) { pos -= dat[s + (1 << i)]; s += (1 << i); }
		}
		return s;
	}
};

long long Q, a[500009], b[500009], id[500009]; vector<pair<long long, int>>vec;

int main() {
	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		scanf("%lld", &a[i]);
		if (a[i] == 1) scanf("%lld", &b[i]);
		if (a[i] == 1) vec.push_back(make_pair(b[i], i));
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) id[vec[i].second] = i;

	BIT A1, A2;
	A1.init(vec.size() + 4); A2.init(vec.size() + 4);

	long long maxn = 0, LL = 0, LL2 = 0;

	for (int i = 1; i <= Q; i++) {
		if (a[i] == 1) {
			A1.add(id[i], 1);
			A2.add(id[i], b[i]);
			maxn = max(maxn, b[i]);
			LL++;
		}
		if (a[i] == 2) {
			long long L = 0, R = LL, M1, M2; LL2++;
			for (int j = 0; j < 40; j++) {
				M1 = (L + L + R) / 3;
				M2 = (L + R + R) / 3;
				long long C1 = A1.prevs(M1), C2 = A1.prevs(M2);
				long double T1 = 1.0L*(A2.sum(C1) + maxn) / (A1.sum(C1) + 1);
				long double T2 = 1.0L*(A2.sum(C2) + maxn) / (A1.sum(C2) + 1);

				/*if (LL2 == 23) {
					cout << "* " << M1 << "->" << C1 << " " << M2 << "->" << C2 << " " << T1 << " " << T2 << endl;
				}*/
				if (T1 < T2) { R = M2; }
				else { L = M1; }
			}
			long double maxv = 0;
			for (int j = M1 - 5; j <= M1 + 5; j++) {
				if (j < -1 || j >= LL) continue;
				long long C1 = A1.prevs(j);
				long double T = 1.0L * maxn - 1.0L*(A2.sum(C1) + maxn) / (A1.sum(C1) + 1);
				/*if (LL2 == 23) {
					cout << "* " << j << "->" << C1 << " " << T << endl;
				}*/
				maxv = max(maxv, T);
			}
			printf("%.12Lf\n", maxv);
		}
	}
	return 0;
}