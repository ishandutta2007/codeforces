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
const ll MOD1 = 1000000009;
const ll MOD2 = 1000000021;
//ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

char s[1000005];
bool chk[1000005];
ll h1[1000005],h2[1000005],p1[1000005],p2[1000005];
Pll has(int l,int r)
{
	int L=r-l+1;
	ll t=(h1[l-1]*p1[L])%MOD1;
	ll x=(h1[r]-t+MOD1)%MOD1;
	t=(h2[l-1]*p2[L])%MOD2;
	ll y=(h2[r]-t+MOD2)%MOD2;
	return mp(x,y);
}
int main() {
	int n,k;
	scanf("%d%d%s",&n,&k,s+1);
	p1[0]=p2[0]=1;
	fup(i,1,1000000,1)
	{
		p1[i]=(p1[i-1]*37)%MOD1;
		p2[i]=(p2[i-1]*29)%MOD2;
	}
	fup(i,1,n,1)
	{
		h1[i]=(h1[i-1]*37+s[i]-'a'+1)%MOD1;
		h2[i]=(h2[i-1]*29+s[i]-'a'+1)%MOD2;
	}
	VPi VV;
	for(int t=1;t*k<=n;t++)
	{
		bool ok=1;
		Pll H=has(1,t);
		fup(iii,1,k,1)
		{
			if(H!=has((iii-1)*t+1,iii*t))ok=0;
		}
		if(ok)
		{
			chk[t*k]=1;
			int l=t*k+1,r=min(n,t*k+t);
			while(l<=r)
			{
				int K=(l+r)>>1;
				if(has(t*k+1,K)==mp(h1[K-t*k],h2[K-t*k]))l=K+1;
				else r=K-1;
			}
			if(r!=t*k)VV.pb(mp(t*k+1,r));
		}
	}
	sort(ALL(VV));
	int p=1;
	for(auto PP:VV)
	{
		if(p<PP.X)p=PP.X;
		while(p<=PP.Y)chk[p++]=1;
	}
	fup(i,1,n,1)printf("%d",chk[i]);
}