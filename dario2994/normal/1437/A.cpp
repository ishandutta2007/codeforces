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
	LL l, r;
	cin >> l >> r;
	//~ LL x = r+1;
	if (2*l >= r+1) cout << "YES\n";
	else cout << "NO\n";
	//~ LL x = (r+2)/2;
	//~ cout << x << endl;
	//~ if (2*l >= 3*x) cout << "YES\n";
	//~ else cout << "NO\n";
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) solve();
}