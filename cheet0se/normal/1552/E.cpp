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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int a[10001];
Vi v[101];
bool chk[101];
int cc[101];
Pi ans[101];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	fup(i,1,n*k,1){
		scanf("%d",&a[i]);
		v[a[i]].pb(i);
	}
	fup(i,1,n,k-1){
		int l=i,r=min(l+k-2,n);
		VPi vv;
		fup(j,l,r,1){
			for(int ii:v[j])vv.pb(mp(ii,j));
		}
		sort(ALL(vv));
		int now=0;
		int N=vv.size();
		while(1){
			MEM0(cc);
			int w=-1,ne=-1;
			fup(j,now,N-1,1){
				if(chk[vv[j].Y])continue;
				if(cc[vv[j].Y]){
					chk[vv[j].Y]=1;
					w=vv[j].Y;
					ne=j+1;
					ans[vv[j].Y]=mp(cc[vv[j].Y],vv[j].X);
					break;
				}else{
					cc[vv[j].Y]=vv[j].X;
				}
			}
			if(w==-1)break;
			now=ne;
		}
	}
	fup(i,1,n,1)printf("%d %d\n",ans[i].X,ans[i].Y);
}