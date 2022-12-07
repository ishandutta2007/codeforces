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
#define INF 987654321987654231
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
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

Vll v[4];
LLL d[300001];
ll a[300001];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,1,3,1)v[i].pb(INF);
	fup(i,0,n-1,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
	}
	fup(i,1,3,1)sort(v[i].rbegin(),v[i].rend());
	fup(i,1,3,1)v[i][0]=0;
	fup(i,1,3,1)
		fup(j,1,(int)v[i].size()-1,1)v[i][j]+=v[i][j-1];
	int N=v[1].size(),M=v[2].size();
	fup(i,0,299999,1)
	{
		ll z,x,y;
		tie(z,x,y)=d[i];
		if(x+1<N)d[i+1]=max(d[i+1],LLL(v[1][x+1]+v[2][y],x+1,y));
		if(y+1<M)d[i+2]=max(d[i+2],LLL(v[1][x]+v[2][y+1],x,y+1));
	}
	fup(i,1,300000,1)a[i]=max(a[i-1],get<0>(d[i]));
	ll ans=0;
	fup(i,0,(int)v[3].size()-1,1)
	{
		if(m-3*i>=0)ans=max(ans,v[3][i]+a[m-3*i]);
	}
	printf("%lld",ans);
}