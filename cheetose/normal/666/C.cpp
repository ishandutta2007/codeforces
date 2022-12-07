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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int c[100001],cc;
char s[100005];
ll pow25[100001],pow26[100001],inv26[100001];
Vi v[450];
ll fac[100001];
ll inv[100001];
ll nCr(int n, int r)
{
	if(r>n)return 0;
	ll c = fac[n];
	c = (c*inv[r]) % MOD;
	c = (c*inv[n - r]) % MOD;
	return c;
}
void add(ll &a,ll b){a=(a+b)%MOD;}
ll mul(ll a,ll b){return (a*b)%MOD;}
void upd(int l)
{
	fup(i,0,l-1,1)v[cc].pb(0);
	ll sum=0;
	fup(k,l,100000,1)
	{
		ll t=mul(nCr(k-1,l-1),pow25[k-l]);
		t=mul(t,inv26[k]);
		add(sum,t);
		v[cc].pb(mul(sum,pow26[k]));
	}
	cc++;
}
int main() {
	pow26[0]=pow25[0]=1;
	inv26[0]=1;
	fup(i,1,100000,1)
	{
		pow25[i]=(pow25[i-1]*25)%MOD;
		pow26[i]=(pow26[i-1]*26)%MOD;
		inv26[i]=POW(pow26[i],MOD-2);
	}
	fac[0] = inv[0] = 1;
	fup(i, 1, 100000, 1)
		fac[i] = (fac[i - 1] * i) % MOD;
	inv[100000] = POW(fac[100000], MOD - 2);
	fdn(i, 99999, 1, 1)
		inv[i] = (inv[i + 1] * (i+1)) % MOD;
	MEM_1(c);
	int q;
	scanf("%d%s",&q,s);
	int n=strlen(s);
	c[n]=cc;
	upd(n);
	while(q--)
	{
		int o,t;
		scanf("%d",&o);
		if(o==1)
		{
			scanf("%s",s);
			n=strlen(s);
			if(c[n]==-1)
			{
				c[n]=cc;
				upd(n);
			}
		}
		else
		{
			scanf("%d",&t);
			printf("%d\n",v[c[n]][t]);
		}
	}
}