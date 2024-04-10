#include <bits/stdc++.h>
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

ll a[2222222];
int rem[2222222];
int n,m;
void init(int N)
{
	if(N>m)rem[N]=1;
	else rem[N]=0;
	int L=N<<1,R=L+1;
	if(L>n)return;
	init(L);init(R);
	rem[N]+=rem[L]+rem[R];
}
bool G(int N)
{
	if(N>m)return 1;
	if(rem[N]==0)return 0;
	int L=N<<1,R=L+1;
	if(a[L]>a[R])return G(L);
	return G(R);
}
int go(int N)
{
	if(G(N))
	{
		int now=N/2;
		while(now)
		{
			rem[now]--;
			now>>=1;
		}
		now=N;
		while(1)
		{
			rem[now]--;
			int L=now<<1,R=L+1;
			if(L>n)
			{
				a[now]=0;
				break;
			}
			if(a[L]>a[R])
			{
				a[now]=a[L];
				now=L;
			}
			else
			{
				a[now]=a[R];
				now=R;
			}
		}
		return N;
	}
	int L=N<<1,R=L+1;
	if(rem[L]==0)return go(R);
	if(rem[R]==0)return go(L);
	if(a[L]>a[R])return go(R);
	else return go(L);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int h,g;
		scanf("%d%d",&h,&g);
		n=(1<<h)-1,m=(1<<g)-1;
		fup(i,1,n,1)scanf("%lld",a+i);
		fup(i,n+1,2*n+1,1)a[i]=0;
		init(1);
		Vi ans;
		fup(i,1,n-m,1)ans.pb(go(1));
		ll sum=0;
		fup(i,1,m,1)sum+=a[i];
		printf("%lld\n",sum);
		for(int x:ans)printf("%d ",x);
		puts("");
	}
}