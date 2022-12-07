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
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM){ll ret = 1;for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret;}
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if(a==0||b==0)return a+b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

VPll v[200001];
ll dist[200001];
bool chk[200001];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	fup(i, 0, m - 1, 1)
	{
		ll x, y, z;
		scanf("%I64d%I64d%I64d", &x, &y, &z);
		z *= 2;
		v[x].push_back(Pll(y, z));
		v[y].push_back(Pll(x, z));
	}
	priority_queue<Pll, VPll, greater<Pll> > q;
	fup(i, 1, n, 1)
	{
		scanf("%I64d", dist + i);
		q.push(Pll(dist[i], i));
	}
	while (!q.empty())
	{
		Pll pp = q.top();
		q.pop();
		int x = pp.Y;
		if (chk[x])continue;
		chk[x] = 1;
		for (const auto& p : v[x])
		{
			ll next = p.X, cost = p.Y;
			if (dist[next] > dist[x] + cost)
			{
				dist[next] = dist[x] + cost;
				q.push(mp(dist[next], next));
			}
		}
	}
	fup(i, 1, n, 1)printf("%I64d ", dist[i]);
}