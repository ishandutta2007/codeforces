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
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

ll fac[1000001];
ll inv[1000001];
int ori[26],cnt[26];
char a[1000002],b[1000002];
inline void mul(ll &x,ll y){x=(x*y)%MOD;}
inline void add(ll &x,ll y){x=(x+y)%MOD;}
int main() {
	fac[0] = inv[0] = 1;
	fup(i, 1, 1000000, 1)
		fac[i] = (fac[i - 1] * i) % MOD;
	inv[1000000] = POW(fac[1000000], MOD - 2);
	fdn(i, 999999, 1, 1)
		inv[i] = (inv[i + 1] * (i+1)) % MOD;
	scanf("%s%s",a,b);
	int n=strlen(a);
	fup(i,0,n-1,1)ori[a[i]-'a']++;
	memcpy(cnt,ori,sizeof(cnt));
	ll ans1=0,ans2=0;
	fup(i,0,n-1,1)
	{
		int c=n-i-1,sum=0;
		ll t=fac[c];
		int o=b[i]-'a';
		fup(j,o,25,1)mul(t,inv[cnt[j]]);
		fup(j,0,o-1,1)
		{
			if(cnt[j]>0)
			{
				sum+=cnt[j];
				mul(t,inv[cnt[j]]);
			}
		}
		mul(t,sum);
		add(ans2,t);
		if(cnt[o]==0)break;
		cnt[o]--;
	}
	memcpy(cnt,ori,sizeof(cnt));
	fup(i,0,n-1,1)
	{
		int c=n-i-1,sum=0;
		ll t=fac[c];
		int o=a[i]-'a';
		fup(j,o,25,1)mul(t,inv[cnt[j]]);
		fup(j,0,o-1,1)
		{
			if(cnt[j]>0)
			{
				sum+=cnt[j];
				mul(t,inv[cnt[j]]);
			}
		}
		mul(t,sum);
		add(ans1,t);
		cnt[o]--;
	}
	printf("%lld",(ans2-ans1-1+MOD)%MOD);
}