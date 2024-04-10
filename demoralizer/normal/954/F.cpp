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

const int MOD = 1e9 + 7;
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

const int N=1e4+5;



	Matrix m[8];
void solve(){
	rep(i,0,8){
		m[i].n_cols = m[i].n_rows = 3;
		m[i].mat.resize(3);
		rep(j,0,3) m[i].mat[j].resize(3);
	}
	m[7].mat[0][0] = m[7].mat[0][1] = m[7].mat[1][0] = m[7].mat[1][1] = m[7].mat[1][2] = m[7].mat[2][1] = m[7].mat[2][2] = 1;
	
	m[6].mat[1][1] = m[6].mat[1][2] = m[6].mat[2][1] = m[6].mat[2][2] = 1;
	
	m[5].mat[0][0] = m[5].mat[2][2] = 1;
	
	m[4].mat[2][2] = 1;
	
	m[3].mat[0][0] = m[3].mat[0][1] = m[3].mat[1][0] = m[3].mat[1][1] = 1;
	
	m[2].mat[1][1] = 1;
	
	m[1].mat[0][0] = 1;
	
	set<int> c;
	
	int n,mm;
	cin>>n>>mm;
	
	map<pii, int> add;
	
	rep(i,0,n){
		int a,l,r;
		cin>>a>>l>>r;
		c.insert(l);
		c.insert(l-1);
		c.insert(r);
		
		add[{l,a-1}]++;
		add[{r,a-1}]--;
	}
	c.insert(1);
	c.insert(mm);
	
	Matrix ans; ans.n_rows = 3; ans.n_cols = 1;
	ans.mat.resize(3);
	ans.mat[0].pb(0);
	ans.mat[1].pb(1);
	ans.mat[2].pb(0);
	
	int op[3] = {0,0,0};
	
	
	// rep(i,0,3){
	// 	rep(j,0,3){
	// 		cout<<m[0].mat[i][j]<<" ";
	// 	}
	// }
	
	int cur = 1, msk = 7;
	for(int x:c){
		ans = 
		pw(m[msk],x-cur)
		 * ans;
		
		rep(i,0,3){
			if(add.count({x,i})) ans.mat[i][0] = 0;
			op[i] += add[{x,i}];
		}
		msk = 0;
		rep(i,0,3){
			if(!op[i]) msk |= (1<<i);
		}
		cur = x;
	}
	cout<<ans.mat[1][0];
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