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
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

ld x[100000],y[100000],a[100000],b[100000];
ld a0,b0;
int main() {
	SYNC;
	cout<<fixed;
	cout.precision(9);
	int n;
	cin>>n;
	fup(i,0,n-1,1)cin>>x[i];
	fup(i,0,n-1,1)cin>>y[i];
	if(x[0]==0)a[0]=0,b[0]=y[0];
	else
	{
		a[0]=((x[0]+y[0])-sqrtl((x[0]+y[0])*(x[0]+y[0])-4*x[0]))/2;
		b[0]=x[0]/a[0];
	}
	a0+=a[0],b0+=b[0];
	ld ze=0;
	fup(i,1,n-1,1)
	{
		ld c=x[i]+y[i];
		ld t1=(a0-b0+c);
		ld t2=sqrtl(max(ze,t1*t1-4*x[i]+4*b0*c));
		t1/=2,t2/=2;
		if(t1-t2<0)b[i]=t1+t2;
		else b[i]=t1-t2;
		a[i]=c-b[i];
		a0+=a[i],b0+=b[i];
	}
	fup(i,0,n-1,1)cout<<a[i]<<' ';
	cout<<'\n';
	fup(i,0,n-1,1)cout<<b[i]<<' ';
}