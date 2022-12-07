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
#define INF 1000000000000000005
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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

char s[300005];
int a,b,n;
void solve(){
	scanf("%d%d%s",&a,&b,s);
	n=strlen(s);
	int tmp=0;
	Vi v;
	fup(i,0,n-1,1)
	{
		if(s[i]=='X')
		{
			if(tmp>0)v.pb(tmp);
			tmp=0;
		}
		else tmp++;
	}
	if(tmp>0)v.pb(tmp);
	int c1=0,c2=0;
	int l=-1;
	for(int x:v)
	{
		if(x<b)continue;
		if(x<a)
		{
			puts("NO");
			return;
		}
		if(x<2*b)c1++;
		if(x>=2*b)
		{
			c2++;
			l=x;
		}
	}
	if(c2>1)
	{
		puts("NO");
		return;
	}
	if(c2==0)
	{
		puts(c1&1?"YES":"NO");
		return;
	}
	for(int t1=0;l-a-t1>=0;t1++)
	{
		int t2=l-a-t1;
		if(t1>=2*b || (t1>=b && t1<a))continue;
		if(t2>=2*b || (t2>=b && t2<a))continue;
		int c=0;
		if(t1>=a && t1<2*b)c++;
		if(t2>=a && t2<2*b)c++;
		if((c1+c)%2==0)
		{
			puts("YES");
			return;
		}
	}
	puts("NO");
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}