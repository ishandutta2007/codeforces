#include <bits/stdc++.h>
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
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 993244853;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

ll c[28];
int main() {
	c[1]=4;
	ll now=4;
	fup(i,2,27,1)
	{
		now*=4;
		c[i]=c[i-1]+now;
	}
	/*int t=1;
	fup(i,1,5,1)
	{
		while(in(t))t++;
		for(int j=t+1;;j++)
		{
			if(!in(j) && !in(t^j))
			{
				S.insert(t);
				S.insert(j);
				S.insert(t^j);
				//printf("%d %d %d ",t,j,t^j);
				break;
			}
		}
	}
	puts("");
	fup(i,6,21,1)
	{
		while(in(t))t++;
		for(int j=t+1;;j++)
		{
			if(!in(j) && !in(t^j))
			{
				S.insert(t);
				S.insert(j);
				S.insert(t^j);
				//printf("%d %d %d ",t,j,t^j);
				break;
			}
		}
	}
	fup(i,22,25)*/
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		ll n;
		scanf("%lld",&n);
		n--;
		ll x=n/3,y=n%3;
		if(x==0)
		{
			printf("%lld\n",n+1);
			continue;
		}
		int i;
		for(i=27;i>=1;i--)
		{
			if(x>c[i-1])break;
		}
		x-=c[i-1];
		ll L=(1LL<<(2*i)),R=(4LL<<(2*i))-1;
		ll w=(R-L+1)/3;
		if(y==0)
		{
			ll l=L,r=L+w-1;
			while(l<r)
			{
				ll ww=(r-l+1)/4;
				ll l1=1,r1=ww;
				ll l2=r1+1,r2=r1+ww;
				ll l3=r2+1,r3=r2+ww;
				ll l4=r3+1,r4=r3+ww;
				if(l1<=x && x<=r1)
				{
					r=l+ww-1;
				}
				else if(l2<=x && x<=r2)
				{
					l=l+ww,r=l+ww-1;
					x-=r1;
				}
				else if(l3<=x && x<=r3)
				{
					l=l+2*ww,r=l+ww-1;
					x-=r2;
				}
				else
				{
					l=l+3*ww,r=l+ww-1;
					x-=r3;
				}
			}
			printf("%lld\n",l);
		}
		else if(y==1)
		{
			ll l=L+w,r=L+w+w-1;
			while(l<r)
			{
				ll ww=(r-l+1)/4;
				ll l1=1,r1=ww;
				ll l2=r1+1,r2=r1+ww;
				ll l3=r2+1,r3=r2+ww;
				ll l4=r3+1,r4=r3+ww;
				if(l1<=x && x<=r1)
				{
					r=l+ww-1;
				}
				else if(l2<=x && x<=r2)
				{
					l=l+2*ww,r=l+ww-1;
					x-=r1;
				}
				else if(l3<=x && x<=r3)
				{
					l=l+3*ww,r=l+ww-1;
					x-=r2;
				}
				else
				{
					l=l+ww,r=l+ww-1;
					x-=r3;
				}
			}
			printf("%lld\n",l);
		}
		else
		{
			ll l=L+w+w,r=R;
			while(l<r)
			{
				ll ww=(r-l+1)/4;
				ll l1=1,r1=ww;
				ll l2=r1+1,r2=r1+ww;
				ll l3=r2+1,r3=r2+ww;
				ll l4=r3+1,r4=r3+ww;
				if(l1<=x && x<=r1)
				{
					r=l+ww-1;
				}
				else if(l2<=x && x<=r2)
				{
					l=l+3*ww,r=l+ww-1;
					x-=r1;
				}
				else if(l3<=x && x<=r3)
				{
					l=l+ww,r=l+ww-1;
					x-=r2;
				}
				else
				{
					l=l+2*ww,r=l+ww-1;
					x-=r3;
				}
			}
			printf("%lld\n",l);
		}
	}
}