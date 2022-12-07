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

char s[5005];
ll d[5005][5005];
ll sum[5005];
int first=-1;
int n;
int main() {
	scanf("%d\n", &n);
	fup(i, 0, n - 1, 1)
		scanf("%c\n", &s[i]);
	fup(i, 0, n - 1, 1)
		if (s[i] == 'f')
		{
			first = i;
			break;
		}
	if (first == -1)
	{
		puts("1");
		return 0;
	}
	d[first][1] = 1;
	fup(i, first, n - 1, 1)
	{
		if (s[i] == 'f')
		{
			fup(j, 1, n, 1)
				d[i + 1][j + 1] = d[i][j];
		}
		else
		{
			fdn(j, n-1, 1, 1)
				sum[j] = (sum[j + 1] + d[i][j]) % MOD;
			fup(j, 1, n, 1)
				d[i + 1][j] = sum[j];
		}
	}
	ll ans = 0;
	fup(i, 1, n, 1)
		ans = (ans + d[n-1][i])%MOD;
	printf("%I64d", ans);
}