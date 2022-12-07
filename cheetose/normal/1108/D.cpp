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
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int n;
char s[200001];
int a[200001];
int d[200001][4];
int x(char c)
{
	if(c=='R')return 0;
	if(c=='G')return 1;
	return 2;
}
int go(int N,int c)
{
	if(N==n)return 0;
	int &ret=d[N][c];
	if(ret!=-1)return ret;
	ret=INF;
	fup(i,0,2,1)
	{
		if(i==c)continue;
		ret=min(ret,(a[N]!=i)+go(N+1,i));
	}
	return ret;
}
void track(int N,int c)
{
	if(N==n)return;
	int t[3];
	fup(i,0,2,1)
	{
		if(i==c)t[i]=INF;
		else t[i]=(a[N]!=i)+go(N+1,i);
	}
	int mn=*min_element(t,t+3);
	if(t[0]==mn)
	{
		putchar('R');
		track(N+1,0);
	}
	else if(t[1]==mn)
	{
		putchar('G');
		track(N+1,1);
	}
	else if(t[2]==mn)
	{
		putchar('B');
		track(N+1,2);
	}
}
int main() {
	MEM_1(d);
	scanf("%d%s",&n,s);
	fup(i,0,n-1,1)a[i]=x(s[i]);
	printf("%d\n",go(0,3));
	track(0,3);
}