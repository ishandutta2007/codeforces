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
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
ll MOD = 1999;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

ll a[100000], w[100000];
bool chk[100000];
int main() {
	int n;
	ll m;
	scanf("%d%lld", &n, &m);
	fup(i, 0, n - 1, 1)scanf("%lld", a + i);
	fup(i, 0, n - 1, 1)
	{
		scanf("%lld", w + i);
		w[i] *= (100 - a[i] % 100) % 100;
	}
	Vi v;
	ll t = -m;
	fup(i, 0, n - 1, 1)
	{
		t += a[i]%100;
		if (t > 0)
		{
			int c = (t + 99) / 100;
			while (v.size() < c)v.push_back(i);
		}
	}
	priority_queue<Pll, VPll, greater<Pll> >q;
	ll ans = 0;
	for (int i = 0, j = 0; i < (int)v.size(); i++)
	{
		while (j < n && j <= v[i])
		{
			if (w[j] > 0)q.push(mp(w[j], j));
			j++;
		}
		ans += q.top().X;
		chk[q.top().Y] = 1;
		q.pop();
	}
	printf("%lld\n", ans);
	fup(i, 0, n - 1, 1)
	{
		if (chk[i])printf("%lld 0\n", a[i] / 100 + 1);
		else printf("%lld %lld\n", a[i] / 100, a[i] % 100);
	}
	
}