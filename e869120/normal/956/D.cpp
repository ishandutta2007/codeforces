#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

class BIT {
public:
	vector<int>bit; int size_;

	void init(int sz) {
		size_ = sz + 2;
		bit.resize(size_ + 2, 0);
	}
	void add(int pos, int x) {
		pos++;
		while (pos <= size_) {
			bit[pos] += x;
			pos += (pos&-pos);
		}
	}
	int sum(int pos) {
		pos++; int s = 0;
		while (pos >= 1) {
			s += bit[pos];
			pos -= (pos&-pos);
		}
		return s;
	}
};

long long get_inversion(vector<int> A1, vector<int>A2) {
	vector<int>L(A2.size(), 0);
	for (int i = 0; i < A2.size(); i++) L[A2[i]] = i;
	
	vector<int>I;
	for (int i = 0; i < A1.size(); i++) I.push_back(L[A1[i]]);
	
	long long rem = 0; BIT Z; Z.init(A1.size() + 1);
	for (int i = 0; i < I.size(); i++) {
		rem += 1LL * (i - Z.sum(I[i]));
		Z.add(I[i], 1);
	}
	return rem;
}

int N, W, X[100009], V[100009];
vector<tuple<long double, long double, int>> V1, V2;

int main() {
	scanf("%d%d", &N, &W);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &X[i], &V[i]);
		V1.push_back(make_tuple(1.0L * X[i] / (V[i] - W), 1.0L / X[i], i));
		V2.push_back(make_tuple(1.0L * X[i] / (V[i] + W), -1.0L / X[i], i));
	}
	sort(V1.begin(), V1.end()); vector<int>B1; for (int i = 0; i < N; i++) B1.push_back(get<2>(V1[i]));
	sort(V2.begin(), V2.end()); vector<int>B2; for (int i = 0; i < N; i++) B2.push_back(get<2>(V2[i]));

	cout << get_inversion(B1, B2) << endl;
	return 0;
}