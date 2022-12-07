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

struct Matrix{
	ll a[2][2];
	Matrix() {
		MEM0(a);
	}
	Matrix operator+(Matrix x) {
		Matrix res;
		fup(i,0,1,1)fup(j,0,1,1)
				res.a[i][j] = (a[i][j] + x.a[i][j]) % MOD;
		return res;
	}
	Matrix operator*(Matrix x) {
		Matrix res;
		fup(i,0,1,1)
			fup(j,0,1,1)
			fup(k,0,1,1)
					res.a[i][j] = (res.a[i][j]+a[i][k] * x.a[k][j])%MOD;
		return res;
	}
	void i(){fup(i,0,1,1)fup(j,0,1,1)a[i][j]=(i==j);}
}A,I,O;
Matrix mul(Matrix &A,int k)
{
	if(k==1)return A;
	if(k&1)return A*mul(A,k-1);
	Matrix t=mul(A,k/2);
	return t*t;
}
Matrix tree[262144], lazy[262144];
int a[100001];
void init(int node, int S, int E)
{
	lazy[node].i();
	if (S == E)
	{
		tree[node]=mul(A,a[S]);
		return;
	}
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}
void upd(int node, int S, int E, int i, int j, Matrix tmp)
{
	if (i > E || j < S) return;
	if (j >= E && i <= S)
	{
		tree[node] = tree[node]*tmp;
		lazy[node]=lazy[node]*tmp;
		return;
	}
	upd(2 * node, S, (S + E) / 2, i, j,tmp);
	upd(2 * node + 1, (S + E) / 2 + 1, E, i, j,tmp);
	tree[node] = (tree[2 * node] + tree[2 * node + 1])*lazy[node];
}
Matrix find(int node, int S, int E, int i, int j)
{
	if (i > E || j < S) return O;
	if (j >= E && i <= S) return tree[node];
	return (find(node * 2, S, (S + E) / 2, i, j) + find(2 * node + 1, (S + E) / 2 + 1, E, i, j))*lazy[node];
}
int main() {
	A.a[0][0]=A.a[0][1]=A.a[1][0]=1;
	I.a[0][0]=I.a[1][1]=1;
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,1,n,1)scanf("%d",a+i);
	init(1,1,n);
	while(m--)
	{
		int o,l,r,k;
		scanf("%d%d%d",&o,&l,&r);
		if(o==1)
		{
			scanf("%d",&k);
			Matrix tmp=mul(A,k);
			upd(1,1,n,l,r,tmp);
		}
		else
		{
			printf("%lld\n",find(1,1,n,l,r).a[0][1]);
		}
	}
}