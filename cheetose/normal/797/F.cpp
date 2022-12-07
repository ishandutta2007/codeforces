#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321987654321
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
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

ll d[5005][5005];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	Vi x(n);
	VPi y(m);
	fup(i,0,n-1,1)scanf("%d",&x[i]);
	fup(i,0,m-1,1)scanf("%d%d",&y[i].X,&y[i].Y);
	sort(ALL(x));sort(ALL(y));
	fup(i,0,n,1)fup(j,0,m,1)d[i][j]=INF;
	d[0][0]=0;
	fup(i,1,m,1){
		ll now=0;
		int cnt=y[i-1].Y,f=-1;
		d[i][0]=0;
		fup(j,1,n,1){
			int cost=abs(y[i-1].X-x[j-1]);
			if(f==-1){
				if(d[i-1][j-1]+cost<d[i-1][j]){
					d[i][j]=d[i-1][j-1]+cost;
					f=j-1;
					cnt--;
					now+=cost;
				}else{
					d[i][j]=d[i-1][j];
				}
			}else{
				if(cnt>0){
					now+=cost;
					d[i][j]=d[i-1][f]+now;
					cnt--;
				}else{
					now+=cost;
					now-=abs(y[i-1].X-x[f++]);
					d[i][j]=d[i-1][f]+now;
				}
			}
		}
	}
	if(d[m][n]>=INF)d[m][n]=-1;
	printf("%lld",d[m][n]);
}