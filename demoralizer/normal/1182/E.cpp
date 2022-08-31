#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=0;

const int MOD = 1e9 + 6;
const long long MOD2 = static_cast<long long>(MOD) * MOD;

struct Matrix
{
	vector< vector<int> > mat;
	int n_rows, n_cols;

	Matrix() {}

	Matrix(vector< vector<int> > values): mat(values), n_rows(values.size()),
		n_cols(values[0].size()) {}

	static Matrix identity_matrix(int n)
	{
		vector< vector<int> > values(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			values[i][i] = 1;
		return values;
	}

	Matrix operator*(const Matrix &other) const 
	{
		int n = n_rows, m = other.n_cols;
		vector< vector<int> > result(n_rows, vector<int>(n_cols, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) {
				long long tmp = 0;
				for(int k = 0; k < n_cols; k++) {
					tmp += mat[i][k] * 1ll * other.mat[k][j];
					while(tmp >= MOD2)
						tmp -= MOD2;
				}
				result[i][j] = tmp % MOD;
			}

		return move(Matrix(move(result)));
	}

	inline bool is_square() const
	{
		return n_rows == n_cols;
	}
	
	void print(){
		for(auto &x:mat){
			for(int y:x){
				cout << y << " ";
			}
			cout << "\n";
		}
	}
};
Matrix pw(Matrix a,int p){
	Matrix result = Matrix::identity_matrix(a.n_cols);
	while (p > 0) {
		if (p & 1)
			result = a * result;
		a = a * a;
		p >>= 1;
	}
	return result;
}

int pw(int a,int p=M-2,int MOD=M){
	int result = 1;
	while (p > 0) {
		if (p & 1)
			result = a * result % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return result;
}

int f[100];

void solve(){
	int n,c;
	cin >> n >> f[1] >> f[2] >> f[3] >> c;
	
	if(n < 4){
		cout << f[n];
		return;
	}
	
	vector<vector<int>> m(3,vector<int>(3,0)),col(3,vector<int>(1,0));
	m[0][0] = m[0][1] = m[0][2] = 1;
	m[1][0] = 1;
	m[2][1] = 1;
	
	auto k = pw(m,n - 3);
	
	col[0][0] = 0;
	col[1][0] = 0;
	col[2][0] = 1;
	int f1pow = (k * col).mat[0][0];
	col[0][0] = 0;
	col[1][0] = 1;
	col[2][0] = 0;
	int f2pow = (k * col).mat[0][0];
	col[0][0] = 1;
	col[1][0] = 0;
	col[2][0] = 0;
	int f3pow = (k * col).mat[0][0];
	
	m.clear();
	col.clear();
	m = 
	{
		{1,1,1,2,MOD-4},
		{1,0,0,0,0},
		{0,1,0,0,0},
		{0,0,0,1,1},
		{0,0,0,0,1}
	};
	col =
	{
		{0},
		{0},
		{0},
		{3},
		{1}
	};
	
	int cpow = (pw(m,n-3) * col).mat[0][0];
	
	// cout << cpow << " " << f1pow << " " << f2pow << " " << f3pow << "\n";
	
	int ans = pw(c,cpow) * pw(f[1],f1pow) % M * pw(f[2],f2pow) % M * pw(f[3],f3pow) % M;
	cout << ans << "\n";
	
	
	// rep(i,4,n+1){
	// 	f[i] = f[i-1] % M * f[i-2] % M * f[i-3] % M;
	// }
	// f[n] = f[n] * pw(c,cpow) % M;
	// cout << f[n];
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}