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

int d[4000005];
int p[4000005];
int n,m;
VPi v;
int go(int N,int k,int x){
	if(N==v.size()){
		if(k==1)return 0;
		int c=x/k;
		return (d[c]-d[c-1]+m)%m;
	}
	int ret=0,kk=1;
	fup(i,0,v[N].Y,1){
		ret=(ret+go(N+1,k*kk,x))%m;
		kk*=v[N].X;
	}
	return ret;
}
int main() {
	scanf("%d%d",&n,&m);
	fup(i,2,4000000,1){
		if(p[i])continue;
		fup(j,i,4000000,i){
			if(!p[j])p[j]=i;
		}
	}
	int dd=1,s=0;
	d[1]=1;
	fup(i,2,n,1){
		v.clear();
		d[i]=dd;
		int now=i;
		while(now>1){
			int t=p[now],c=0;
			while(now%t==0){
				c++;
				now/=t;
			}
			v.pb(mp(t,c));
		}
		s=(s+go(0,1,i))%m;
		d[i]=(d[i]+s)%m;
		dd=(dd+d[i])%m;
	}
	printf("%d\n",d[n]);
}