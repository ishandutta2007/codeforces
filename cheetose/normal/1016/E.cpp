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
typedef pair<double, double> Pd;
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

ll sy,sa,sb;
db x[200000],y[200000],s[200000];
int main() {
	scanf("%lld%lld%lld",&sy,&sa,&sb);
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)scanf("%lf%lf",x+i,y+i);
	s[0]=y[0]-x[0];
	fup(i,1,n-1,1)s[i]=s[i-1]+y[i]-x[i];
	int q;
	scanf("%d",&q);
	fup(T,1,q,1)
	{
		ll xx,yy;
		scanf("%lld%lld",&xx,&yy);
		db l=-1.0*yy*(xx-sa)/(yy-sy)+xx;
		db r=-1.0*yy*(xx-sb)/(yy-sy)+xx;
		int ll=upper_bound(x,x+n,l)-x-1;
		int rr=upper_bound(x,x+n,r)-x-1;
		if(ll==rr)
		{
			if(ll==-1)printf("%.10f\n",0.0);
			else if(r<=y[rr])printf("%.10f\n",1.0*(sb-sa));
			else
			{
				db tot=y[rr]-l;
				if(tot<0)tot=0;
				printf("%.10f\n",tot*(sb-sa)/(r-l));
			}
			continue;
		}
		db tot=0;
		if(rr>0)tot+=s[rr-1];
		if(ll>=0)tot-=s[ll];
		if(rr!=-1)tot+=(r>y[rr]?y[rr]-x[rr]:r-x[rr]);
		if(ll!=-1)tot+=(y[ll]-l>0?y[ll]-l:0);
		printf("%.10f\n",tot*(sb-sa)/(r-l));
	}
}