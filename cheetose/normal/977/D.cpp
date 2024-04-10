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
#define INF 987654321987654321
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
ll MOD = 12345678910;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

ll a[100];
Vi v[100];
int d[100];
int go(int N)
{
	int &ret = d[N];
	if (ret != -1)return ret;
	ret = 1;
	for (int next : v[N])ret = max(ret, 1 + go(next));
	return ret;
}
void track(int N)
{
	printf("%lld ", a[N]);
	int t = -1, next = -1;
	for (int nn : v[N])if (go(nn) > t)t = go(nn), next = nn;
	if(next!=-1)track(next);
}
int main() {
	MEM_1(d);
	int n;
	scanf("%d", &n);
	fup(i, 0, n - 1, 1)scanf("%lld", a + i);
	fup(i,0,n-1,1)
		fup(j, 0, n - 1, 1)
	{
		if (i == j)continue;
		if (a[i] % 3 == 0 && a[i] / 3 == a[j])
			v[i].push_back(j);
		else if (a[i] * 2 == a[j])
			v[i].push_back(j);
	}

	fup(i, 0, n - 1, 1)go(i);
	fup(i, 0, n - 1, 1)
		if (d[i] == n) {
			track(i);
			return 0;
		}
}