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
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

Vi v[1000000];
char s[1000][1002];
int visit[1000000],d[1000000];
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
int n,m;
int go(int N)
{
	int &ret=d[N];
	if(ret!=-1)return ret;
	ret=1;
	for(int next:v[N])
		ret=max(ret,1+go(next));
	return ret;
}
char ne(char c)
{
	if(c=='D')return 'I';
	if(c=='I')return 'M';
	if(c=='M')return 'A';
	if(c=='A')return 'D';
}
int main() {
	MEM_1(d);
	scanf("%d%d",&n,&m);
	fup(i,0,n-1,1)scanf("%s",s[i]);
	fup(x,0,n-1,1)
		fup(y,0,m-1,1)
	{
		fup(i,0,3,1)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&s[nx][ny]==ne(s[x][y]))
				v[x*m+y].pb(nx*m+ny);
		}
	}
	fup(i,0,n*m-1,1)
		if(!visit[i] && Cycle(i))return !printf("Poor Inna!");
	int ans=0;
	fup(i,0,n-1,1)
		fup(j,0,m-1,1)
		if(s[i][j]=='D')ans=max(ans,go(i*m+j));
	if(ans<4)return !printf("Poor Dima!");
	printf("%d",ans/4);
}