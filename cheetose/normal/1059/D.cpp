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
#define INF 987654321987654321.0
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
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

pair<ld,ld> p[100000];
int n;
bool ok(ld k)
{
	ld l=-1e13,r=1e13;
	fup(i,0,n-1,1)
	{
		ld x=p[i].X,y=p[i].Y;
		if((2*k-y)*y<0)return 0;
		ld rr=x+sqrtl((2*k-y)*y),ll=x-sqrtl((2*k-y)*y);
		l=max(l,ll),r=min(rr,r);
	}
	return l<=r;
}
int main() {
	SYNC;
	cin>>n;
	bool c1=0,c2=0;
	fup(i,0,n-1,1)
	{
		cin>>p[i].X>>p[i].Y;
		if(p[i].Y>0)c1=1;
		if(p[i].Y<0)c2=1;
	}
	if(c1&&c2)return cout<<-1,0;
	if(c2)fup(i,0,n-1,1)p[i].Y*=-1;
	ld l=0,r=1e18;
	int tt=100;
	while(tt--)
	{
		ld k=(l+r)/2;
		if(ok(k))r=k;
		else l=k;
	}
	cout<<fixed;
	cout.precision(10);
	cout<<l;
}