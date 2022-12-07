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
#define INF 1987654321
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
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

Pi p[10000];
map<Pi,int> M;
set<iiii> S;
int main() {
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)scanf("%d%d",&p[i].X,&p[i].Y);
	fup(i,0,n-1,1)
	{
		fup(j,i+1,n-1,1)
		{
			int x=p[j].X-p[i].X,y=p[j].Y-p[i].Y;
			if(x==0)
			{
				S.insert(iiii(0,1,p[j].X,0));
				continue;
			}
			if(y==0)
			{
				S.insert(iiii(1,0,0,p[j].Y));
				continue;
			}
			int g=gcd(x,y);
			x/=g,y/=g;
			if(x<0)x*=-1,y*=-1;
			int a=x*p[i].Y-y*p[i].X,b=x;
			g=gcd(a,b);
			a/=g,b/=g;
			if(a<0)a*=-1,b*=-1;
			S.insert(iiii(x,y,a,b));
		}
	}
	for(auto it=S.begin();it!=S.end();it++)
	{
		int x,y;
		tie(x,y,ignore,ignore)=*it;
		M[mp(x,y)]++;
	}
	ll ans=0;
	int N=S.size();
	for(auto it=M.begin();it!=M.end();it++)
	{
		ll tot=N;
		tot-=it->Y;
		ans+=tot*(it->Y);
	}
	printf("%lld",ans/2);
}