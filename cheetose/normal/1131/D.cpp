#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
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
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
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
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int n,m;
char s[1000][1001];
int parent[2001],ans[2001],deg[2001];
bool chk[2001];
Vi v[2001];
int find(int a)
{
	if (parent[a] < 0)return a;
	return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a != b)
	{
		parent[a] += parent[b];
		parent[b] = a;
	}
}
int visit[2001];
bool Cycle(int N) {
	if (visit[N]) {
		if (visit[N] == -1) {
			return 1;
		}
		return 0;
	}
	visit[N] = -1;
	for (int next : v[N]) {
		if (Cycle(next)) {
			return 1;
		}
	}
	visit[N] = 1;
	return 0;
}
int main() {
	MEM_1(ans);
	MEM_1(parent);
	scanf("%d%d",&n,&m);
	fup(i,0,n-1,1)scanf("%s",s[i]);
	fup(i,0,n-1,1)fup(j,0,m-1,1)if(s[i][j]=='=')merge(i,j+n);
	fup(i,0,n-1,1)
		fup(j,0,m-1,1)
	{
		if(s[i][j]=='=')continue;
		int ii=find(i),jj=find(j+n);
		if(ii==jj)return !printf("No");
		if(s[i][j]=='>')v[jj].pb(ii),deg[ii]++;
		else v[ii].pb(jj),deg[jj]++;
	}
	fup(i,0,n+m-1,1)if(!visit[i] && Cycle(i))return !printf("No");
	puts("Yes");
	queue<int> q;
	fup(i,0,n+m-1,1)
	{
		int ii=find(i);
		if(deg[ii]==0 && !chk[ii])
		{
			ans[ii]=1;
			q.push(ii);
			chk[ii]=1;
		}
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int next:v[x])
		{
			deg[next]--;
			ans[next]=max(ans[next],ans[x]+1);
			if(deg[next]==0)q.push(next);
		}
	}
	fup(i,0,n-1,1)printf("%d ",ans[find(i)]);
	puts("");
	fup(i,n,n+m-1,1)printf("%d ",ans[find(i)]);
}