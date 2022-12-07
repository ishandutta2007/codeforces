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

string s[1000000];
int n,r,c,to[1000001][20];
Pi p[1000000];
int res(int l)
{
	int now=l;
	fdn(i,19,0,1)
	{
		if(r&(1<<i))
		{
			now=to[now][i];
		}
	}
	return now-l;
}
int main() {
	SYNC;
	cin>>n>>r>>c;
	fup(i,0,n-1,1)cin>>s[i];
	p[0].X=0,p[0].Y=s[0].length()-1;
	fup(i,1,n-1,1)
	{
		p[i].X=p[i-1].Y+2;
		p[i].Y=p[i].X+s[i].length()-1;
	}
	to[n][0]=n;
	int rr=0;
	fup(i,0,n-1,1)
	{
		if(s[i].length()>c)
		{
			to[i][0]=i;
			rr=i+1;
		}
		else
		{
			while(rr<n && p[rr].Y-p[i].X+1<=c)
				rr++;
			to[i][0]=rr;
		}
	}
	fup(j,1,19,1)
		fup(i,0,n,1)
			to[i][j]=to[to[i][j-1]][j-1];
	int ans=-1,what=-1;
	fup(i,0,n-1,1)
	{
		int t=res(i);
		if(t>ans)
		{
			ans=t;
			what=i;
		}
	}
	fup(i,0,r-1,1)
	{
		fup(j,what,to[what][0]-1,1)
		{
			if(j!=what)cout<<' ';
			cout<<s[j];
		}
		cout<<'\n';
		what=to[what][0];
	}
}