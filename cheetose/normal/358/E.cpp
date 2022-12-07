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

int a[1005][1005];
Vi R[1005], C[1005];
bool cc[1005][1005];
void bfs(int i, int j)
{
	queue<Pi> q;
	cc[i][j] = 1;
	q.push(mp(i, j));
	while (!q.empty())
	{
		int x = q.front().X, y = q.front().Y;
		q.pop();
		fup(i, 0, 3, 1)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (!cc[nx][ny] && a[nx][ny])
			{
				cc[nx][ny] = 1;
				q.push(mp(nx, ny));
			}
		}
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	fup(i, 1, n, 1)	fup(j, 1, m, 1)scanf("%d", &a[i][j]);
	int com = 0;
	fup(i,1,n,1)
		fup(j, 1, m, 1)
	{
		if (a[i][j] && !cc[i][j])
		{
			com++;
			bfs(i, j);
		}
	}
	if (com > 1)return !printf("-1");
	int cnt = 0;
	fup(x,1,n,1)
		fup(y, 1, m, 1)
	{
		if (!a[x][y])continue;
		int temp = 0;
		bool chk[4] = { 0 };
		fup(i, 0, 3, 1)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (a[nx][ny])
			{
				chk[i] = 1;
				temp++;
			}
		}
		cnt += (temp & 1);
		if ((temp&1) ||((chk[0] || chk[2]) && (chk[1] || chk[3])))
		{
			R[x].push_back(y);
			C[y].push_back(x);
		}
	}
	if (cnt > 2)return !printf("-1");
	Vi v;
	fup(i, 1, n, 1)
	{
		int N = R[i].size();
		fup(j, 1, N - 1, 1)
			v.push_back(R[i][j] - R[i][j - 1]);
	}
	fup(i, 1, m, 1)
	{
		int N = C[i].size();
		fup(j, 1, N - 1, 1)
			v.push_back(C[i][j] - C[i][j - 1]);
	}
	if (v.empty())return !printf("-1");
	sort(ALL(v));
	v.resize(unique(ALL(v)) - v.begin());
	int N = v.size();
	int g = v[0];
	fup(i, 1, N - 1, 1)g = gcd(g, v[i]);
	if (g == 1)return !printf("-1");
	fup(i, 2, g, 1)
		if (g%i == 0)printf("%d ", i);
}