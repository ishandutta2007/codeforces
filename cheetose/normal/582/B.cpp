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
#define INF 987654321
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
const ll MOD = 1000000009;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

typedef vector<Vi> Matrix;
Matrix operator *(const Matrix& A, const Matrix& B)
{
	int n = A.size();
	Matrix C= Matrix(n, Vi(n));
	fup(i, 0, n - 1, 1)
	{
		fup(j, 0, n - 1, 1)
		{
			fup(k, i, j, 1)
				C[i][j] = max(C[i][j],A[i][k] + B[k][j]);
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
int n,t;
int a[100];
int d[100][300][300];
int go(int N,int now,int M)
{
	if(N==n)return 0;
	int &ret=d[N][now][M];
	if(ret!=-1)return ret;
	ret=go(N+1,now,M);
	if(a[N]>=now && a[N]<=M)ret=max(ret,1+go(N+1,a[N],M));
	return ret;
}
int main() {
	MEM_1(d);
	scanf("%d%d",&n,&t);
	fup(i,0,n-1,1)
	{
		scanf("%d",a+i);
		a[i]--;
	}
	Matrix A=Matrix(300,Vi(300));
	fup(i,0,299,1)fup(j,0,299,1)A[i][j]=go(0,i,j);
	A=mul(A,t);
	printf("%d",A[0][299]);
}