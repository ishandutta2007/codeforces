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
#define INF 987654321987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
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
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

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
int a[10];
int main() {
	int n,b,k,x;
	scanf("%d%d%d%d",&n,&b,&k,&x);
	fup(i,0,n-1,1)
	{
		int y;
		scanf("%d",&y);
		a[y]++;
	}
	Matrix d(x,Vll(x));
	fup(i,0,x-1,1)
	{
		fup(t,1,9,1)
			d[i][(10*i+t)%x]=(d[i][(10*i+t)%x]+a[t])%MOD;
	}
	d=mul(d,b);
	printf("%lld",d[0][k]);
}