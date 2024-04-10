#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#define mp make_pair
#define X first
#define Y second
#define INF 987654321
#define PI 3.14159265358979323846264
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
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
typedef vector<iii> Viii;
typedef complex<double> base;
int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM){ll ret = 1;for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret;}
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if(a==0||b==0)return a+b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int d[1000001];
int sum[10][1000001];
int go(int N)
{
	if (N < 10)return N;
	int &ret = d[N];
	if (ret != -1)return ret;
	int c = 1;
	while (N)
	{
		if (N % 10 != 0)c *= N % 10;
		N /= 10;
	}
	return ret = go(c);
}
int main()
{
	MEM_1(d);
	fup(j, 1, 1000000, 1)
	{
		fup(i, 1, 9, 1)sum[i][j] = sum[i][j - 1];
		int t = go(j);
		sum[t][j]++;
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", sum[k][r] - sum[k][l - 1]);
	}
}