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
#define INF 1987654321987654321
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
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

db eps=1e-9;
struct A{
	ll x1,y1,x2,y2,g;
}a[1000];
map<Pll,int> M;
Pll P(ll a,ll b,ll c,ll d,ll e,ll f,ll g1,ll g2,ll xa,ll ya)
{
	ll det=a*d-b*c;
	if(det==0)return mp(-INF,-INF);
	ll t1=e*d-b*f,t2=a*f-e*c;
	db r1=1.0*t1/det,r2=1.0*t2/det;
	if(r1>1.0 || r1<0 || r2>1.0 || r2<0)return mp(-INF,-INF);
	r1*=g1,r2*=g2;
	db rr1=floor(r1+eps),rr2=floor(r2+eps);
	if(abs(rr1-r1)>eps || abs(rr2-r2)>eps)return mp(-INF,-INF);
	ll q1=a/g1*(ll)rr1+xa,q2=c/g1*(ll)rr1+ya;
	return mp(q1,q2);
}
int main() {
	int n;
	scanf("%d",&n);
	ll ans=0;
	fup(i,0,n-1,1)
	{
		scanf("%lld%lld%lld%lld",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		a[i].g=gcd(abs(a[i].x2-a[i].x1),abs(a[i].y2-a[i].y1));
		ans+=a[i].g+1;
	}
	fup(i,0,n-1,1)
		fup(j,i+1,n-1,1)
	{
		ll A,B,C,D,E,F;
		A=a[i].x2-a[i].x1,B=a[j].x1-a[j].x2,E=a[j].x1-a[i].x1;
		C=a[i].y2-a[i].y1,D=a[j].y1-a[j].y2,F=a[j].y1-a[i].y1;
		Pll p=P(A,B,C,D,E,F,a[i].g,a[j].g,a[i].x1,a[i].y1);
		if(p.X!=-INF)M[p]++;
	}
	for(auto it=M.begin();it!=M.end();it++)
	{
		ll t=it->Y;
		ans-=(ll)sqrt(2*t);
	}
	printf("%lld",ans);
}