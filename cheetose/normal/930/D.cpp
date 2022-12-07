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

Vi v[400001];
int Lmn[400001],Lmx[400001],Rmn[400001],Rmx[400001];
int main(){
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x+y+200000].pb(x-y+200000);
	}
	ll ans=0;
	fup(i,0,400000,1){
		if(i-2>=0){
			Lmn[i]=Lmn[i-2],Lmx[i]=Lmx[i-2];
		}else{
			Lmn[i]=INF,Lmx[i]=-INF;
		}
		for(int x:v[i]){
			Lmn[i]=min(Lmn[i],x);
			Lmx[i]=max(Lmx[i],x);
		}
	}
	fdn(i,400000,0,1){
		if(i+2<=400000){
			Rmn[i]=Rmn[i+2],Rmx[i]=Rmx[i+2];
		}else{
			Rmn[i]=INF,Rmx[i]=-INF;
		}
		for(int x:v[i]){
			Rmn[i]=min(Rmn[i],x);
			Rmx[i]=max(Rmx[i],x);
		}
	}
	fup(i,1,399999,1){
		int L=max(Lmn[i-1],Rmn[i+1]),R=min(Lmx[i-1],Rmx[i+1]);
		if(L>R)continue;
		ans+=(R-L)/2;
	}
	printf("%lld\n",ans);
}