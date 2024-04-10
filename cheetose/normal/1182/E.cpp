#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<db> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

typedef vector<Vi> Matrix;
Matrix operator *(const Matrix& A, const Matrix& B)
{
	int n = A.size(), m = A[0].size();
	int N = B.size(), M = B[0].size();
	Matrix C= Matrix(n, Vi(M));
	if (m != N)return C;
	fup(i, 0, n - 1, 1)
	{
		fup(j, 0, M - 1, 1)
		{
			fup(k, 0, m - 1, 1)
				C[i][j] = (C[i][j] + 1LL * A[i][k] * B[k][j])%(MOD-1);
		}
	}
	return C;
}

Matrix mul(Matrix& A,ll k)
{
	if(k==1)return A;
	if(k&1)return mul(A,k-1)*A;
	Matrix t=mul(A,k/2);
	return t*t;
}
int main(){
	ll n,x,y,z,c;
	scanf("%lld%lld%lld%lld%lld",&n,&x,&y,&z,&c);
	n-=3;
	Matrix A(3,Vi(3));
	A={{1,1,0},{1,0,1},{1,0,0}};
	A=mul(A,n);
	ll aa=(x*c)%MOD;
	ll bb=(y*c)%MOD;
	bb=(bb*c)%MOD;
	ll cc=(z*POW(c,3))%MOD;
	aa=POW(aa,A[2][0]),bb=POW(bb,A[1][0]),cc=POW(cc,A[0][0]);
	ll ans=(aa*bb)%MOD;
	ans=(ans*cc)%MOD;
	ll t=POW(c,n+3);
	ans=(ans*POW(t,MOD-2))%MOD;
	printf("%lld\n",ans);
}