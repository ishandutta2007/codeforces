#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

template<typename A, typename B>
ostream& operator<<(ostream& out, const pair<A, B>& P) {
	out << "(" << P.first << ", " << P.second << ")";
	return out;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& vec) {
	out << "[";
	for (const T& x: vec) out << x << ", ";
	out << "]";
	return out;
}

#ifdef DEBUG
	ifstream in("input.txt");
	#define cin in
#endif



void solve() {
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++) cin >> a[i];
	int depth = 1;
	int curr = 0;
	int prev = 1;
	for (int i = 1; i < N; i++) {
		if (a[i-1] > a[i]) prev--;
		if (prev == 0) {
			prev = curr;
			curr = 0;
			depth++;
		}
		curr++;
	}
	cout << depth << "\n";
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) solve();
}