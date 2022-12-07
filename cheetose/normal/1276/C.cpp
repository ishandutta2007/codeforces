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
const int MOD = 1000000009;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={-1,-2,1,-2,2,-1,2,1},ddy[]={-2,-1,-2,1,-1,2,1,2};

int a[400005];
Vi v[400001];
int main(){
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)scanf("%d",a+i);
	sort(a,a+n);
	int t=1;
	fup(i,1,n-1,1)
	{
		if(a[i]!=a[i-1])
		{
			v[t].pb(a[i-1]);
			t=1;
		}
		else t++;
	}
	v[t].pb(a[n-1]);
	Vi tt;
	fup(i,1,n,1)
	{
		for(int x:v[i])tt.pb(i);
	}
	int N=0,M=0;
	int NN=tt.size(),T=0,c=0;
	for(int i=1;i*i<=n;i++)
	{
		while(T<NN && tt[T]<=i)
		{
			c+=tt[T];
			T++;
		}
		int tot=(NN-T)*i+c;
		tot-=(tot%i);
		if(tot>=i*i && tot>=N*M)
		{
			N=i,M=tot/i;
		}
	}
	vector<Vi> ans(N);
	fup(i,0,N-1,1)ans[i].resize(M);
	int x=0,y=0;
	fdn(k,n,1,1)
	{
		for(int c:v[k])
		{
			fup(TT,1,k,1)
			{
				if(TT>N)break;
				ans[x][y]=c;
				if(x==N-1)
				{
					y=(y-x+1+M)%M,x=0;
				}
				else
				{
					x++,y=(y+1)%M;
				}
			}
		}
	}
	printf("%d\n%d %d\n",N*M,N,M);
	fup(i,0,N-1,1)
	{
		fup(j,0,M-1,1)
			printf("%d ",ans[i][j]);
		puts("");
	}
}