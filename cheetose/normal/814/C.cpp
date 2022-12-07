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
ll MOD = 1000000007;
ll POW(ll a, ll b){ll ret = 1;for (; b; b >>= 1, a = (a*a) % MOD)if (b & 1)ret = (ret*a) % MOD; return ret;}
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if(a==0||b==0)return a+b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

char s[1501];
Vi v[26], a[26];
int n;
int res(int t, int c)
{
	int tl = v[c].back() - v[c][0] + 1;
	int tt = tl - v[c].size();
	if (t >= tt)
	{
		t -= tt;
		int ret = tl;
		return min(n, ret + t);
	}
	int l = 0, sum = 0, MAX = 1;
	int N = a[c].size();
	fup(i, 0, N - 1, 1)
	{
		sum += a[c][i];
		if (sum <= t)MAX = max(i - l + 2, MAX);
		else
		{
			while (sum > t)
			{
				sum -= a[c][l];
				l++;
			}
		}
	}
	return MAX + t;
}
int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	fup(i, 0, n - 1, 1)
	{
		v[s[i] - 'a'].push_back(i);
	}
	fup(i, 0, 25, 1)
	{
		if (v[i].size() <= 1)continue;
		fup(ii, 1, (int)v[i].size() - 1, 1)
		{
			a[i].push_back(v[i][ii] - v[i][ii - 1] - 1);
		}
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int t;
		char c;
		scanf("%d %c", &t, &c);
		int cc = c - 'a';
		if (v[cc].empty())printf("%d\n", t);
		else if (v[cc].size() == 1)printf("%d\n", min(n, t + 1));
		else printf("%d\n", res(t, cc));
	}
}