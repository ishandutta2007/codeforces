#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define eb emplace_back
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

Vi v[1001],rev[1001];
ll a[1001],b[1001],d[1001];
int outd[1001];
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,1,n,1){
		scanf("%lld",a+i);
		v[i].clear();
		rev[i].clear();
		outd[i]=0;
		d[i]=0;
	}
	fup(i,1,m,1){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		rev[y].pb(x);
		outd[x]++;
	}
	fup(i,0,n-1,1){
		bool ok=0;
		fup(j,1,n,1){
			if(a[j])ok=1;
			b[j]=0;
		}
		if(!ok){
			printf("%d\n",i);
			return;
		}
		fup(j,1,n,1){
			if(a[j]){
				b[j]--;
				for(int x:v[j]){
					b[x]++;
				}
			}
		}
		fup(j,1,n,1)a[j]+=b[j];
	}
	int R=-1;
	fup(i,1,n,1)if(!outd[i])R=i;
	queue<int> q;
	q.push(R);
	d[R]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int next:rev[x]){
			d[next]=(d[next]+d[x])%MOD;
			outd[next]--;
			if(!outd[next])q.push(next);
		}
	}
	ll ans=n;
	fup(i,1,n,1)ans=(ans+d[i]*a[i])%MOD;
	printf("%lld\n",ans);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}