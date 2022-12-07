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
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

Vi v[100001];
bool is(int x,int y)
{
	if(x>100000)return 0;
	return binary_search(ALL(v[x]),y);
}
int main() {
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
	}
	fup(i,0,100000,1)sort(ALL(v[i]));
	int ans=0;
	fup(x,0,100000,1)
	{
		int N=v[x].size();
		if(N<400)
		{
			fup(i,0,N-1,1)
			{
				fup(j,i+1,N-1,1)
				{
					int d=v[x][j]-v[x][i];
					if(is(x+d,v[x][i]) && is(x+d,v[x][j]))ans++;
				}
			}
		}
		else
		{
			fup(xx,x+1,100000,1)
			{
				int M=v[xx].size();
				fup(i,0,M-1,1)
				{
					int yy=v[xx][i],d=xx-x;
					if(is(x,yy) && is(x,yy+d) && is(xx,yy+d))ans++;
				}
			}
		}
	}
	printf("%d",ans);
}