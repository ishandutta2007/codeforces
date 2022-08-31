#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
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

/*
  prc(Matrix):    pre-calculates Matrix^(1<<i)
  mpw(int):       returns the power based on pre-calculation
  constructor:    Matrix <identifier>(vector<vector<int>>)
  * operator is overloaded for multiplication
  Matrix.mat[i][j] gives the element
*/
#define prc precalc_powers
#define mpw fast_exponentiation_with_precalc
const int MOD = 1e9 + 7;
const long long MOD2 = static_cast<long long>(MOD) * MOD;
const int MAX_K = 50;

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
};

Matrix pw(Matrix a,int p){
	Matrix result = Matrix::identity_matrix(a.mat.size());
	while (p > 0) {
		if (p & 1)
			result = a * result;
		a = a * a;
		p >>= 1;
	}
	return result;
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> v(m,vector<int>(m));
	rep(i,0,m){
		rep(j,0,m){
			if(j==i+1){
				v[i][j]=1;
			}
			if(i==m-1){
				if(j==0 || j==m-1){
					v[i][j]=1;
				}
			}
		}
	}
	
	Matrix k(v);
	vector<vector<int>> x(m,vector<int>(1,1));
	cout<<(pw(k,n)*Matrix(x)).mat[0][0];
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}