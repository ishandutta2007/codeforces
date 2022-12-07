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
#include<cassert>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define INF 1000000005
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
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
int MOD = 10000;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

ll cal(const Vll& v)
{
	Vll dif;
	ll res = 0;
	int n = v.size();
	fup(i, 1, n - 1, 1)
		dif.push_back(v[i] - v[i - 1]);
	sort(ALL(dif));
	fup(i, 0, n - 3, 1) res += dif[i];
	return res;
}
int main() {
	deque<int> r, b, p;
	int n;
	scanf("%d", &n);
	ll ans = 0;
	fup(i, 0, n - 1, 1)
	{
		int x;
		char c;
		scanf("%d %c", &x, &c);
		if (c == 'P')p.push_back(x);
		if (c == 'B')b.push_back(x);
		if (c == 'R')r.push_back(x);
	}
	if (p.empty())
	{
		if (!r.empty())ans += r.back() - r.front();
		if (!b.empty())ans += b.back() - b.front();
		return !printf("%lld", ans);
	}
	if (!r.empty() && r.front() < p.front())
	{
		ans += p.front() - r.front();
		while (!r.empty() && r.front() < p.front())r.pop_front();
	}
	if (!r.empty() && r.back() > p.back())
	{
		ans += r.back() - p.back();
		while (!r.empty() && r.back() > p.back())r.pop_back();
	}
	if (!b.empty() && b.front() < p.front())
	{
		ans += p.front() - b.front();
		while (!b.empty() && b.front() < p.front())b.pop_front();
	}
	if (!b.empty() && b.back() > p.back())
	{
		ans += b.back() - p.back();
		while (!b.empty() && b.back() > p.back())b.pop_back();
	}
	fup(i, 1, (int)p.size() - 1, 1)
	{
		Vll R, B;
		R.push_back(p[i - 1]);
		B.push_back(p[i - 1]);
		while (!r.empty() && r.front() < p[i])
		{
			R.push_back(r.front());
			r.pop_front();
		}
		while (!b.empty() && b.front() < p[i])
		{
			B.push_back(b.front());
			b.pop_front();
		}
		R.push_back(p[i]);
		B.push_back(p[i]);
		ll temp = p[i] - p[i - 1];
		temp += cal(B) + cal(R);
		ans += min(temp, (p[i] - p[i - 1]) * 2LL);
	}
	printf("%lld", ans);
}