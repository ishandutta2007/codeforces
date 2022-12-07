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
#define MOD 1000000007LL
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
typedef complex<double> base;
ll POW(ll a, ll b) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1)) % MOD; ll t = POW(a, b / 2); return (t*t) % MOD; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//

bool chk[2000001];
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	fup(i, 0, n - 1, 1)
	{
		int x;
		scanf("%d", &x);
		chk[x] = 1;
	}
	int ans = 0, cnt = 0;
	fup(i, 1, m, 1)
	{
		if (chk[i])cnt++;
		if (cnt == k)
		{
			cnt--;
			chk[i] = 0;
			ans++;
		}
	}
	int l = 1, r = m;
	while (l <= 1000000)
	{
		l++, r++;
		if (chk[l - 1])cnt--;
		if (chk[r])cnt++;
		if (cnt == k)
		{
			cnt--;
			chk[r] = 0;
			ans++;
		}
	}
	printf("%d", ans);
}