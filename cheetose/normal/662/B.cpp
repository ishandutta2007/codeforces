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
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int x[100001],y[100001];
char c[100001];
int parent[200001];
bool chk[200001],chk2[200001];
int n,m;
int find(int a)
{
	if (parent[a] <= 0)return a;
	return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a != b)
	{
		parent[a] += parent[b];
		parent[b] = a;
	}
}
inline int sz(int a){return -parent[find(a)];}
void init()
{
	fup(i,1,n,1)parent[i]=-1;
	fup(i,n+1,n+n,1)parent[i]=0;
	MEM0(chk);MEM0(chk2);
}
int main() {
	SYNC;
	cin>>n>>m;
	fup(i,0,m-1,1)
		cin>>x[i]>>y[i]>>c[i];
	
	init();
	fup(i,0,m-1,1)
	{
		if(c[i]=='R')
		{
			merge(x[i],y[i]);
			merge(x[i]+n,y[i]+n);
		}
		else
		{
			merge(x[i],y[i]+n);
			merge(x[i]+n,y[i]);
		}
	}
	bool rok=1;
	fup(i,1,n,1)
		if(find(i)==find(i+n))rok=0;
	Vi rans;
	if(rok)
	{
		fup(i,1,n,1)
		{
			if(chk[find(i)] || chk[find(i+n)])continue;
			chk[find(i)]=chk[find(i+n)]=1;
			if(sz(i)<=sz(i+n))chk2[find(i)]=1;
			else chk2[find(i+n)]=1;
		}
		fup(i,1,n,1)if(chk2[find(i)])rans.pb(i);
	}
	init();
	fup(i,0,m-1,1)
	{
		if(c[i]=='B')
		{
			merge(x[i],y[i]);
			merge(x[i]+n,y[i]+n);
		}
		else
		{
			merge(x[i],y[i]+n);
			merge(x[i]+n,y[i]);
		}
	}
	bool bok=1;
	fup(i,1,n,1)
		if(find(i)==find(i+n))bok=0;
	Vi bans;
	if(bok)
	{
		fup(i,1,n,1)
		{
			if(chk[find(i)] || chk[find(i+n)])continue;
			chk[find(i)]=chk[find(i+n)]=1;
			if(sz(i)<=sz(i+n))chk2[find(i)]=1;
			else chk2[find(i+n)]=1;
		}
		fup(i,1,n,1)if(chk2[find(i)])bans.pb(i);
	}
	if(!rok && !bok)return cout<<-1,0;
	if(!bok || (rok && rans.size()<bans.size()))
	{
		cout<<rans.size()<<'\n';
		for(int x:rans)cout<<x<<' ';
	}
	else
	{
		cout<<bans.size()<<'\n';
		for(int x:bans)cout<<x<<' ';
	}
}