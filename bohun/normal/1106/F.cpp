#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; n >= i; ++i)

using namespace std;
using namespace __gnu_pbds;

const int nax = 1e6 + 5, pod = (1 << 19), inf = 1e9 + 5, mod = 998244353;
const int N = 105;

int k;
int b[N];
int n, m;
int root = 3;

struct matrix {
	int t[N][N];
	matrix () {
		memset(t, 0, sizeof(t));
	}
	matrix operator * (const matrix x) {
		matrix res = matrix();
		for(int i = 0; i < N; ++i) 
			for(int k = 0; k < N; ++k) 
				for(int j = 0; j < N; ++j)
					res.t[i][j] = (res.t[i][j] + (ll) t[i][k] * x.t[k][j]) % (mod - 1);
		return res;
	}
	matrix Pow(matrix a, ll k) {
		matrix res = matrix();
		for(int i = 0; i < N; ++i) 
			res.t[i][i] = 1;
		while(k) {
			if(k & 1)
				res = res * a;
			a = a * a;
			k /= 2;
		}
		return res;
	}
	void Cat() {
		for(int i = 1; i <= k; ++i)  {
			for(int j = 1; j <= k; ++j)
				cout << t[i][j] << " ";
			cout << endl;
		}
	}
};

int pt(int a, ll b) {
	int res = 1;
	while(b) {
		if(b & 1)
			res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
		b /= 2;
	}
	return res;
}

map<int, int> mapka;

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> k;
	matrix M = matrix();
	for(int i = 1; i <= k; ++i) {
		cin >> M.t[k - i + 1][k];
		if(i != k)
			M.t[i + 1][i] = 1;
	}
		
	cin >> n >> m;
	matrix P = matrix();
	P.t[1][k] = 1;
	M = M.Pow(M, n - 1);
	P = P * M;
	int b = P.t[1][1];
	
	int pier = sqrt(mod) + 5;
	int A = pt(root, b);
	int C = m;
	
	for(int i = 0; i < pier; ++i) {
		int x = (ll) C * pt(A, i) % mod;
		mapka[x] = i;
	}
	for(int i = 1; i <= pier; ++i) {
		ll L = (ll) pier * i;
		L = pt(A, L);
		if(mapka.find(L) != mapka.end()) {
			int w = pier * i - mapka[L];
			cout << pt(root, w) % mod;
			return 0;
		}
	}
	cout << -1;
	
		
	
	
	
	
		
	
    return 0;
}