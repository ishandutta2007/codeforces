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

int b[101],sb[101],c[101];
int d[101][10001];
int r[111];
int n;
int go(int x){
	MEM0(d);
	d[0][0]=1;
	fup(i,1,n,1){
		int ss=0;
		fup(j,0,10000,1){
			ss=(ss+d[i-1][j]);
			if(ss>=MOD)ss-=MOD;
			if(j-c[i]>0)ss=ss+MOD-d[i-1][j-c[i]-1];
			if(ss>=MOD)ss-=MOD;
			if(j>=i*x+sb[i])d[i][j]=(d[i][j]+ss)%MOD;
		}
	}
	int ans=0;
	fup(i,0,10000,1){
		ans=(ans+d[n][i])%MOD;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	fup(i,1,n,1)scanf("%d",c+i);
	int s=0;
	int mn=INF;
	fup(i,1,n,1){
		sb[i]=sb[i-1]+s;
		if(i!=n)scanf("%d",b+i);
		s+=b[i];
		mn=min(mn,-sb[i]/i-1);
	}
	mn-=3;
	fup(i,0,110,1)r[i]=go(mn+i);
	int q;
	scanf("%d",&q);
	while(q--){
		int x;
		scanf("%d",&x);
		if(x<mn)printf("%d\n",r[0]);
		else if(x>mn+105)printf("0\n");
		else printf("%d\n",r[x-mn]);
	}
}