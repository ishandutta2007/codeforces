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
const int MOD = 1000000021;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

bitset<4300001> prime;
int a[300001];
ll H[300001],inv[300001];
Vi v[300001];
Vi p={1};
ll ans[300001];
int L[300002],R[300002];
void erase(int x)
{
	int l=L[x],r=R[x];
	R[l]=r,L[r]=l;
}
int main(){
	prime.set();
	prime[0]=prime[1]=0;
	fup(i,2,4300000,1)
	{
		if(!prime[i])continue;
		p.pb(i);
		fup(j,i+i,4300000,i)
			prime[j]=0;
	}
	H[0]=inv[0]=1;
	int n;
	scanf("%d",&n);
	fup(i,0,n+1,1)
	{
		if(i)L[i]=i-1;
		if(i<=n)R[i]=i+1;
	}
	fup(i,1,n,1)v[i].pb(0);
	fup(i,1,n,1)
	{
		scanf("%d",a+i);
		v[a[i]].pb(i);
	}
	fup(i,1,n,1)v[i].pb(n+1);
	fup(i,1,n,1)
	{
		H[i]=(H[i-1]*p[a[i]])%MOD;
		inv[i]=POW(H[i],MOD-2);
	}
	ans[0]=1;
	fup(i,1,n,1)ans[i]=(ans[i-1]*p[i])%MOD;
	int res=0;
	fup(k,1,n,1)
	{
		fup(i,1,(int)v[k].size()-2,1)
		{
			fup(j,max(L[v[k][i]],v[k][i-1])+k,min(R[v[k][i]],v[k][i+1])-1,1)if((H[j]*inv[j-k])%MOD==ans[k])res++;
		}
		fup(i,1,(int)v[k].size()-2,1)erase(v[k][i]);
	}
	printf("%d",res);
}