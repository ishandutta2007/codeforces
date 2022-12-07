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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

const int N=1<<9;
int t[N],cnt[N];
Pll p[N][2];
void upd(Pll &a,Pll &b,Pll c)
{
	if(c<a)
	{
		b=a;
		a=c;
	}
	else if(c<b)
	{
		b=c;
	}
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	fill(&p[0][0],&p[N-1][2],mp(INF,INF));
	fup(i,0,n-1,1)
	{
		int c=0,x;
		int r;
		scanf("%d",&r);
		while(r--)
		{
			scanf("%d",&x);
			c|=1<<(x-1);
		}
		t[c]++;
	}
	fup(i,1,N-1,1)
	{
		fup(j,1,N-1,1)if((i&j)==j)cnt[i]+=t[j];
	}
	fup(i,0,m-1,1)
	{
		ll c;
		int r,x;
		scanf("%lld%d",&c,&r);
		int cc=0;
		while(r--)
		{
			scanf("%d",&x);
			cc|=1<<(x-1);
		}
		upd(p[cc][0],p[cc][1],mp(c,i+1));
	}
	Pi ans;
	int c=0;
	ll pri=INF;
	fup(i,1,N-1,1)
		fup(j,i,N-1,1)
	{
		if(i==j)
		{
			if(p[i][1].X==INF)continue;
			if(cnt[i]>c || (cnt[i]==c && pri>p[i][0].X+p[i][1].X))
			{
				c=cnt[i];
				pri=p[i][0].X+p[i][1].X;
				ans=mp(p[i][0].Y,p[i][1].Y);
			}
		}
		else
		{
			if(p[i][0].X==INF || p[j][0].X==INF)continue;
			int k=i|j;
			if(cnt[k]>c || (cnt[k]==c && pri>p[i][0].X+p[j][0].X))
			{
				c=cnt[k];
				pri=p[i][0].X+p[j][0].X;
				ans=mp(p[i][0].Y,p[j][0].Y);
			}
		}
	}
	printf("%d %d",ans.X,ans.Y);
}