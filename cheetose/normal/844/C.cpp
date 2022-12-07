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
typedef tuple<int, int, int> iii;
typedef vector<iii> Viii;
typedef complex<double> base;
ll POW(ll a, ll b) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1)) % MOD; ll t = POW(a, b / 2); return (t*t) % MOD; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return gcd(a, b); return a*b / gcd(a, b); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int temp[100000], a[100000];
int group[100000];
Vi g[100000];
int gg;
map<int, int> M;
void dfs(int N)
{
	group[N] = gg;
	g[gg].push_back(N);
	int next = a[N];
	if (group[next] == -1)dfs(next);
}
int main() {
	MEM_1(group);
	int n;
	scanf("%d", &n);
	fup(i, 0, n - 1, 1)
	{
		scanf("%d", temp + i);
		a[i] = temp[i];
	}
	sort(temp, temp + n);
	fup(i, 0, n - 1, 1)
		M[temp[i]] = i;
	fup(i, 0, n - 1, 1)
		a[i] = M[a[i]];
	fup(i, 0, n - 1, 1)
	{
		if (group[i] == -1)
		{
			dfs(i);
			gg++;
		}
	}
	printf("%d\n", gg);
	fup(i, 0, gg - 1, 1)
	{
		printf("%d ", g[i].size());
		for (int x : g[i])printf("%d ", x+1);
		puts("");
	}
}