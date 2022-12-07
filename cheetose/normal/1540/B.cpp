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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Vi v[201];
int par[201];
bool chk[201];
int nCr[401][401],inv[401],inv2[401],n;
int LR(int x,int y){
	return 1ll*nCr[x+y-1][x]*inv2[x+y]%MOD;
}
int g(int a,int b){
	MEM_1(par);
	MEM0(chk);
	queue<int> q;
	q.push(a);
	chk[a]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(x==b)continue;
		for(int next:v[x]){
			if(!chk[next]){
				chk[next]=1;
				par[next]=x;
				q.push(next);
			}
		}
	}
	int cnt=0;
	q.push(b);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		cnt++;
		for(int next:v[x]){
			if(!chk[next]){
				chk[next]=1;
				q.push(next);
			}
		}
	}
	int res=1ll*cnt*inv[n]%MOD;
	Vi vv;
	int x=b;
	chk[x]=0;
	x=par[x];
	while(x!=a){
		chk[x]=0;
		vv.pb(x);
		x=par[x];
	}
	chk[x]=0;
	int N=vv.size();
	fup(i,0,N-1,1){
		int cnt=0;
		int z=vv[i];
		q.push(z);
		while(!q.empty()){
			int x=q.front();
			cnt++;
			q.pop();
			for(int next:v[x]){
				if(chk[next]){
					chk[next]=0;
					q.push(next);
				}
			}
		}
		int tmp=1ll*cnt*inv[n]%MOD;
		int sum=0;
		fup(k,0,N-i-1,1){
			sum=(sum+LR(k,i+1))%MOD;
		}
		res=(res+1ll*tmp*sum)%MOD;
	}
	return res;
}
int main(){
	fup(i,0,400,1){
		nCr[i][0]=nCr[i][i]=1;
		fup(j,1,i-1,1){
			nCr[i][j]=(nCr[i-1][j-1]+nCr[i-1][j])%MOD;
		}
	}
	fup(i,1,400,1)inv[i]=POW(i,MOD-2);
	inv2[0]=1;
	fup(i,1,400,1)inv2[i]=(1ll*inv2[i-1]*(MOD+1)/2)%MOD;
	scanf("%d",&n);
	fup(i,1,n-1,1){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	int ans=0;
	fup(i,1,n,1){
		fup(j,i+1,n,1){
			ans=(ans+g(i,j))%MOD;
		}
	}
	printf("%d\n",ans);
}