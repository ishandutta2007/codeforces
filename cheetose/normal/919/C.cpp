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
ll POW(ll a, ll b) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1)) % MOD; ll t = POW(a, b / 2); return (t*t) % MOD; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0)return b; if(b == 0)return a; return a*b / gcd(a, b); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

char s[2000][2001];
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m,&k);
	fup(i, 0, n - 1, 1)scanf("%s", s[i]);
	if (k == 1)
	{
		int ans = 0;
		fup(i, 0, n - 1, 1)
			fup(j, 0, m - 1, 1)
			if (s[i][j] == '.')ans++;
		printf("%d", ans);
		return 0;
	}
	Vi v;
	fup(i, 0, n - 1, 1)
	{
		int cnt = 0;
		fup(j, 0, m - 1, 1)
		{
			if (s[i][j] == '.')cnt++;
			else
			{
				if(cnt>=k)v.push_back(cnt);
				cnt = 0;
			}
		}
		if (cnt >= k)v.push_back(cnt);
	}
	fup(j, 0, m - 1, 1)
	{
		int cnt = 0;
		fup(i, 0, n - 1, 1)
		{
			if (s[i][j] == '.')cnt++;
			else
			{
				if (cnt >= k)v.push_back(cnt);
				cnt = 0;
			}
		}
		if (cnt >= k)v.push_back(cnt);
	}
	ll ans = 0;
	for (int x : v)ans += x - k + 1;
	printf("%lld", ans);
}