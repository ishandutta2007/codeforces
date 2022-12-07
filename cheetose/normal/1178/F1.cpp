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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int n,m;
ll d[501][501];
int a[501],t[501],mn[501][501];
ll go(int L,int R)
{
	if(L>=R)return 1;
	ll &ret=d[L][R];
	if(~ret)return ret;
	ret=0;
	ll t1=0,t2=0;
	int m=t[mn[L][R]];
	fup(i,L,m,1)t1=(t1+go(L,i-1)*go(i,m-1))%MOD;
	fup(i,m,R,1)t2=(t2+go(m+1,i)*go(i+1,R))%MOD;
	return ret=(t1*t2)%MOD;
}
int main(){
	MEM_1(d);
	scanf("%d%d",&n,&m);
	fup(i,1,n,1)scanf("%d",a+i),t[a[i]]=i;
	fup(i,1,n,1)
	{
		mn[i][i]=a[i];
		fup(j,i+1,n,1)
		{
			mn[i][j]=min(mn[i][j-1],a[j]);
		}
	}
	printf("%lld\n",go(1,n));
}