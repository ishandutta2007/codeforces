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

map<int,Vi> M;
struct query{
	int l,r,i;
}q[1000000];
int a[1000001],xsum[1000001],ans[1000000],tree[1000001];
int n;
void upd(int i, int k)
{
	while (i <= n)
	{
		tree[i]^=k;
		i += (i&-i);
	}
}
int sum(int i)
{
	int c = 0;
	while (i > 0)
	{
		c ^= tree[i];
		i -= (i&-i);
	}
	return c;
}
int main() {
	scanf("%d",&n);
	fup(i,1,n,1)
	{
		scanf("%d",a+i);
		xsum[i]=xsum[i-1]^a[i];
		M[a[i]].pb(i);
	}
	for(auto it=M.begin();it!=M.end();it++)
	{
		int x=it->X,y=it->Y.back();
		upd(y,x);
	}
	int m;
	scanf("%d",&m);
	fup(i,0,m-1,1)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].i=i;
	}
	sort(q,q+m,[&](query q1,query q2){return q1.r>q2.r;});
	int p=n;
	fup(i,0,m-1,1)
	{
		int l=q[i].l,r=q[i].r,ii=q[i].i;
		while(p>r)
		{
			upd(p,a[p]);
			auto &it=M[a[p]];
			it.pop_back();
			if(!it.empty())upd(it.back(),a[p]);
			p--;
		}
		ans[ii]=xsum[r]^xsum[l-1]^sum(r)^sum(l-1);
	}
	fup(i,0,m-1,1)printf("%d\n",ans[i]);
}