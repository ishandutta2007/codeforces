#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 2000000002
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
const int MOD = 1000000000;
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int n,m;
int a[500001],x[500001],y[500001];
Vi v[500001],vv[500001];
int main(){
	scanf("%d%d",&n,&m);
	fup(i,0,m-1,1){
		scanf("%d%d",x+i,y+i);
		v[x[i]].pb(y[i]);
		v[y[i]].pb(x[i]);
	}
	fup(i,1,n,1){
		scanf("%d",a+i);
		vv[a[i]].pb(i);
	}
	fup(i,0,m-1,1){
		if(a[x[i]]==a[y[i]])return !printf("-1\n");
	}
	Vi ans;
	fup(i,1,n,1){
		while(!vv[i].empty()){
			int x=vv[i].back();
			Vi tmp;
			for(int y:v[x]){
				if(a[y]>=i)continue;
				tmp.pb(a[y]);
			}
			sort(ALL(tmp));tmp.resize(unique(ALL(tmp))-tmp.begin());
			if(tmp.size()!=i-1)return !printf("-1\n");
			ans.pb(x);
			vv[i].pop_back();
		}
	}
	for(int x:ans)printf("%d ",x);
}