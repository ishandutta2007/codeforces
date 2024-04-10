#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

struct Node {
	int num, l, r;
};

class XORTree {
public:
	vector<Node>vec; int size_ = 0;

	void init() {
		vec.push_back(Node{ 0,-1,-1 });
		size_++;
	}
	void add(long long d) {
		int cx = 0;
		for (int i = 59; i >= 0; i--) {
			vec[cx].num++;
			if ((d / (1LL << i)) % 2 == 0) {
				if (vec[cx].l == -1) { vec.push_back(Node{ 0,-1,-1 }); vec[cx].l = size_; size_++; }
				cx = vec[cx].l;
			}
			else {
				if (vec[cx].r == -1) { vec.push_back(Node{ 0,-1,-1 }); vec[cx].r = size_; size_++; }
				cx = vec[cx].r;
			}
		}
		vec[cx].num++;
	}
	void lose(long long d) {
		int cx = 0;
		for (int i = 59; i >= 0; i--) {
			vec[cx].num--;
			if ((d / (1LL << i)) % 2 == 0) {
				if (vec[cx].l == -1) { vec.push_back(Node{ 0,-1,-1 }); vec[cx].l = size_; size_++; }
				cx = vec[cx].l;
			}
			else {
				if (vec[cx].r == -1) { vec.push_back(Node{ 0,-1,-1 }); vec[cx].r = size_; size_++; }
				cx = vec[cx].r;
			}
		}
		vec[cx].num--;
	}
	long long min_xor(long long s) {
		if (vec[0].num == 0) return -1;
		int cx = 0; long long cur = 0;
		for (int i = 59; i >= 0; i--) {
			if ((s / (1LL << i)) % 2 == 0) {
				if (vec[cx].l >= 0 && vec[vec[cx].l].num >= 1) { cx = vec[cx].l; }
				else { cx = vec[cx].r; cur += (1LL << i); }
			}
			else {
				if (vec[cx].r >= 0 && vec[vec[cx].r].num >= 1) { cx = vec[cx].r; cur += (1LL << i); }
				else { cx = vec[cx].l; }
			}
		}
		return (s^cur);
	}
};

long long n, a[100009], p[100009]; vector<long long>F; long long ret = 0;
XORTree E[66];

int main() {
	cin >> n;
	for (int i = 0; i < 66; i++) E[i].init();
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		for (int j = 0; j < 60; j++) { if ((1LL << j) <= a[i]) p[i] = j; }
	}
	for (int i = 0; i < n; i++) E[p[i]].add(a[i]);

	for (int i = 0; i < n; i++) {
		bool OK = false;
		for (int j = 0; j < 60; j++) {
			if ((ret / (1LL << j)) % 2 == 1) continue;
			long long V = E[j].min_xor(ret);
			if (V != -1) { E[j].lose(V^ret); F.push_back(V^ret); ret = V; OK = true; break; }
		}
		if (OK == false) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	for (int i = 0; i < F.size(); i++) {
		if (i)cout << " ";
		printf("%lld", F[i]);
	}
	cout << endl;
	return 0;
}