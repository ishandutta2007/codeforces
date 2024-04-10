#include <bits/stdc++.h>
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
typedef vector<db> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

ll fac[300001],inv[300001];
ll nCr(int n, int r)
{
	if(r>n)return 0;
	ll c = fac[n];
	c = (c*inv[r]) % MOD;
	c = (c*inv[n - r]) % MOD;
	return c;
}
int main() {
	fac[0] = inv[0] = 1;
	fup(i, 1, 300000, 1)
		fac[i] = (fac[i - 1] * i) % MOD;
	inv[300000] = POW(fac[300000], MOD - 2);
	fdn(i, 299999, 1, 1)
		inv[i] = (inv[i + 1] * (i+1)) % MOD;
	int n,k;
	scanf("%d%d",&n,&k);
	VPi vv;
	fup(i,1,n,1){
		int l,r;
		scanf("%d%d",&l,&r);
		vv.pb(mp(l,i));
		vv.pb(mp(r+1,-i));
	}
	sort(ALL(vv));
	ll ans=0;
	int cnt=0;
	fup(i,0,2*n-1,1){
		if(vv[i].Y>0){
			cnt++;
			if(cnt==k)ans+=nCr(cnt,k);
			else if(cnt>k)ans+=nCr(cnt-1,k-1);
			if(ans>=MOD)ans-=MOD;
		}else{
			cnt--;
		}
	}
	printf("%lld\n",ans);
}