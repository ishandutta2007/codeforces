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
#define INF 987654321
#define PI 3.14159265358979323846264
#define MOD 900528LL
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
ll POW(ll a, ll b, ll p) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1, p)) % p; ll t = POW(a, b / 2, p); return (t*t) % p; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0)return b; if (b == 0)return a; return a*b / gcd(a, b); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int a[201];
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		MEM0(a);
		int n, k;
		scanf("%d%d", &n, &k);
		while (k--)
		{
			int x;
			scanf("%d", &x);
			a[x] = 1;
		}
		queue<int> q;
		fup(i, 1, n, 1)
			if (a[i] == 1)q.push(i);
		int ans = 1;
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			if (x - 1 != 0 && a[x - 1] == 0)
			{
				a[x - 1] = a[x] + 1;
				q.push(x - 1);
			}
			if (x + 1 <=n && a[x + 1] == 0)
			{
				a[x + 1] = a[x] + 1;
				q.push(x + 1);
			}
		}
		fup(i, 1, n, 1)
			ans = max(ans, a[i]);
		printf("%d\n", ans);
	}
}