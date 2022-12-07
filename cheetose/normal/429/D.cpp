#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
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
#define INF 987654321987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
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
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int n;
Pll a[100001];
inline ll dist(int i, int j)
{
	return (a[i].X - a[j].X)*(a[i].X - a[j].X) + (a[i].Y - a[j].Y)*(a[i].Y - a[j].Y);
}
bool f(Pi p1, Pi p2)
{
	return p1.Y < p2.Y;
}
ll find(int S, int E)
{
	if (E - S <= 2)
	{
		ll temp = INF;
		for (int i = S; i < E; i++)
			for (int j = i + 1; j <= E; j++)
				temp = min(temp, dist(i, j));
		return temp;
	}
	int m = (S + E) / 2;
	ll t = min(find(S, m), find(m + 1, E));
	VPll temp;
	for (int i = S; i <= E; i++)
	{
		ll d = (a[i].X - a[m].X) * (a[i].X - a[m].X);
		if (d < t)temp.push_back(a[i]);
	}
	int N = temp.size();
	sort(temp.begin(), temp.end(), f);
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			ll d = (temp[i].Y - temp[j].Y)*(temp[i].Y - temp[j].Y);
			if (d < t)
			{
				ll dd = (temp[i].X - temp[j].X)*(temp[i].X - temp[j].X) + (temp[i].Y - temp[j].Y)*(temp[i].Y - temp[j].Y);
				t = min(t, dd);
			}
			else break;
		}
	}
	return t;
}
int main() {
	scanf("%d",&n);
	fup(i,1,n,1)
	{
		ll x;
		scanf("%lld",&x);
		a[i].Y=x+a[i-1].Y;
		a[i].X=i;
	}
	printf("%lld",find(1,n));
}