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

int a[1000001];
vector<Vi> v[1000001];
Vi cycle;
bool chk[1000001];
int ans[1000001];
void dfs(int N)
{
	cycle.pb(N);
	chk[N]=1;
	int next=a[N];
	if(!chk[next])dfs(next);
}
void upd(Vi &ve)
{
	int N=ve.size();
	fup(i,0,N-1,1)
		ans[ve[i]]=ve[(i+1)%N];
}
int main() {
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)scanf("%d",a+i);
	fup(i,1,n,1)
	{
		if(chk[i])continue;
		dfs(i);
		v[cycle.size()].pb(cycle);
		cycle.clear();
	}
	fup(i,1,n,1)
		if(i%2==0 && v[i].size()%2==1)return !printf("-1");
	fup(i,1,n,1)
	{
		if(i&1)
		{
			fup(j,0,(int)v[i].size()-1,1)
			{
				Vi vv;
				fup(k,0,i/2-1,1)
				{
					vv.pb(v[i][j][k]);
					vv.pb(v[i][j][(k+1)+i/2]);
				}
				vv.pb(v[i][j][i/2]);
				upd(vv);
			}
		}
		else
		{
			fup(j,0,(int)v[i].size()-1,2)
			{
				Vi vv;
				fup(k,0,i-1,1)
				{
					vv.pb(v[i][j][k]);
					vv.pb(v[i][j+1][k]);
				}
				upd(vv);
			}
		}
	}
	fup(i,1,n,1)printf("%d ",ans[i]);
}