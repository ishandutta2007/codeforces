#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T>pair<T,T> operator+=(pair<T,T> &a,pair<T,T> b){a.fr+=b.fr;a.sc+=b.sc;return a;}
template<typename T>pair<T,T> operator-=(pair<T,T> &a,pair<T,T> b){a.fr-=b.fr;a.sc-=b.sc;return a;}
template<typename T>pair<T,T> operator+(pair<T,T> a,pair<T,T> b){a.fr+=b.fr;a.sc+=b.sc;return a;}
template<typename T>pair<T,T> operator-(pair<T,T> a,pair<T,T> b){a.fr-=b.fr;a.sc-=b.sc;return a;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

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
const int MOD = MM-1;
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

// M_powers[i] is M, raised to 2^i-th power
Matrix M_powers[61];

void precalc_powers(Matrix MT)
{
	assert(MT.is_square());
	M_powers[0] = MT;

	for(int i = 1; i < 61; i++)
		M_powers[i] = M_powers[i - 1] * M_powers[i - 1];
}

Matrix fast_exponentiation_with_precalc(int power)
{
	Matrix result = Matrix::identity_matrix(M_powers[0].mat.size());
	int pointer = 0;
	while(power) {
		if(power & 1)
			result = result * M_powers[pointer];
		pointer++;
		power >>= 1;
	}
	return result;
}

int gcd(int a, int b) {
    return a ? gcd(b % a, a) : b;
}

int powmod(int a, int b, int p) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

// Finds the primitive root modulo p
int generator(int p) {
    vector<int> fact;
    int phi = p-1, n = phi;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            fact.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        fact.push_back(n);

    for (int res = 2; res <= p; ++res) {
        bool ok = true;
        for (int factor : fact) {
            if (powmod(res, phi / factor, p) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return res;
    }
    return -1;
}


void solve(){
	int k;
	cin>>k;
	vector<vector<int>> v(k);
	rep(i,0,k){
		int b;
		cin>>b;
		v[0].pb(b);
	}
	rep(i,1,k){
		v[i].resize(k);
		v[i][i-1]=1;
	}
	Matrix mat(v);
	int n,m;
	cin>>n>>m;
	prc(mat);
	int r=mpw(n-k).mat[0][0];
	
	n=MM;
	k=r;
	int a=m;
	    int g = generator(n);

    // Baby-step giant-step discrete logarithm algorithm
    int sq = (int) sqrt (n + 0.0) + 1;
    vector<pair<int, int>> dec(sq);
    for (int i = 1; i <= sq; ++i)
        dec[i-1] = {powmod(g, i * sq * k % (n - 1), n), i};
    sort(dec.begin(), dec.end());
    int any_ans = -1;
    for (int i = 0; i < sq; ++i) {
        int my = powmod(g, i * k % (n - 1), n) * a % n;
        auto it = lower_bound(dec.begin(), dec.end(), make_pair(my, 0LL));
        if (it != dec.end() && it->first == my) {
            any_ans = it->second * sq - i;
		    int delta = (n-1) / gcd(k, n-1);
            int cur=any_ans%delta;
            cout<<powmod(g, cur, n);
            return;
        }
    }
    cout<<-1;
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
	#ifdef DSU
		cleardsu(MAXDSUSIZE);
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}