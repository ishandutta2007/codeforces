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
typedef pair<double, double> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

ll d[2][5][5];
char s[1000005];
int main() {
	int n;
	scanf("%s",s+1);
	n=strlen(s+1);
	d[0][4][4]=1;
	fup(i,1,n,1)
	{
		int t=i&1;
		MEM0(d[t]);
		if(s[i]=='0' || s[i]=='?')
		{
			fup(x,0,4,1)
				fup(y,0,4,1)
			{
				if(y==2 || y==3)continue;
				if(y==0 || y==4)d[t][y][0]=(d[t][y][0]+d[1-t][x][y])%MOD;
				if(y==1 && x==3)d[t][y][0]=(d[t][y][0]+d[1-t][x][y])%MOD;
			}
		}
		if(s[i]=='1' || s[i]=='?')
		{
			fup(x,0,4,1)
				fup(y,0,4,1)
			{
				if(y==2)continue;
				if(y==1 && x!=3)continue;
				d[t][y][1]=(d[t][y][1]+d[1-t][x][y])%MOD;
			}
		}
		if(s[i]=='2' || s[i]=='?')
		{
			fup(x,0,4,1)
				fup(y,0,4,1)
			{
				if(y==3)d[t][y][2]=(d[t][y][2]+d[1-t][x][y])%MOD;
			}
		}
		if(s[i]=='*' || s[i]=='?')
		{
			fup(x,0,4,1)
				fup(y,0,4,1)
			{
				if(y==1 && x!=3)d[t][y][3]=(d[t][y][3]+d[1-t][x][y])%MOD;
				if(y==2 || y==3 || y==4)d[t][y][3]=(d[t][y][3]+d[1-t][x][y])%MOD;
			}
		}
	}
	ll ans=0;
	int t=n&1;
	fup(i,0,4,1)
		fup(j,0,4,1)
	{
		if(i!=3 && j==1)continue;
		if(j==2)continue;
		ans=(ans+d[t][i][j])%MOD;
	}
	printf("%lld",ans);
}