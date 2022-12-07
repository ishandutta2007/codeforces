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
#define INF 987654321987654321
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
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int n,m;
Pi p[100000],q[100000];
bool chk[100000];
bool cmp(Pi p1,Pi p2)
{
	if(p1.Y!=p2.Y)return p1.Y<p2.Y;
	return p1.X<p2.X;
}
int find(int x,int y)
{
	int r=lower_bound(p,p+m,mp(x,y))-p;
	if(r==m || p[r]!=mp(x,y))return -1;
	return r;
}
int main() {
	scanf("%d%d",&n,&m);
	fup(i,0,m-1,1)
	{
		scanf("%d%d",&p[i].X,&p[i].Y);
		q[i]=p[i];
	}
	sort(p,p+m);sort(q,q+m,cmp);
	queue<int> Q;
	fup(i,0,m-1,1)
	{
		if(p[i].X==n || p[i].Y==1)
		{
			Q.push(i);
			chk[i]=1;
		}
	}
	while(!Q.empty())
	{
		int t=Q.front();
		Q.pop();
		if(p[t].X==1 || p[t].Y==n)return !printf("-1");
		fup(i,-1,1,1)
			fup(j,-1,1,1)
		{
			if(i==0 && j==0)continue;
			int tt=find(p[t].X+i,p[t].Y+j);
			if(tt!=-1 && !chk[tt])
			{
				chk[tt]=1;
				Q.push(tt);
			}
		}
		int tt=upper_bound(p,p+m,mp(p[t].X-1,p[t].Y-1))-p-1;
		if(tt==m)tt=-1;
		else if(p[tt].X!=p[t].X-1)tt=-1;
		if(tt!=-1 && !chk[tt])
		{
			Q.push(tt);
			chk[tt]=1;
		}
		tt=lower_bound(q,q+m,mp(p[t].X+1,p[t].Y+1),cmp)-q;
		if(tt==m)tt=-1;
		else
		{
			int y=q[tt].Y;
			tt=lower_bound(p,p+m,mp(q[tt].X,q[tt].Y))-p;
			if(p[tt].Y!=p[t].Y+1)tt=-1;
		}
		if(tt!=-1 && !chk[tt])
		{
			Q.push(tt);
			chk[tt]=1;
		}
	}
	printf("%d",2*n-2);
}