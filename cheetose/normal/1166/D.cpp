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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

void solve()
{
	ll a,b,m;
	scanf("%lld%lld%lld",&a,&b,&m);
	if(a==b)
	{
		printf("1 %lld\n",a);
		return;
	}
	if(b-a<=m)
	{
		printf("2 %lld %lld\n",a,b);
		return;
	}
	fup(i,0,50,1)
	{
		if((1LL<<i)*(a+1) > b)
		{
			puts("-1");
			return;
		}
		if((1LL<<i)*(a+1)<=b && b<=(1LL<<i)*(a+m))
		{
			printf("%d %lld ",i+2,a);
			ll r[51]={0};
			ll rem=b-(1LL<<i)*a;
			fup(j,0,i-1,1)
			{
				ll k=1LL<<(i-j-1);
				ll L=1,R=m;
				while(L<=R)
				{
					ll M=(L+R)>>1;
					if(rem-M*k>=k)L=M+1;
					else R=M-1;
				}
				r[j]=R;
				rem-=R*k;
			}
			r[i]=rem;
			ll sum=a;
			fup(j,0,i,1)
			{
				printf("%lld ",sum+r[j]);
				sum+=sum+r[j];
			}
			puts("");
			return;
		}
	}
}
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}