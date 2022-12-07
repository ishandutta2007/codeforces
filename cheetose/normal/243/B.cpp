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

Vi v[100001];
Pi p[100000];
bool cc[100001];
int n,m,h,t;
bool chk(int a,int b)
{
	int aa=0,bb=0,d=0;
	for(int x:v[a])
	{
		if(x==b)continue;
		aa++,d++;
		cc[x]=1;
	}
	for(int x:v[b])
	{
		if(x==a)continue;
		bb++;
		if(!cc[x])d++;
	}
	for(int x:v[a])cc[x]=0;
	return aa>=h&&bb>=t&&d>=h+t;
}
void print(int a,int b)
{
	puts("YES");
	printf("%d %d\n",a,b);
	set<int> SA,SB;
	for(int x:v[a])if(x!=b)SA.insert(x);
	for(int x:v[b])if(x!=a)SB.insert(x);
	Vi VA,VB,V;
	for(int x:v[a])
	{
		if(x==b)continue;
		if(SB.find(x)==SB.end())VA.pb(x);
		else V.pb(x);
	}
	for(int x:v[b])
	{
		if(x==a)continue;
		if(SA.find(x)==SA.end())VB.pb(x);
	}
	while(VA.size()<h)
	{
		VA.pb(V.back());
		V.pop_back();
	}
	while(VA.size()>h)VA.pop_back();
	while(VB.size()<t)
	{
		VB.pb(V.back());
		V.pop_back();
	}
	while(VB.size()>t)VB.pop_back();
	for(int x:VA)printf("%d ",x);
	puts("");
	for(int x:VB)printf("%d ",x);
	puts("");
}
int main() {
	scanf("%d%d%d%d",&n,&m,&h,&t);
	fup(i,0,m-1,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		p[i]=mp(x,y);
		if(v[x].size()<205)v[x].pb(y);
		if(v[y].size()<205)v[y].pb(x);
	}
	fup(i,0,m-1,1)
	{
		int x=p[i].X,y=p[i].Y;
		if(chk(x,y))
		{
			print(x,y);
			return 0;
		}
		if(chk(y,x))
		{
			print(y,x);
			return 0;
		}
	}
	puts("NO");
}