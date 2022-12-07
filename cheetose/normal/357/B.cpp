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
#define INF (ll)1e17
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
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

Vi v[100001];
int ans[100001];
bool chk[100001];
void bfs(int N)
{
	queue<int> q;
	q.push(N);
	chk[N] = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		int temp = 0;
		for (int next : v[x])
		{
			if (ans[next] != 0)temp |= (1 << ans[next]);
			else if (!chk[next])
			{
				q.push(next);
				chk[next] = 1;
			}
		}
		fup(i, 1, 3, 1)
		{
			if (temp&(1 << i))continue;
			ans[x] = i;
			break;
		}
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		v[x].push_back(y);
		v[x].push_back(z);
		v[y].push_back(x);
		v[y].push_back(z);
		v[z].push_back(x);
		v[z].push_back(y);
	}
	fup(i, 1, n, 1)if (!chk[i])bfs(i);
	fup(i, 1, n, 1)printf("%d ", ans[i]);
}