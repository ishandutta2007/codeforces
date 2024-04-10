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
#define INF 2100000000
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

ll a[150000];
bool chk[150000];
map<ll, set<int> > M;
set<ll> S;
int main() {
	int n;
	scanf("%d", &n);
	fup(i, 0, n - 1, 1)
	{
		scanf("%lld", a + i);
		M[a[i]].insert(i);
		if (M[a[i]].size() == 2)S.insert(a[i]);
	}
	while (!S.empty())
	{
		ll x = *S.begin();
		auto it = M[x].begin();
		int t1 = *it;
		M[x].erase(it);
		it = M[x].begin();
		int t2 = *it;
		M[x].erase(it);
		chk[t1] = 1;
		a[t2] *= 2;
		M[a[t2]].insert(t2);
		if (M[a[t2]].size() == 2)S.insert(a[t2]);
		if (M[x].size() < 2)S.erase(S.begin());
	}
	int cnt = 0;
	fup(i, 0, n - 1, 1)if (!chk[i])cnt++;
	printf("%d\n", cnt);
	fup(i, 0, n - 1, 1)if (!chk[i])printf("%lld ", a[i]);
}