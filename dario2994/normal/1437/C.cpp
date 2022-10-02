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


const int MAXN = 210;
int din[MAXN][2*MAXN];

void solve() {
	int N;
	cin >> N;
	vector<int> t(N);
	for (int i = 0; i < N; i++) cin >> t[i];
	
	sort(t.begin(), t.end());
	int P = 2*N+1;
	for (int i = 1; i <= N; i++) { // how many
		din[i][0] = 1e9;
		for (int p = 1; p <= P; p++) { // last pos
			din[i][p] = 1e9;
			for (int q = 0; q < p; q++) {
				int ris = 1e9;
				if (q < t[i-1] and t[i-1] <= p) ris = din[i-1][q];
				if (t[i-1] <= q) ris = din[i-1][q] + abs(q+1-t[i-1]);
				if (p < t[i-1]) ris = din[i-1][q] + abs(p-t[i-1]);
				din[i][p] = min(din[i][p], ris);
			}
		}
	}
	cout << din[N][P] << "\n";
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) solve();
}