#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 1987654321987654321
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

ll p[1000005];
ll ans[300005];
int xx[300000],yy[300000],zz[300000];
int tmp[1000000][2];
int tt[2];
int main(){
	p[0]=1;
	fup(i,1,1000000,1)p[i]=p[i-1]*2%MOD;
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	fup(i,0,q-1,1){
		scanf("%d%d%d",xx+i,yy+i,zz+i);
		--xx[i],--yy[i];
	}
	//Case1 : row 010101
	MEM0(tmp);
	int cnt=m;
	int ok=0;
	map<Pi,int> M;
	fup(i,0,q-1,1){
		int x=xx[i],y=yy[i],z=zz[i];
		if(M.find(mp(x,y))!=M.end()){
			int t=M[mp(x,y)];
			tmp[y][t]--;
			if(tmp[y][t]==0 && tmp[y][t^1]>0)ok--;
			if(tmp[y][t]+tmp[y][t^1]==0)cnt++;
			M.erase(mp(x,y));
		}
		if(z!=-1){
			if(x&1)z^=1;
			tmp[y][z]++;
			if(tmp[y][z]+tmp[y][z^1]==1)cnt--;
			if(tmp[y][z]==1 && tmp[y][z^1]>0)ok++;
			M[mp(x,y)]=z;
		}
		if(!ok)ans[i]+=p[cnt];
	}

	//Case2 : row 101010

	MEM0(tmp);
	cnt=m;
	ok=0;
	M.clear();
	fup(i,0,q-1,1){
		int x=xx[i],y=yy[i],z=zz[i];
		if(M.find(mp(x,y))!=M.end()){
			int t=M[mp(x,y)];
			tmp[y][t]--;
			if(tmp[y][t]==0 && tmp[y][t^1]>0)ok--;
			if(tmp[y][t]+tmp[y][t^1]==0)cnt++;
			M.erase(mp(x,y));
		}
		if(z!=-1){
			if(x%2==0)z^=1;
			tmp[y][z]++;
			if(tmp[y][z]+tmp[y][z^1]==1)cnt--;
			if(tmp[y][z]==1 && tmp[y][z^1]>0)ok++;
			M[mp(x,y)]=z;
		}
		if(!ok)ans[i]+=p[cnt];
	}

	//Case3 : col 010101

	MEM0(tmp);
	cnt=n;
	ok=0;
	M.clear();
	fup(i,0,q-1,1){
		int x=xx[i],y=yy[i],z=zz[i];
		if(M.find(mp(x,y))!=M.end()){
			int t=M[mp(x,y)];
			tmp[x][t]--;
			if(tmp[x][t]==0 && tmp[x][t^1]>0)ok--;
			if(tmp[x][t]+tmp[x][t^1]==0)cnt++;
			M.erase(mp(x,y));
		}
		if(z!=-1){
			if(y&1)z^=1;
			tmp[x][z]++;
			if(tmp[x][z]+tmp[x][z^1]==1)cnt--;
			if(tmp[x][z]==1 && tmp[x][z^1]>0)ok++;
			M[mp(x,y)]=z;
		}
		if(!ok)ans[i]+=p[cnt];
	}

	//Case4 : col 101010

	MEM0(tmp);
	cnt=n;
	ok=0;
	M.clear();
	fup(i,0,q-1,1){
		int x=xx[i],y=yy[i],z=zz[i];
		if(M.find(mp(x,y))!=M.end()){
			int t=M[mp(x,y)];
			tmp[x][t]--;
			if(tmp[x][t]==0 && tmp[x][t^1]>0)ok--;
			if(tmp[x][t]+tmp[x][t^1]==0)cnt++;
			M.erase(mp(x,y));
		}
		if(z!=-1){
			if(y%2==0)z^=1;
			tmp[x][z]++;
			if(tmp[x][z]+tmp[x][z^1]==1)cnt--;
			if(tmp[x][z]==1 && tmp[x][z^1]>0)ok++;
			M[mp(x,y)]=z;
		}
		if(!ok)ans[i]+=p[cnt];
	}

	//Case5 : row 0101 col 0101

	MEM0(tt);
	ok=0;
	M.clear();
	fup(i,0,q-1,1){
		int x=xx[i],y=yy[i],z=zz[i];
		if(M.find(mp(x,y))!=M.end()){
			int t=M[mp(x,y)];
			tt[t]--;
			if(t==1 && tt[t]==0)ok--;
			M.erase(mp(x,y));
		}
		if(z!=-1){
			if(x%2==1)z^=1;
			if(y%2==1)z^=1;
			tt[z]++;
			if(z==1 && tt[z]==1)ok++;
			M[mp(x,y)]=z;
		}
		if(!ok)ans[i]--;
	}

	//Case6 : row 0101 col 1010

	MEM0(tt);
	ok=0;
	M.clear();
	fup(i,0,q-1,1){
		int x=xx[i],y=yy[i],z=zz[i];
		if(M.find(mp(x,y))!=M.end()){
			int t=M[mp(x,y)];
			tt[t]--;
			if(t==1 && tt[t]==0)ok--;
			M.erase(mp(x,y));
		}
		if(z!=-1){
			if(x%2==1)z^=1;
			if(y%2==0)z^=1;
			tt[z]++;
			if(z==1 && tt[z]==1)ok++;
			M[mp(x,y)]=z;
		}
		if(!ok)ans[i]--;
	}

	//Case7 : row 1010 col 0101

	MEM0(tt);
	ok=0;
	M.clear();
	fup(i,0,q-1,1){
		int x=xx[i],y=yy[i],z=zz[i];
		if(M.find(mp(x,y))!=M.end()){
			int t=M[mp(x,y)];
			tt[t]--;
			if(t==1 && tt[t]==0)ok--;
			M.erase(mp(x,y));
		}
		if(z!=-1){
			if(x%2==0)z^=1;
			if(y%2==1)z^=1;
			tt[z]++;
			if(z==1 && tt[z]==1)ok++;
			M[mp(x,y)]=z;
		}
		if(!ok)ans[i]--;
	}
	//Case8 : row 1010 col 1010
	MEM0(tt);
	ok=0;
	M.clear();
	fup(i,0,q-1,1){
		int x=xx[i],y=yy[i],z=zz[i];
		if(M.find(mp(x,y))!=M.end()){
			int t=M[mp(x,y)];
			tt[t]--;
			if(t==1 && tt[t]==0)ok--;
			M.erase(mp(x,y));
		}
		if(z!=-1){
			if(x%2==0)z^=1;
			if(y%2==0)z^=1;
			tt[z]++;
			if(z==1 && tt[z]==1)ok++;
			M[mp(x,y)]=z;
		}
		if(!ok)ans[i]--;
	}
	ll t=(MOD+1)/2;
	fup(i,0,q-1,1){
		ans[i]%=MOD;
		if(ans[i]<0)ans[i]+=MOD;
		printf("%lld\n",ans[i]*t%MOD);
	}
}