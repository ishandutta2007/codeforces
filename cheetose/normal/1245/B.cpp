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
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

char ss[200],ans[200];
void solve()
{
	MEM0(ans);
	int n,a,b,c;
	scanf("%d%d%d%d%s",&n,&a,&b,&c,ss);
	int r=0,p=0,s=0,cnt=0;
	fup(i,0,n-1,1)
	{
		if(ss[i]=='R' && b>0)
		{
			ans[i]='P';
			cnt++,b--;
		}
		if(ss[i]=='P' && c>0)
		{
			ans[i]='S';
			cnt++,c--;
		}
		if(ss[i]=='S' && a>0)
		{
			ans[i]='R';
			cnt++,a--;
		}
	}
	if(cnt<(n+1)/2)
	{
		puts("NO");
		return;
	}
	puts("YES");
	fup(i,0,n-1,1)
	{
		if(!ans[i])
		{
			if(a>0)ans[i]='R',a--;
			else if(b>0)ans[i]='P',b--;
			else ans[i]='S',c--;
		}
	}
	puts(ans);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}