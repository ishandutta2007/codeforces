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
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Vll basis;
VPll v[100001];
bool chk[100001],fin[100001];
ll Xor[100001];
int zero[60],one[60];
void dfs(int N,ll cur,int p=-1){
	chk[N]=1;
	Xor[N]=cur;
	fup(i,0,59,1){
		if(cur&(1LL<<i))one[i]++;
		else zero[i]++;
	}
	for(auto P:v[N]){
		if(P.X==p)continue;
		if(!chk[P.X])dfs(P.X,cur^P.Y,N);
		else if(!fin[P.X] && Xor[P.X]^cur^P.Y>0){
			basis.pb(Xor[P.X]^cur^P.Y);
		}
	}
	fin[N]=1;
}
int Rank(){
	int N=basis.size();
	int res=0,tt=0;
	fdn(k,59,0,1){
		if(tt>=N)break;
		int tmp=-1;
		fup(i,tt,N-1,1){
			if(basis[i]&(1LL<<k)){
				tmp=i;
				break;
			}
		}
		if(tmp==-1)continue;
		swap(basis[tmp],basis[tt]);
		fup(i,tt+1,N-1,1){
			if(basis[i]&(1LL<<k))basis[i]^=basis[tt];
		}
		res++,tt++;
	}
	return res;
}
ll nC2(int x){
	return (1LL*x*(x-1)/2)%MOD;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,1,m,1){
		int x,y;
		ll z;
		scanf("%d%d%lld",&x,&y,&z);
		v[x].pb(mp(y,z));
		v[y].pb(mp(x,z));
	}
	ll ans=0;
	fup(i,1,n,1){
		if(!chk[i]){
			basis.clear();
			MEM0(zero);MEM0(one);
			dfs(i,0);
			int R=Rank();
			if(R==0){
				fup(k,0,59,1){
					ll c=(1LL<<k)%MOD;
					c=c*zero[k]%MOD*one[k]%MOD;
					ans=(ans+c)%MOD;
				}
				continue;
			}
			int N=basis.size();
			ll sum=0;
			fup(j,0,N-1,1){
				sum|=basis[j];
			}
			fup(k,0,59,1){
				if(sum&(1LL<<k)){
					ll c=(1LL<<k)%MOD;
					c=(1LL<<(R-1))%MOD*c%MOD;
					c=c*nC2(zero[k]+one[k])%MOD;
					ans=(ans+c)%MOD;
				}else{
					ll c=(1LL<<k)%MOD;
					c=(1LL<<R)%MOD*c%MOD;
					c=c*zero[k]%MOD*one[k]%MOD;
					ans=(ans+c)%MOD;
				}
			}
		}
	}
	printf("%lld\n",ans);
}