#include<cstdio>
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
#include<algorithm>
#include<list>
#include<functional>
#define mp make_pair
#define X first
#define Y second
#define INF 1987654321
#define PI 3.14159265358979323846264
#define MOD 1000000007LL
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
typedef complex<double> base;
ll POW(ll a, ll b) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1)) % MOD; ll t = POW(a, b / 2); return (t*t) % MOD; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int a[100001];
Vi v[100001];
int main()
{
	int n;
	scanf("%d", &n);
	fup(i, 0, n, 1)scanf("%d", a + i);
	bool ok = 1;
	int first = -1;
	fup(i, 1, n, 1)
	{
		if (a[i-1] != 1 && a[i]!=1)
		{
			ok = 0;
			first = i;
			break;
		}
	}
	if (ok)
	{
		puts("perfect");
		return 0;
	}
	else puts("ambiguous");
	int cnt = 0;
	fup(i, 0, n, 1)
	{
		int t = a[i];
		while(t--)
		{
			if (i == 0)printf("0 ");
			else printf("%d ", v[i - 1][0]);
			v[i].push_back(++cnt);
		}
	}
	puts("");
	fup(i, 0, n, 1)
	{
		int t = a[i];
		int N;
		if (i == 0)N = 1;
		else N = v[i - 1].size();
		fup(ii,0,t-1,1)
		{
			if (i == 0)printf("0 ");
			else printf("%d ", v[i - 1][(N-1)-(ii%N)]);
		}
	}
	puts("");
}