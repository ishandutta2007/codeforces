#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

class BIT {
public:
	vector<int>bit; int size_ = 0;

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
		int s = 0; pos++;
		while (pos >= 1) {
			s += bit[pos];
			pos -= (pos&-pos);
		}
		return s;
	}
};

long long N, T, A[200009], B[200009];
vector<long long>X;

int main() {
	cin >> N >> T;
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
		B[i] = B[i - 1] + A[i];
		X.push_back(B[i]);
		X.push_back(B[i] - T);
	}
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());

	BIT Z; Z.init(X.size() + 2);
	int pos1 = lower_bound(X.begin(), X.end(), B[0]) - X.begin();
	Z.add(pos1, 1);

	long long sum = 0;
	for (int i = 1; i <= N; i++) {
		int pos3 = lower_bound(X.begin(), X.end(), B[i] - T) - X.begin();
		sum += 1LL * (Z.sum(X.size()) - Z.sum(pos3));

		int pos2 = lower_bound(X.begin(), X.end(), B[i]) - X.begin();
		Z.add(pos2, 1);
	}
	cout << sum << endl;
	return 0;
}