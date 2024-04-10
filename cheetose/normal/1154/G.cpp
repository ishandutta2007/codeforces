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

int t[10000001][2];
int main(){
	MEM_1(t);
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)
	{
		int x;
		scanf("%d",&x);
		if(t[x][0]==-1)t[x][0]=i;
		else if(t[x][1]==-1)t[x][1]=i;
	}
	ll ans=INF;
	int x=-1,y=-1;
	fup(g,1,10000000,1)
	{
		int g1=-1,g2=-1,q=-1,w=-1;
		fup(i,g,10000000,g)
		{
			if(t[i][0]!=-1)
			{
				if(g1==-1)
				{
					g1=i;
					q=t[i][0];
				}
				else if(g2==-1)
				{
					g2=i;
					w=t[i][0];
				}
			}
			if(t[i][1]!=-1)
			{
				if(g2==-1)
				{
					g2=i;
					w=t[i][1];
				}
			}
			if(g2!=-1)break;
		}
		if(g2==-1)continue;
		ll tmp=1LL*g1*g2/g;
		if(ans>tmp)
		{
			ans=tmp;
			x=q,y=w;
		}
	}
	if(x>y)swap(x,y);
	printf("%d %d\n",x,y);
}