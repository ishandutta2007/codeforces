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

ll C[303][303];
ll F[303];
map<int,int> M;
int main() {
	F[0]=1;
	fup(i,1,301,1)F[i]=F[i-1]*i%MOD;
	fup(i,0,301,1){
		C[i][0]=C[i][i]=1;
		fup(j,1,i-1,1){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
		}
	}
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1){
		int x;
		scanf("%d",&x);
		for(int j=2;j*j<=x;j++){
			int t=j*j;
			while(x%t==0)x/=t;
		}
		M[x]++;
	}
	Vi vv;
	for(auto P:M)vv.pb(P.Y);
	Vll d(301),nd(301);
	d[0]=1;
	int sum=0;
	for(int x:vv){
		fup(i,0,300,1)nd[i]=0;
		fup(i,0,sum,1){
			fup(j,0,min(i,x),1){
				fup(k,max(0,x-sum-1),x-1,1){
					if(i+k-j<0 || i+k-j>=n)continue;
					ll c=C[i][j]*C[x-1][x-1-k]%MOD;
					if(x-k-j>=0){
						c=c*C[sum+1-i][x-k-j]%MOD;
						nd[i+k-j]=(nd[i+k-j]+c*d[i])%MOD;
					}
				}
			}
		}
		swap(d,nd);
		sum+=x;
	}
	for(int x:vv)d[0]=d[0]*F[x]%MOD;
	printf("%lld\n",d[0]);
}