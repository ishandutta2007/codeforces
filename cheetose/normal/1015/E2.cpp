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

char s[1000][1001];
int xx[1000][1001],yy[1000][1001];
int L[1000][1000],R[1000][1000],D[1000][1000],U[1000][1000],d[1000][1000];
void upd(int *a,int i, int k,int n)
{
	while (i <= n)
	{
		a[i] += k;
		i += (i&-i);
	}
}
int sum(int *a,int i)
{
	int c = 0;
	while (i > 0)
	{
		c += a[i];
		i -= (i&-i);
	}
	return c;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,0,n-1,1)scanf("%s",s[i]);
	fup(i,0,n-1,1)
	{
		int now=0;
		fup(j,0,m-1,1)
		{
			if(s[i][j]=='.')
			{
				now=0;
				continue;
			}
			L[i][j]=now++;
		}
		now=0;
		fdn(j,m-1,0,1)
		{
			if(s[i][j]=='.')
			{
				now=0;
				continue;
			}
			R[i][j]=now++;
		}
	}
	fup(j,0,m-1,1)
	{
		int now=0;
		fup(i,0,n-1,1)
		{
			if(s[i][j]=='.')
			{
				now=0;
				continue;
			}
			U[i][j]=now++;
		}
		now=0;
		fdn(i,n-1,0,1)
		{
			if(s[i][j]=='.')
			{
				now=0;
				continue;
			}
			D[i][j]=now++;
		}
	}
	fup(i,0,n-1,1)
		fup(j,0,m-1,1)
	{
		d[i][j]=min({L[i][j],R[i][j],D[i][j],U[i][j]});
		if(d[i][j]>0)
		{
			int t=d[i][j];
			int l=i-t+1,r=i+t+1;
			upd(yy[j],l,1,n);
			upd(yy[j],r+1,-1,n);
			l=j-t+1,r=j+t+1;
			upd(xx[i],l,1,m);
			upd(xx[i],r+1,-1,m);
		}
	}
	Viii ans;
	fup(i,0,n-1,1)
		fup(j,0,m-1,1)
	{
		if(d[i][j]>0)ans.pb(iii(i+1,j+1,d[i][j]));
		if(s[i][j]=='*')
		{
			if(sum(xx[i],j+1)+sum(yy[j],i+1)==0)return !printf("-1");
		}
	}
	printf("%d\n",ans.size());
	for(iii a:ans)
	{
		printf("%d %d %d\n",get<0>(a),get<1>(a),get<2>(a));
	}
}