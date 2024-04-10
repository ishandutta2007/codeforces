#include <bits/stdc++.h>

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()
#define debug(x) cerr << #x" = " << x << endl

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;
typedef vector<int> VI;

template <typename T, typename TT> ostream & operator << (ostream &out, pair<T, TT> t) { return out << "(" << t.X << "," << t.Y << ")";}
template <typename T> ostream & operator << (ostream &out,vector<T> t) { out << "["; for (auto x:t) out << x << " "; out << "]"; return out;}
template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
template <typename T> void read(T & x) {
	int f = 1; char ch; x = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar(); x *= f;
}

const int mod = 1e9 + 7, KX = 32;
LL n; int K;

struct matrix {
	int x[KX][KX];
	int* operator [] (int p) {
		return x[p];
	}
	matrix operator * (const matrix & b) {
		matrix ans = {};
		for (int i = 0; i <= K; i++) {
			for (int j = 0; j <= K; j++) {
				for (int k = 0; k <= K; k++) {
					ans[i][j] = (ans[i][j] + (LL) x[i][k] * b.x[k][j]) % mod;
				}
			}
		} 
		return ans;
	}
}f[KX << 1][KX], p[KX], q[KX], ans; 


int main() {
	VI d; read(n); read(K);
	while(n) d.pb(n % K), n /= K;
	for (int i = 0; i < K; i++) {
		for (int j = 0; j <= K; j++) {
			f[0][i][j][j] = f[0][i][j][i] = 1;
		}
	}
	ans[0][K] = 1;
	for (int i = 1; i < SZ(d); i++) {
		p[0] = f[i - 1][0];
		for (int j = 1; j < K; j++)
			p[j] = p[j - 1] * f[i - 1][j];
		q[K - 1] = f[i - 1][K - 1];
		for (int j = K - 2; j >= 0; j--) {
			q[j] = f[i - 1][j] * q[j + 1];
		} 
		f[i][0] = q[0];
		for (int j = 1; j < K; j++)
			f[i][j] = q[j] * p[j - 1];
	}
	
	for (int i = SZ(d) - 1, l = 0; i >= 0; i--) 
		for (int j = 0; j < d[i]; j++, l++) {
			ans = ans * f[i][l % K];
		}
		
	int result = 0;
	for (int i = 0; i <= K; i++) 
		result = (result + ans[0][i]) % mod;
		
	cout << result << "\n";
	return 0;
}