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
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//

bool beauti(int N)
{
	Vi v;
	while (N)
	{
		v.push_back(N&1);
		N >>= 1;
	}
	reverse(ALL(v));
	bool ok = 0;
	int cnt[2] = { 0 };
	for (int n : v)
	{
		if (ok && n == 1)return 0;
		if (n == 0)
		{
			ok = 1;
			cnt[0]++;
		}
		else cnt[1]++;
	}
	return cnt[1]-cnt[0]==1;
}
int main() {
	int n;
	scanf("%d", &n);
	Vi v;
	for (int i = 1; i *i <= n; i++)
	{
		if (n%i == 0)
		{
			v.push_back(i);
			v.push_back(n / i);
		}
	}
	sort(ALL(v));
	reverse(ALL(v));
	for (int n : v)
		if (beauti(n))
		{
			printf("%d", n);
			return 0;
		}
}
//freopen("input.txt", "r", stdin);