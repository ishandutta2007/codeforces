#include <bits/stdc++.h>
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
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<ld> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

ll cross(Pll &p1,Pll &p2){
	return p1.X*p2.Y-p2.X*p1.Y;
}
Pll operator -(const Pll &p1,const Pll &p2){
	return mp(p1.X-p2.X,p1.Y-p2.Y);
}
int quad(const Pll &p){
	if(p.X>0 && p.Y>=0)return 1;
	if(p.X<=0 && p.Y>0)return 2;
	if(p.X<0 && p.Y<=0)return 3;
	return 4;
}
ll nCr(int n,int r)
{
	ll res=1;
	fdn(i,n,n-r+1,1)res*=i;
	fup(i,2,r,1)res/=i;
	return res;
}
Pll p[2500];
int main() {
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)scanf("%lld%lld",&p[i].X,&p[i].Y);
	ll ans=0;
	fup(i,0,n-1,1)
	{
		VPll v;
		fup(j,0,n-1,1)
			if(i!=j)v.pb(p[j]-p[i]);
		sort(ALL(v),[&](Pll p1,Pll p2){
			if(quad(p1)!=quad(p2))return quad(p1)<quad(p2);
			return cross(p1,p2)>0;
		});
		int jj=0;
		int N=v.size();
		fup(ii,0,N-1,1)
		{
			while(jj<ii+N && cross(v[ii],v[jj%N])>=0)jj++;
			ans+=nCr(jj-ii-1,3);
		}
	}
	printf("%lld\n",5*nCr(n,5)-ans);
}