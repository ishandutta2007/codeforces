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
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
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
const int MOD = 5000000;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

bool chk[1000001];
int a[1000001];
int L[1000001], R[1000001];
int n, m, k;
void init()
{
	for (int i = 0; i < n; i++)
	{
		L[i] = i - 1;
		R[i] = i + 1;
	}
	R[n-1] = -1;
}
void del(int x)
{
	int l = L[x], r = R[x];
	if (r != -1)L[r] = l;
	if (l != -1)R[l] = r;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	init();
	fup(i, 0, m - 1, 1)
	{
		int x;
		scanf("%d", &x);
		if(x==0)return !printf("-1");
		chk[x] = 1;
		del(x);
	}
	fup(i, 1, k, 1)scanf("%d", a + i);
	ll ans = INF;
	fup(i, 1, k, 1)
	{
		ll temp = 0;
		int now = 0;
		for (; now < n; now += i)
		{
			if (chk[now])
			{
				if (L[now] == now - i)break;
				now = L[now];
			}
			temp += a[i];
		}
		if (now >= n && ans > temp)ans = temp;
	}
	if (ans == INF)ans = -1;
	printf("%lld", ans);
}