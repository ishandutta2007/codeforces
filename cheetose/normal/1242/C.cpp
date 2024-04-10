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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int n;
Vll v[15];
ll s[15],T;
map<ll,Pi> M;
VPi tmp,vv[1<<15];
Pll ans[15];
void dfs(Pi p,int k)
{
	tmp.pb(p);
	ll R=T-s[p.X]+v[p.X][p.Y];
	if(M.find(R)==M.end())return;
	Pi np=M[R];
	if(!(k&(1<<np.X)))
	{
		dfs(np,k|(1<<np.X));
		return;
	}
	else if(np==tmp[0])
	{
		vv[k]=tmp;
		return;
	}
}
int d[1<<15];
int go(int K)
{
	if(K==0)return 1;
	int &ret=d[K];
	if(~ret)return ret;
	ret=0;
	for(int x=K;x;x=(x-1)&K)
	{
		if(!vv[x].empty())ret=max(ret,go(K^x));
	}
	return ret;
}
void track(int K)
{
	if(K==0)return;
	for(int x=K;x;x=(x-1)&K)
	{
		if(!vv[x].empty() && go(K^x)==1)
		{
			int N=vv[x].size();
			fup(i,0,N-1,1)
			{
				ans[vv[x][i].X]=mp(v[vv[x][i].X][vv[x][i].Y],vv[x][(i+N-1)%N].X+1);
			}
			track(K^x);
			return;
		}
	}
}
int main() {
	MEM_1(d);
	scanf("%d",&n);
	ll sum=0;
	fup(i,0,n-1,1)
	{
		int c;
		scanf("%d",&c);
		fup(j,0,c-1,1)
		{
			ll x;
			scanf("%lld",&x);
			v[i].pb(x);
			sum+=x;
			s[i]+=x;
			M[x]=mp(i,j);
		}
	}
	if(sum%n)return !printf("No");
	T=sum/n;
	fup(i,0,n-1,1)
	{
		fup(j,0,(int)v[i].size()-1,1)
		{
			tmp.clear();
			dfs(mp(i,j),1<<i);
		}
	}
	if(go((1<<n)-1)==0)return !printf("No");
	puts("Yes");
	track((1<<n)-1);
	fup(i,0,n-1,1)printf("%lld %lld\n",ans[i].X,ans[i].Y);
}