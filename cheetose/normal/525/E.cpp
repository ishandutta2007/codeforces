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
#define INF 987654321987654321
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

int n,k;
ll s,a[25],fac[19];
Vll v;
map<ll,Vi> M;
int main() {
	fac[0]=1;
	fup(i,1,18,1)fac[i]=fac[i-1]*i;
	scanf("%d%d%lld",&n,&k,&s);
	fup(i,0,n-1,1)
	{
		scanf("%lld",a+i);
		if(i>=n/2)v.pb(a[i]);
	}
	if(n==1)
	{
		int ans=0;
		if(a[0]<=18 && fac[a[0]]==s)ans++;
		if(a[0]==s)ans++;
		return !printf("%d",ans);
	}
	int N=v.size(),m=n/2;
	ll ans=0;
	M[0].pb(0);
	fup(i,1,(1<<m)-1,1)
	{
		ll ss=0;
		fup(k,0,m-1,1)
		{
			if(i&(1<<k))
				ss+=a[k];
		}
		if(ss==s)ans++;
		M[ss].pb(0);
		for(int j=i;j;j=(j-1)&i)
		{
			int cnt=0;
			ll sum=0;
			fup(k,0,m-1,1)
			{
				if(i&(1<<k))
				{
					if(j&(1<<k))
					{
						cnt++;
						if(a[k]<=18)sum+=fac[a[k]];
						else
						{
							cnt=-1;
							break;
						}
					}
					else sum+=a[k];
				}
			}
			if(cnt==-1)continue;
			if(sum==s&& cnt<=k)ans++;
			M[sum].pb(cnt);
		}
	}
	for(auto it=M.begin();it!=M.end();it++)sort(ALL(it->Y));
	fup(i,1,(1<<N)-1,1)
	{
		ll ss=0;
		fup(k,0,N-1,1)
		{
			if(i&(1<<k))
				ss+=v[k];
		}
		if(M.count(s-ss))
		{
			auto &it=M[s-ss];
			ans+=upper_bound(ALL(it),k)-it.begin();
		}
		for(int j=i;j;j=(j-1)&i)
		{
			int cnt=0;
			ll sum=0;
			fup(k,0,N-1,1)
			{
				if(i&(1<<k))
				{
					if(j&(1<<k))
					{
						cnt++;
						if(v[k]<=18)sum+=fac[v[k]];
						else
						{
							cnt=-1;
							break;
						}
					}
					else sum+=v[k];
				}
			}
			if(cnt==-1)continue;
			if(M.count(s-sum))
			{
				ll pre=ans;
				auto &it=M[s-sum];
				ans+=upper_bound(ALL(it),k-cnt)-it.begin();
			}
		}
	}
	printf("%lld",ans);
}