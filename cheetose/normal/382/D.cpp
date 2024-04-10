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
#define y0 y12
#define y1 y22
#define INF 1987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
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
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

char s[2000][2001];
int n,m,ind[4000000];
Vi v[4000000],res;
bool chk[4000000];
int dfs(int N)
{
	chk[N]=1;
	int res=0;
	for(int next:v[N])
	{
		if(chk[next])
		{
			puts("-1");
			exit(0);
		}
		res=max(res,dfs(next));
	}
	return res+1;
}
inline int z(int x,int y){return x*m+y;}
int main() {
	scanf("%d%d",&n,&m);
	fup(i,0,n-1,1)scanf("%s",s[i]);
	int c=0;
	fup(i,1,n-2,1)
	{
		fup(j,1,m-2,1)
		{
			if(s[i][j]!='#')c++;
			if(s[i][j]=='<')
			{
				if(s[i][j-1]!='#')
				{
					v[z(i,j-1)].pb(z(i,j));
					ind[z(i,j)]++;
				}
			}
			if(s[i][j]=='>')
			{
				if(s[i][j+1]!='#')
				{
					v[z(i,j+1)].pb(z(i,j));
					ind[z(i,j)]++;
				}
			}
			if(s[i][j]=='^')
			{
				if(s[i-1][j]!='#')
				{
					v[z(i-1,j)].pb(z(i,j));
					ind[z(i,j)]++;
				}
			}
			if(s[i][j]=='v')
			{
				if(s[i+1][j]!='#')
				{
					v[z(i+1,j)].pb(z(i,j));
					ind[z(i,j)]++;
				}
			}
		}
	}
	if(c<=1)return !printf("%d",c);
	fup(i,0,n-1,1)
		fup(j,0,m-1,1)
		if(s[i][j]!='#' && ind[z(i,j)]==0)res.pb(dfs(z(i,j)));
	fup(i,0,n-1,1)
		fup(j,0,m-1,1)
		if(s[i][j]!='#' && !chk[z(i,j)])return !printf("-1");
	sort(res.rbegin(),res.rend());
	int ans=res[0]*2-1;
	if(res.size()>1)ans=max(ans,res[0]+res[1]);
	printf("%d",ans);
}