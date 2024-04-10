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
#define INF 987654321
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
typedef vector<ld> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000009;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={-1,-2,1,-2,2,-1,2,1},ddy[]={-2,-1,-2,1,-1,2,1,2};

ll a[100001];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,1,m,1)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[x]+=z,a[y]-=z;
	}
	VPll pp,mm;
	fup(i,1,n,1)
	{
		if(a[i]>0)pp.pb(mp(a[i],i));
		if(a[i]<0)mm.pb(mp(-a[i],i));
	}
	int N=pp.size(),M=mm.size();
	int i=0,j=0;
	VLLL ans;
	while(i<N && j<M)
	{
		ll t=min(pp[i].X,mm[j].X);
		ans.pb(LLL(pp[i].Y,mm[j].Y,t));
		pp[i].X-=t,mm[j].X-=t;
		if(pp[i].X==0)i++;
		if(mm[j].X==0)j++;
	}
	printf("%d\n",ans.size());
	for(auto &L:ans)
	{
		ll x,y,z;
		tie(x,y,z)=L;
		printf("%lld %lld %lld\n",x,y,z);
	}
}