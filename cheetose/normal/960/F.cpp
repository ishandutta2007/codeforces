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
ll MOD = 1000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

iii e[100000];
int d[100000];
set<Pi> S[100001];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	fup(i, 1, n, 1)S[i].insert(mp(-1, 0));
	fup(i, 0, m - 1, 1)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		e[i] = iii(z, x, y);
	}
	fup(i, 0, m - 1, 1)
	{
		int z, x, y;
		tie(z, x, y) = e[i];
		auto it = S[x].lower_bound(mp(z, -1));
		it--;
		d[i] = it->Y + 1;
		auto it2 = S[y].lower_bound(mp(z, -1));
		it2--;
		if (d[i] > it2->Y)
		{
			it = it2;
			it++;
			while (it != S[y].end())
			{
				if (it->Y > d[i])break;
				S[y].erase(it);
				it = it2;
				it++;
			}
			S[y].insert(mp(z, d[i]));
		}
	}
	printf("%d", *max_element(d, d + m));
}