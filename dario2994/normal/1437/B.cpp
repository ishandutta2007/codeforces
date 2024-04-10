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
	string S;
	cin >> S;
	int res = 0;
	for (int i = 0; i < N; i++) {
		res += S[i] == S[(i+1)%N];
	}
	cout << res/2 << "\n";
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) solve();
}