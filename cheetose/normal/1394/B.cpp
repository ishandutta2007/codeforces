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

int n,m,k;
int out[200005];
int t[10];
VPi v[200002];
Pll vv[10][10];
const ll MOD1=1000000021,MOD2=993244853;
ll fac1[200002],fac2[200002];
map<Pll,int> M1,M2;
void dfs1(int N,Pll c){
	if(N==0){
		M1[c]++;
		return;
	}
	fup(i,1,N,1){
		Pll cc=c;
		cc.X=(cc.X+vv[N][i].X)%MOD1;
		cc.Y=(cc.Y+vv[N][i].Y)%MOD2;
		dfs1(N-1,cc);
	}
}
void dfs2(int N,Pll c){
	if(N>k){
		M2[c]++;
		return;
	}
	fup(i,1,N,1){
		Pll cc=c;
		cc.X=(cc.X+vv[N][i].X)%MOD1;
		cc.Y=(cc.Y+vv[N][i].Y)%MOD2;
		dfs2(N+1,cc);
	}
}
int main(){
	fac1[0]=fac2[0]=1;
	fup(i,1,200000,1){
		fac1[i]=(fac1[i-1]*i)%MOD1;
		fac2[i]=(fac2[i-1]*i)%MOD2;
	}
	Pll res;
	scanf("%d%d%d",&n,&m,&k);
	fup(i,1,n,1){
		res.X=(res.X+fac1[i])%MOD1;
		res.Y=(res.Y+fac2[i])%MOD2;
	}
	fup(i,1,m,1){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		v[x].pb(mp(y,z));
	}
	fup(i,1,n,1){
		out[i]=v[i].size();
		sort(ALL(v[i]),[&](Pi p1,Pi p2){
			return p1.Y<p2.Y;
		});	
		fup(j,0,out[i]-1,1){
			vv[out[i]][j+1].X=(vv[out[i]][j+1].X+fac1[v[i][j].X])%MOD1;
			vv[out[i]][j+1].Y=(vv[out[i]][j+1].Y+fac2[v[i][j].X])%MOD2;
		}
	}
	dfs1(min(6,k),mp(0,0));
	dfs2(7,mp(0,0));
	int ans=0;
	for(auto it=M1.begin();it!=M1.end();it++){
		Pll p1=it->X;
		int c=it->Y;
		Pll p=res;
		p.X=(p.X-p1.X+MOD1)%MOD1;
		p.Y=(p.Y-p1.Y+MOD2)%MOD2;
		if(M2.find(p)!=M2.end())ans+=M2[p]*c;
	}
	printf("%d\n",ans);
}