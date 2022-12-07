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
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int R,G,B;
int d[201][201][201];
int r[201],g[201],b[201];
int go(int rr,int gg,int bb){
	int &ret=d[rr][gg][bb];
	if(~ret)return ret;
	ret=0;
	if(rr<R && gg<G)ret=max(ret,r[rr]*g[gg]+go(rr+1,gg+1,bb));
	if(rr<R && bb<B)ret=max(ret,r[rr]*b[bb]+go(rr+1,gg,bb+1));
	if(gg<G && bb<B)ret=max(ret,g[gg]*b[bb]+go(rr,gg+1,bb+1));
	return ret;
}
int main(){
	MEM_1(d);
	scanf("%d%d%d",&R,&G,&B);
	fup(i,0,R-1,1)scanf("%d",r+i);
	fup(i,0,G-1,1)scanf("%d",g+i);
	fup(i,0,B-1,1)scanf("%d",b+i);
	sort(r,r+R);reverse(r,r+R);
	sort(g,g+G);reverse(g,g+G);
	sort(b,b+B);reverse(b,b+B);
	printf("%d\n",go(0,0,0));
}