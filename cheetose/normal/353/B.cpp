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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

Vi v[101];
set<int> S[3];
int ans[201];
bool chk[101];
int main() {
	int n;
	scanf("%d", &n);
	fup(i, 0, 2 * n - 1, 1)
	{
		int x;
		scanf("%d", &x);
		v[x].push_back(i);
	}
	fup(i, 10, 99, 1)
	{
		if (v[i].size() >= 2)
		{
			chk[i] = 1;
			int t = v[i].back();
			ans[t] = 1;
			S[1].insert(i);
			v[i].pop_back();
			t = v[i].back();
			ans[t] = 2;
			S[2].insert(i);
			v[i].pop_back();
		}
	}
	int now = 1;
	fup(i, 10, 99, 1)
	{
		if (!chk[i] && !v[i].empty())
		{
			int t = v[i].back();
			v[i].pop_back();
			ans[t] = now;
			S[now].insert(i);
			now = 3 - now;
		}
	}
	fup(i, 10, 99, 1)
	{
		while (!v[i].empty())
		{
			int t = v[i].back();
			v[i].pop_back();
			ans[t] = now;
			now = 3 - now;
		}
	}
	printf("%d\n", S[1].size()*S[2].size());
	fup(i, 0, 2 * n - 1, 1)printf("%d ", ans[i]);
}