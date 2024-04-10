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

int n,a[101],b[101];
int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
int d[101][1<<17],parent[101][1<<17],ans[101][1<<17],bt[60];
int main() {
	fill(&d[0][0],&d[100][1<<17],INF);
	fup(i,1,59,1)
		fup(j,0,16,1)if(i%p[j]==0)bt[i]|=(1<<j);
	d[0][0]=0;
	scanf("%d",&n);
	fup(i,1,n,1)scanf("%d",a+i);
	fup(i,1,n,1)
	{
		fup(k,1,59,1)
		{
			fup(j,0,(1<<17)-1,1)
			{
				if(j&bt[k])continue;
				if(d[i-1][j]+abs(a[i]-k)<d[i][j|bt[k]])
				{
					d[i][j|bt[k]]=d[i-1][j]+abs(a[i]-k);
					parent[i][j|bt[k]]=j;
					ans[i][j|bt[k]]=k;
				}
			}
		}
	}
	int res=INF,what=-1;
	fup(i,0,(1<<17)-1,1)
		if(d[n][i]<res)
		{
			res=d[n][i];
			what=i;
		}
	fdn(i,n,1,1)
	{
		b[i]=ans[i][what];
		what=parent[i][what];
	}
	fup(i,1,n,1)printf("%d ",b[i]);
}