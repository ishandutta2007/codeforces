#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#include<cassert>
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
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

struct edge{
	int x,y,z;
	bool operator <(const edge &O)const{return z<O.z;}
}e[200000];
Vi vv;
ll dist[800][800];
int main() {
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	fup(i,0,m-1,1)
	{
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
		e[i].x--,e[i].y--;
	}
	sort(e,e+m);
	fup(i,0,min(m,k)-1,1)
	{
		vv.pb(e[i].x);
		vv.pb(e[i].y);
	}
	sort(ALL(vv));
	vv.resize(unique(ALL(vv))-vv.begin());
	int N=vv.size();
	fup(i,0,N-1,1)fup(j,0,N-1,1)if(i!=j)dist[i][j]=INF;
	fup(i,0,min(m,k)-1,1)
	{
		int x=lower_bound(ALL(vv),e[i].x)-vv.begin();
		int y=lower_bound(ALL(vv),e[i].y)-vv.begin();
		dist[x][y]=min(dist[x][y],(ll)e[i].z);
		dist[y][x]=dist[x][y];
	}
	fup(k,0,N-1,1)
		fup(i,0,N-1,1)
		fup(j,0,N-1,1)
		dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	Vll v;
	fup(i,0,N-1,1)fup(j,i+1,N-1,1)v.pb(dist[i][j]);
	sort(ALL(v));
	printf("%lld",v[k-1]);
}