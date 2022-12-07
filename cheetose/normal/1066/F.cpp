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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

map<int,VPi> M;
Pi mx[200001],mn[200001];
ll d[2][200001],dd[200001];
inline ll dist(Pi p1,Pi p2){return abs(p1.X-p2.X)+abs(p1.Y-p2.Y);} 
int main() {
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		M[max(x,y)].pb(mp(x,y));
	}
	int i=0;
	for(auto it=M.begin();it!=M.end();it++)
	{
		i++;
		mx[i]=mp(-INF,INF),mn[i]=mp(INF,-INF);
		auto &v=it->Y;
		for(Pi &p:v)
		{
			if(p.X<mn[i].X)mn[i]=p;
			else if(p.X==mn[i].X && p.Y>mn[i].Y)mn[i]=p;
			if(p.Y<mx[i].Y)mx[i]=p;
			else if(p.Y==mx[i].Y && p.X>mx[i].X)mx[i]=p;
		}
		dd[i]=dist(mx[i],mn[i]);
	}
	fup(ii,1,i,1)
	{
		d[0][ii]=dd[ii]+min(d[0][ii-1]+dist(mx[ii],mn[ii-1]),d[1][ii-1]+dist(mx[ii],mx[ii-1]));
		d[1][ii]=dd[ii]+min(d[0][ii-1]+dist(mn[ii],mn[ii-1]),d[1][ii-1]+dist(mn[ii],mx[ii-1]));
	}
	printf("%lld",min(d[0][i],d[1][i]));
}