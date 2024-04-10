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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int a[400002],n;
ll r[20][20],tmp[20][20],d[1<<20],tot[20];
int fir[20],fii[20],cnt[20][400002],tt[20];
ll go(int k)
{
	if(k==(1<<20)-1)return 0;
	ll &ret=d[k];
	if(~ret)return ret;
	ret=INF;
	fup(i,0,19,1)
	{
		if(!(k&(1<<i)))
		{
			if(fir[i]==-1)return ret=go(k|(1<<i));
			ll rcnt=cnt[i][n],rtot=tot[i];
			int c=0;
			fup(j,0,19,1)
			{
				if(k&(1<<j))
				{
					rtot-=r[j][i];
				}
				else if(i!=j)
				{
					c+=cnt[j][fii[i]];
				}
			}
			ret=min(ret,rtot+rcnt*c+go(k|(1<<i)));
		}
	}
	return ret;
}
int main() {
	MEM_1(fir);MEM_1(fii);MEM_1(d);
	scanf("%d",&n);
	fup(i,1,n,1)
	{
		scanf("%d",a+i);
		a[i]--;
	}
	int f=0;
	fup(i,1,n,1)
	{
		cnt[a[i]][i]++;
		fup(j,0,19,1)cnt[j][i]+=cnt[j][i-1];
		tot[a[i]]+=tt[a[i]];
		fup(j,0,19,1)
		{
			if(~fir[j] && a[i]!=j)tt[j]++;
		}
		if(fir[a[i]]==-1)fir[a[i]]=f,fii[a[i]]=i;
		f|=1<<a[i];
		fup(j,0,19,1)
		{
			if(j==a[i])continue;
			r[j][a[i]]+=tmp[j][a[i]];
			if(~fir[j])
			{
				tmp[a[i]][j]++;
			}
		}
	}
	printf("%lld",go(0));
}