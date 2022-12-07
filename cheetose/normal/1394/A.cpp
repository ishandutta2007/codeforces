#include <bits/stdc++.h>
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
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

Vll v1,v2;
ll s[100001];
int main(){
	int n,d;
	ll m;
	scanf("%d%d%lld",&n,&d,&m);
	fup(i,0,n-1,1){
		ll x;
		scanf("%lld",&x);
		if(x<=m)v1.pb(x);
		else v2.pb(x);
	}
	sort(ALL(v1));sort(ALL(v2));
	reverse(ALL(v1));reverse(ALL(v2));
	ll ans=0;
	if(v2.empty()){
		for(ll x:v1)ans+=x;
		return !printf("%lld\n",ans);
	}
	int N=v1.size();
	fup(i,0,N-1,1){
		s[i]=v1[i];
		if(i>0)s[i]+=s[i-1];
	}
	int M=v2.size();
	ll tmp=0;
	fup(i,0,M-1,1){
		ll rem=n-i-1;
		if(rem<1LL*d*i)break;
		tmp+=v2[i];
		ll tt=tmp;
		if(N-d*i+M-i-2>=0)tt+=s[min(N-d*i+M-i-2,N-1)];
		ans=max(ans,tt);
	}
	printf("%lld\n",ans);
}