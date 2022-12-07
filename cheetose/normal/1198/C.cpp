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
#define INF 987654321987654321
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
typedef pair<ld, ld> Pd;
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

bool chk[300001];
VPi v[300001];
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,1,3*n,1)
	{
		chk[i]=0;
		v[i].clear();
	}
	fup(i,1,m,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(mp(y,i));
		v[y].pb(mp(x,i));
	}
	Vi a,b;
	fup(i,1,3*n,1)
	{
		if(chk[i])continue;
		Pi p=mp(-1,-1);
		for(auto P:v[i])
		{
			if(!chk[P.X])p=P;
		}
		if(p.X!=-1)
		{
			chk[i]=chk[p.X]=1;
			b.pb(p.Y);
		}
		else
		{
			chk[i]=1;
			a.pb(i);
		}
	}
	if(a.size()>b.size())
	{
		puts("IndSet");
		fup(i,0,n-1,1)printf("%d ",a[i]);
		puts("");
	}
	else
	{
		puts("Matching");
		fup(i,0,n-1,1)printf("%d ",b[i]);
		puts("");
	}
}
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}