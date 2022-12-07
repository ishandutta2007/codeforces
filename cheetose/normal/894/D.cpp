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
#define INF 987654321
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
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

ll dist[1000001];
Vll v[2000001],sum[1000001];
int n,q;
void init(int N)
{
	if(N>n)return;
	v[N].pb(dist[N]);
	init(2*N);
	init(2*N+1);
	Vll &v1=v[2*N],&v2=v[2*N+1];
	int i=0, j=0, nn=v1.size(), mm=v2.size();
	while (1)
	{
		if (i == nn && j == mm)break;
		if (i == nn) v[N].push_back(v2[j++]);
		else if (j == mm)v[N].push_back(v1[i++]);
		else if (v1[i] > v2[j]) v[N].push_back(v2[j++]);
		else v[N].push_back(v1[i++]);
	}
}
int main() {
	scanf("%d%d",&n,&q);
	fup(i,1,n-1,1)
	{
		ll x;
		scanf("%lld",&x);
		dist[i+1]=dist[(i+1)/2]+x;
	}
	init(1);
	fup(i,1,n,1)
	{
		sum[i].pb(0);
		fup(j,0,(int)v[i].size()-1,1)
			sum[i].pb(sum[i].back()+v[i][j]);
	}
	while(q--)
	{
		int x;
		ll h;
		scanf("%d%lld",&x,&h);
		ll ans=0;
		int t=upper_bound(ALL(v[x]),h+dist[x])-v[x].begin();
		ans+=t*(h+dist[x])-sum[x][t];
		bool L;
		while(1)
		{
			L=(x%2==0);
			h-=dist[x]-dist[x/2];
			if(h<0)break;
			x/=2;
			if(x==0)break;
			ans+=h;
			if(L)
			{
				t=upper_bound(ALL(v[x*2+1]),h+dist[x])-v[x*2+1].begin();
				if(t)ans+=t*(h+dist[x])-sum[x*2+1][t];
			}
			else
			{
				t=upper_bound(ALL(v[x*2]),h+dist[x])-v[x*2].begin();
				if(t)ans+=t*(h+dist[x])-sum[x*2][t];
			}
		}
		printf("%lld\n",ans);
	}
}