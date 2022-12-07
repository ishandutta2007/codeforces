#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#include<cassert>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 1987654321
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
typedef pair<double, double> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

map<ll,Vi> M;
VPll vv;
int cnt[4];
typedef vector<Vll> Matrix;
Matrix mat[8];
Matrix operator *(const Matrix& A, const Matrix& B)
{
	int n = A.size(), m = A[0].size();
	int N = B.size(), M = B[0].size();
	Matrix C= Matrix(n, Vll(M));
	if (m != N)return C;
	fup(i, 0, n - 1, 1)
	{
		fup(j, 0, M - 1, 1)
		{
			fup(k, 0, m - 1, 1)
			{
				C[i][j] = (C[i][j] + A[i][k] * B[k][j])%MOD;
			}
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
int main() {
	int n;
	ll m;
	scanf("%d%lld",&n,&m);
	fup(i,0,n-1,1)
	{
		int t;
		ll l,r;
		scanf("%d%lld%lld",&t,&l,&r);
		M[l].pb(t);
		M[r+1].pb(-t);
	}
	if(M.begin()->X !=2)vv.pb(mp(2,0));
	for(auto it=M.begin();it!=M.end();it++)
	{
		Vi &v=it->Y;
		for(int t:v)
		{
			if(t>0)cnt[t]++;
			else cnt[-t]--;
		}
		int c=0;
		fup(i,1,3,1)if(cnt[i]>0)c|=(1<<(i-1));
		vv.pb(mp(it->X,c));
	}
	Matrix res={{0,1,0}};
	mat[0]={{1,1,0},{1,1,1},{0,1,1}};
	mat[1]={{0,1,0},{0,1,1},{0,1,1}};
	mat[2]={{1,0,0},{1,0,1},{0,0,1}};
	mat[3]={{0,0,0},{0,0,1},{0,0,1}};
	mat[4]={{1,1,0},{1,1,0},{0,1,0}};
	mat[5]={{0,1,0},{0,1,0},{0,1,0}};
	mat[6]={{1,0,0},{1,0,0},{0,0,0}};
	mat[7]={{0,0,0},{0,0,0},{0,0,0}};
	vv.pb(mp(m+1,0));
	int N=vv.size();
	fup(i,0,N-2,1)
	{
		ll L=vv[i+1].X-vv[i].X;
		Matrix mu=mul(mat[vv[i].Y],L);
		res=res*mu;
	}
	printf("%lld",res[0][1]);
}