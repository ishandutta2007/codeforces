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
#define INF 1987654321
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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

double ang(int x,int y)
{
	if(y==0)
	{
		if(x>0)return 0;
		else return -PI;
	}
	if(x==0)
	{
		if(y>0)return PI/2;
		else PI*3/2;
	}
	if(x>0&&y>0)return atan(1.0*y/x);
	if(x<0)return atan(1.0*y/x)+PI;
	return atan(1.0*y/x)+2*PI;
}
Pd ans[7];
db theta;
Pd rot(Pd P)
{
	Pd res;
	res.X=cos(theta)*P.X+sin(theta)*P.Y;
	res.Y=-sin(theta)*P.X+cos(theta)*P.Y;
	return res;
}
int main() {
	db px,py,vx,vy,a,b,c,d;
	cin>>px>>py>>vx>>vy>>a>>b>>c>>d;
	ans[0]=mp(0,b);
	ans[1]=mp(-a/2,0);
	ans[2]=mp(-c/2,0);
	ans[3]=mp(-c/2,-d);
	ans[4]=mp(c/2,-d);
	ans[5]=mp(c/2,0);
	ans[6]=mp(a/2,0);
	theta=PI/2-ang(vx,vy);
	fup(i,0,6,1)ans[i]=rot(ans[i]);
	fup(i,0,6,1)printf("%.10f %.10f\n",ans[i].X+px,ans[i].Y+py);
}