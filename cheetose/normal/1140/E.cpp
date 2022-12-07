#include <bits/stdc++.h>
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
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define COMPRESS(a) sort(ALL(a));a.resize(unique(ALL(a))-a.begin())
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
typedef vector<ld> Vd;
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
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int a[200006];
int n,k;
ll cnt(int N,int t){
	if(N==0)return 1;
	if(t==0){
		ll ans=k;
		fup(i,1,N-1,1)ans=ans*(k-1)%MOD;
		return ans;
	}else if(t==1){
		ll ans=1;
		fup(i,1,N,1)ans=ans*(k-1)%MOD;
		return ans;
	}
	ll same=1,dif=0;
	fup(i,1,N,1){
		ll ns=dif*(k-1)%MOD;
		ll nd=(same+dif*(k-2))%MOD;
		same=ns,dif=nd;
	}
	if(t==2)return dif*(k-1)%MOD;
	return (same+dif*(k-2))%MOD;
}
int main(){
	scanf("%d%d",&n,&k);
	fup(i,0,n-1,1)scanf("%d",a+i);
	fup(i,0,n-3,1){
		if(a[i]!=-1 && a[i]==a[i+2])return !printf("0\n");
	}
	ll ans=1;
	int pr=-2;
	fup(i,0,n-1,2){
		if(a[i]!=-1){
			if(pr==-2){
				ans=ans*cnt(i/2,1)%MOD;
			}else{
				int t=2;
				if(a[i]!=a[pr])t=3;
				ans=ans*cnt((i-pr)/2-1,t)%MOD;
			}
			pr=i;
		}
	}
	if(pr==-2){
		ans=cnt((n+1)/2,0);
	}else{
		ans=ans*cnt((n-pr-1)/2,1)%MOD;
	}

	pr=-2;
	fup(i,1,n-1,2){
		if(a[i]!=-1){
			if(pr==-2){
				ans=ans*cnt(i/2,1)%MOD;
			}else{
				int t=2;
				if(a[i]!=a[pr])t=3;
				ans=ans*cnt((i-pr)/2-1,t)%MOD;
			}
			pr=i;
		}
	}
	if(pr==-2){
		ans=ans*cnt(n/2,0)%MOD;
	}else{
		ans=ans*cnt((n-pr-1)/2,1)%MOD;
	}
	printf("%lld\n",ans);
}