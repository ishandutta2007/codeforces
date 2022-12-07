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
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

Vi t={0};
map<VPi,int> M;
int n,k;
VPi op(VPi &v)
{
	VPi p;
	for(auto P:v)p.pb(mp(P.X,k-P.Y));
	return p;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;;i++)
	{
		ll c=1;
		fup(j,1,k,1)
		{
			c*=i;
			if(c>100000)
			{
				c=-1;
				break;
			}
		}
		if(c==-1)break;
		t.pb(c);
	}
	fup(i,0,n-1,1)
	{
		ll x;
		scanf("%lld",&x);
		fup(k,2,(int)t.size()-1,1)
			while(x%t[k]==0)x/=t[k];
		VPi vv;
		for(int k=2;k*k<=x;k++)
		{
			if(x%k==0)
			{
				int cc=0;
				while(x%k==0)
				{
					cc++;
					x/=k;
				}
				vv.pb(mp(k,cc));
			}
		}
		if(x!=1)vv.pb(mp(x,1));
		M[vv]++;
	}
	ll ans=0;
	for(auto it=M.begin();it!=M.end();it++)
	{
		auto t=it->X;
		if(t.empty())ans+=1LL*it->Y*(it->Y-1);
		else 
		{
			auto vp=op(t);
			if(it->X==vp)ans+=1LL*it->Y*(it->Y-1);
			else ans+=1LL*it->Y*M[vp];
		}
	}
	printf("%lld",ans/2);
}