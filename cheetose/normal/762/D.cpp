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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int n;
ll a[3][100000],d[3][100000];
ll s(int j,int k)
{
	ll c=0;
	fup(i,0,2,1)if(k&(1<<i))c+=a[i][j];
	return c;
}
int main() {
	scanf("%d",&n);
	fup(i,0,2,1)fup(j,0,n-1,1)d[i][j]=-INF;
	fup(i,0,2,1)fup(j,0,n-1,1)scanf("%lld",a[i]+j);
	d[0][0]=s(0,1),d[1][0]=s(0,3),d[2][0]=s(0,7);
	fup(j,1,n-1,1)
	{
		d[0][j]=max({d[0][j-1]+s(j,1),d[1][j-1]+s(j,3),d[2][j-1]+s(j,7)});
		d[1][j]=max({d[0][j-1]+s(j,3),d[1][j-1]+s(j,2),d[2][j-1]+s(j,6)});
		d[2][j]=max({d[0][j-1]+s(j,7),d[1][j-1]+s(j,6),d[2][j-1]+s(j,4)});
		ll T=s(j-1,7)+s(j,7);
		if(j==1)
		{
			d[0][j]=max(d[0][j],T);
			d[2][j]=max(d[2][j],T);
		}
		else if(j>1)
		{
			d[0][j]=max(d[0][j],d[2][j-2]+T);
			d[2][j]=max(d[2][j],d[0][j-2]+T);
		}
	}
	printf("%lld",d[2][n-1]);
}