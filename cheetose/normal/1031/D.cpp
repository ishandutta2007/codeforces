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
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
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
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

char s[2005][2005];
int d[2005][2005];
bool chk[2005][2005];
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	fup(i,0,n-1,1)scanf("%s",s[i]);
	d[0][0]=(s[0][0]!='a');
	fup(i,0,n-1,1)
		fup(j,0,n-1,1)
	{
		if(i==0 && j==0)continue;
		d[i][j]=(s[i][j]!='a')+min(i==0?INF:d[i-1][j],j==0?INF:d[i][j-1]);
	}
	VPi v;
	bool ok=0;
	fdn(t,2*n-1,0,1)
	{
		fup(i,0,t,1)
		{
			int j=t-i;
			if(i>=n || j>=n)continue;
			if(d[i][j]<=k)
			{
				ok=1;
				v.pb(mp(i,j));
			}
		}
		if(ok)
		{
			fup(ii,0,t,1)putchar('a');
			break;
		}
	}
	if(v.empty())
	{
		putchar(s[0][0]);
		v.pb(mp(0,0));
	}
	while(1)
	{
		VPi vv;
		for(Pi p:v)
		{
			int x,y;
			tie(x,y)=p;
			if(x<n-1)// && !chk[x+1][y])
			{
				if(!chk[x+1][y])
				{
					vv.pb(mp(x+1,y));
					chk[x+1][y]=1;
				}
			}
			if(y<n-1)// && !chk[x][y+1]);
			{
				if(!chk[x][y+1])
				{
					vv.pb(mp(x,y+1));
					chk[x][y+1]=1;
				}
			}
		}
		if(vv.empty())return 0;
		sort(ALL(vv),[&](Pi p1,Pi p2){
			return s[p1.X][p1.Y]<s[p2.X][p2.Y];
		});
		putchar(s[vv[0].X][vv[0].Y]);
		v.clear();
		for(int i=0;i<vv.size() && s[vv[i].X][vv[i].Y]==s[vv[0].X][vv[0].Y];i++)v.pb(mp(vv[i].X,vv[i].Y));
	}
}