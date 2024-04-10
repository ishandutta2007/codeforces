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

ll p2[300001],p3[300001];
ll div9=POW(9,MOD-2);
int main(){
	p2[0]=p3[0]=1;
	fup(i,1,300000,1){
		p2[i]=p2[i-1]*2%MOD;
		p3[i]=(p2[i]*(3*i+1)+((i&1)?1:-1))%MOD;
		p3[i]=(p3[i]*div9)%MOD;
	}
	int n,m;
	SYNC;
	cin>>n>>m;
	vector<string> s(n);
	fup(i,0,n-1,1)cin>>s[i];
	int tot=0;
	fup(i,0,n-1,1)fup(j,0,m-1,1)if(s[i][j]=='o')tot++;
	ll ans=0;
	fup(i,0,n-1,1){
		int tmp=0;
		fup(j,0,m-1,1){
			if(s[i][j]=='o')tmp++;
			else{
				if(tmp>1){
					ans=(ans+p3[tmp-1]*p2[tot-tmp])%MOD;
				}
				tmp=0;
			}
		}
		if(tmp>1)ans=(ans+p3[tmp-1]*p2[tot-tmp])%MOD;
	}
	fup(j,0,m-1,1){
		int tmp=0;
		fup(i,0,n-1,1){
			if(s[i][j]=='o')tmp++;
			else{
				if(tmp>1){
					ans=(ans+p3[tmp-1]*p2[tot-tmp])%MOD;
				}
				tmp=0;
			}
		}
		if(tmp>1)ans=(ans+p3[tmp-1]*p2[tot-tmp])%MOD;
	}
	cout<<ans<<'\n';
}