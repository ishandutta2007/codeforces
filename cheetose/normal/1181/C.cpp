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

char s[1001][1001];
int D[1000][1000],U[1000][1000],R[1000][1000],mxU[1000][1000],mxD[1000][1000];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,0,n-1,1)scanf("%s",s[i]);
	fup(i,0,n-1,1)
	{
		R[i][m-1]=1;
		fdn(j,m-2,0,1)
		{
			if(s[i][j]==s[i][j+1])R[i][j]=R[i][j+1]+1;
			else R[i][j]=1;
		}
	}
	fup(j,0,m-1,1)
	{
		U[0][j]=1;
		mxD[0][j]=R[0][j];
		fup(i,1,n-1,1)
		{
			if(s[i][j]==s[i-1][j])
			{
				U[i][j]=U[i-1][j]+1;
				mxD[i][j]=min(mxD[i-1][j],R[i][j]);
			}
			else 
			{
				U[i][j]=1;
				mxD[i][j]=R[i][j];
			}
		}
		D[n-1][j]=1;
		mxU[n-1][j]=R[n-1][j];
		fdn(i,n-2,0,1)
		{
			if(s[i][j]==s[i+1][j])
			{
				D[i][j]=D[i+1][j]+1;
				mxU[i][j]=min(mxU[i+1][j],R[i][j]);
			}
			else 
			{
				D[i][j]=1;
				mxU[i][j]=R[i][j];
			}
		}
	}
	ll ans=0;
	fup(j,0,m-1,1)
	{
		int i=D[0][j];
		while(i<n)
		{
			int k=i+D[i][j];
			if(k>=n)break;
			int c=D[i][j];
			if(U[i-1][j]<c || D[k][j]<c)
			{
				i=k;
				continue;
			}
			int t=min({mxU[i][j],mxU[i-c][j],mxD[k+c-1][j]});
			ans+=t;
			i=k;
		}
	}
	printf("%lld",ans);
}