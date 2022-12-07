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
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
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

int n,m;
int a[401][401];
int b[401][401],c[401][401],d[801][401],e[801][401];
int main() {
	scanf("%d%d",&n,&m);
	fup(i,1,n,1)fup(j,1,m,1)scanf("%1d",&a[i][j]);
	fup(i,1,n,1)
	{
		fup(j,1,m,1)
		{
			b[i][j]=b[i][j-1]+a[i][j];
			c[j][i]=c[j][i-1]+a[i][j];
		}
	}
	fup(i,1,n,1)
	{
		fup(j,1,m,1)
		{
			e[i+j][i]=e[i+j][i-1]+a[i][j];
			d[i-j+400][i]=d[i-j+400][i-1]+a[i][j];
		}
	}
	int ans=0;
	fup(i,1,n,1)
	{
		fup(j,1,m,1)
		{
			fup(k,j+1,m,1)
			{
				if(b[i][k]-b[i][j-1])break;
				int t=k-j;
				if(i-t>0)
				{
					if(c[j][i]==c[j][i-t-1] && d[i-k+400][i]==d[i-k+400][i-t-1])ans++;
					if(c[k][i]==c[k][i-t-1] && e[i+j][i]==e[i+j][i-t-1])ans++;
				}
				if(i+t<=n)
				{
					if(c[j][i-1]==c[j][i+t] && e[i+k][i+t]==e[i+k][i-1])ans++;
					if(c[k][i+t]==c[k][i-1] && d[i-j+400][i+t]==d[i-j+400][i-1])ans++;
				}
				if(t%2==0)
				{
					t/=2;
					if(i-t>0 && e[i+j][i]==e[i+j][i-t-1] && d[i-k+400][i]==d[i-k+400][i-t-1])ans++;
					if(i+t<=n && e[i+k][i-1]==e[i+k][i+t] && d[i-j+400][i+t]==d[i-j+400][i-1])ans++;
				}
			}
		}
	}
	fup(j,1,m,1)
	{
		fup(i,1,n,1)
		{
			fup(k,i+2,n,2)
			{
				if(c[j][k]-c[j][i-1])break;
				int t=(k-i)/2;
				if(j-t>0 && e[i+j][i+t]==e[i+j][i-1] && d[k-j+400][k]==d[k-j+400][i+t-1])ans++;
				if(j+t<=m && e[k+j][k]==e[k+j][i+t-1] && d[i-j+400][i+t]==d[i-j+400][i-1])ans++;
			}
		}
	}
	printf("%d",ans);
}