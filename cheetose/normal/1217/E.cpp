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
#define INF 1000000007
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

Pi merge(Pi p1,Pi p2)
{
	if(p1.X==INF)return p2;
	if(p2.X==INF)return p1;
	Pi p=mp(INF,INF);
	if(p1.X<p2.X)
	{
		p.X=p1.X;
		p1.X=p1.Y;
	}
	else
	{
		p.X=p2.X;
		p2.X=p2.Y;
	}
	if(p1.X<p2.X)
	{
		p.Y=p1.X;
		p1.X=p1.Y;
	}
	else
	{
		p.Y=p2.X;
		p2.X=p2.Y;
	}
	return p;
}
Pi tree[10][524288];

void upd(int Q,int node, int S, int E, int k, int dif)
{
	if (S == E)
	{
		tree[Q][node]=mp(dif,INF);
		return;
	}
	if (k <= (S + E) / 2)upd(Q,node * 2, S, (S + E) / 2, k, dif);
	else upd(Q,node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
	tree[Q][node]=merge(tree[Q][node<<1],tree[Q][node<<1|1]);
}

Pi find(int Q,int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return mp(INF,INF);
	if (i <= S && j >= E)return tree[Q][node];
	return merge(find(Q,node * 2, S, (S + E) / 2, i, j), find(Q,node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
int sum(Pi &p)
{
	if(p.Y==INF)return INF<<1;
	return p.X+p.Y;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,1,n,1)
	{
		int xx;
		scanf("%d",&xx);
		int x=xx;
		fup(k,0,9,1)
		{
			int t=x%10;
			if(t>0)
				upd(k,1,1,n,i,xx);
			else
				upd(k,1,1,n,i,INF);
			x/=10;
		}
	}
	while(m--)
	{
		int o,x,y;
		scanf("%d%d%d",&o,&x,&y);
		if(o==1)
		{
			int xx=y;
			fup(k,0,9,1)
			{
				int t=xx%10;
				if(t>0)upd(k,1,1,n,x,y);
				else upd(k,1,1,n,x,INF);
				xx/=10;
			}
		}
		else
		{
			Pi p=mp(INF,INF);
			fup(k,0,9,1)
			{
				Pi pp=find(k,1,1,n,x,y);
				if(sum(p)>sum(pp))p=pp;
			}
			int ans=sum(p);
			if(ans==INF<<1)puts("-1");
			else printf("%d\n",ans);
		}
	}
}