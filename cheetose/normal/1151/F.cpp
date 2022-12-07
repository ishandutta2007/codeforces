#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321
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
typedef vector<ld> Vd;
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

typedef vector<Vll> Matrix;
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
				C[i][j] = (C[i][j] + A[i][k] * B[k][j])%MOD;
		}
	}
	return C;
}

Matrix mul(Matrix& A,int k)
{
	if(k==1)return A;
	if(k&1)return mul(A,k-1)*A;
	Matrix t=mul(A,k/2);
	return t*t;
}
int c0,c1;
int a[100];
int n,K;
int main(){
	scanf("%d%d",&n,&K);
	fup(i,0,n-1,1)scanf("%d",a+i);
	fup(i,0,n-1,1)
	{
		if(a[i]==0)c0++;
		else c1++;
	}
	ll p,q=n*(n-1)/2;
	q=POW(q,K);
	int T=min(c0,c1);
	Matrix A=Matrix(T+1,Vll(T+1));
	fup(k,0,T,1)
	{
		if(k<T)A[k][k+1]=(c0-k)*(c1-k);
		A[k][k]=(c0-k)*k+(c1-k)*k+c0*(c0-1)/2+c1*(c1-1)/2;
		if(k>0)A[k][k-1]=k*k;
	}
	A=mul(A,K);
	int k=0;
	fup(i,0,c0-1,1)if(a[i]==1)k++;
	p=A[k][0];
	printf("%lld\n",(p*POW(q,MOD-2))%MOD);
}