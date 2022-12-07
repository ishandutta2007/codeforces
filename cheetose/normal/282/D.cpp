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
#define INF 987654321987654321
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
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int d[300][300][2];
int go(int x,int y,int c)
{
	if(x==0&&y==0)return 1-c;
	int &ret=d[x][y][c];
	if(ret!=-1)return ret;
	if(c==0)
	{
		ret=1;
		fup(i,1,x,1)ret=min(ret,go(x-i,y,1-c));
		fup(i,1,y,1)ret=min(ret,go(x,y-i,1-c));
		int t=min(x,y);
		fup(i,1,t,1)ret=min(ret,go(x-i,y-i,1-c));
		return ret;
	}
	ret=0;
	fup(i,1,x,1)ret=max(ret,go(x-i,y,1-c));
	fup(i,1,y,1)ret=max(ret,go(x,y-i,1-c));
	int t=min(x,y);
	fup(i,1,t,1)ret=max(ret,go(x-i,y-i,1-c));
	return ret;
}
int main() {
	int n;
	scanf("%d",&n);
	if(n==1)
	{
		int x;
		scanf("%d",&x);
		return 0*puts(x?"BitLGM":"BitAryo");
	}
	if(n==2)
	{
		MEM_1(d);
		int x,y;
		scanf("%d%d",&x,&y);
		puts(go(x,y,0)==1?"BitAryo":"BitLGM");
	}
	else
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		puts((x^y^z)==0?"BitAryo":"BitLGM");
	}
}