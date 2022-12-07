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
#define MOD 900528LL
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
typedef vector<iii> Viii;
typedef complex<double> base;
ll POW(ll a, ll b) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1)) % MOD; ll t = POW(a, b / 2); return (t*t) % MOD; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0)return b; if(b == 0)return a; return a*b / gcd(a, b); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

char s[300001];
Vi v[300000];
int visited[300000];
int cnt[300000][26];
int ind[300000];
bool Cycle(int here) {
	if (visited[here]) {
		if (visited[here] == -1) {
			return true;
		}
		return false;
	}

	visited[here] = -1;
	for (int there : v[here]) {
		if (Cycle(there)) {
			return true;
		}
	}
	visited[here] = 1;

	return false;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	fup(i, 0, m - 1, 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x-1].push_back(y-1);
		ind[y - 1]++;
	}
	fup(i, 0, n - 1, 1)
	{
		if (visited[i] == 0 && Cycle(i))
		{
			puts("-1");
			return 0;
		}
	}
	queue<int> q;
	fup(i, 0, n - 1, 1)
		if (ind[i] == 0)q.push(i);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cnt[x][s[x] - 'a']++;
		for (int next : v[x])
		{
			fup(i, 0, 25, 1)
				cnt[next][i] = max(cnt[next][i],cnt[x][i]);
			ind[next]--;
			if (ind[next] == 0)q.push(next);
		}
	}
	int ans = 0;
	fup(i, 0, n - 1, 1)
		fup(j, 0, 25, 1)
	{
		ans = max(ans, cnt[i][j]);
	}
	printf("%d", ans);
}