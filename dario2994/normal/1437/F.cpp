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

const LL mod = 998244353;

const int MAXN = 5100;
LL din[MAXN][MAXN];
LL don[MAXN][MAXN];
LL choose_ord[MAXN][MAXN];

void solve() {
	int N;
	cin >> N;
	for (int n = 0; n <= N; n++) {
		choose_ord[n][0] = 1;
		for (int k = 1; k <= n; k++) choose_ord[n][k] = choose_ord[n-1][k-1] * n % mod;
	}
	vector<int> a(N);
	for (int i = 0; i < N; i++) cin >> a[i];
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	a.push_back(0);
	reverse(a.begin(), a.end());
	vector<int> pp(N+1, 0);
	for (int i = 1; i <= N; i++) {
		pp[i] = 0;
		while (2*a[pp[i]+1] <= a[i]) pp[i]++;
	}
	
	for (int m = 0; m <= N; m++) din[0][m] = 1;
	for (int m = 1; m <= N; m++) {
		for (int k = 1; k <= m; k++) {
			din[k][m] = din[k][m-1];
			int p = pp[m];
			
			don[k][p] = don[k-1][p] * (p-k+2) % mod;
			// already computed this sum
			//~ for (int h = 0; h < min(p+1, k); h++) {
				//~ din[k][m] += din[h][p] * choose_ord[p-h][k-(h+1)] % mod; 
			//~ }
			for (int h = min(p+1, k-1); h < min(p+1, k); h++) {
				don[k][p] += din[h][p] * choose_ord[p-h][k-(h+1)] % mod; 
			}
			don[k][p] %= mod;
			din[k][m] += don[k][p];
			din[k][m] %= mod;
		}
	}
	cout << din[N][N] << "\n";
}

int main() {
	solve();
}