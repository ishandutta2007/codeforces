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
#define PI 3.14159265358979323846264
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

iiii query[100000];
int ans[100000];
map<int,Viii> M;
int cc;
void upd(int i,Vi& tree,int k)
{
	int n=tree.size();
	while (i < n)
	{
		tree[i]+=k;
		i += (i&-i);
	}
}
int sum(int i,Vi& tree)
{
	int c = 0;
	while (i > 0)
	{
		c += tree[i];
		i -= (i&-i);
	}
	return c;
}
int main() {
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x==3)M[z].pb(iii(x,y,cc++));
		else M[z].pb(iii(x,y,-1));
	}
	for(auto it=M.begin();it!=M.end();it++)
	{
		Viii v=it->Y;
		int N=v.size();
		Vi vv;
		fup(i,0,N-1,1)
			vv.pb(get<1>(v[i]));
		sort(ALL(vv));
		vv.resize(unique(ALL(vv))-vv.begin());
		fup(i,0,N-1,1)
			get<1>(v[i])=lower_bound(ALL(vv),get<1>(v[i]))-vv.begin();
		Vi tree(N+5,0);
		fup(i,0,N-1,1)
		{
			int x,y,z;
			tie(x,y,z)=v[i];
			if(x==1) upd(y+1,tree,1);
			else if(x==2)upd(y+1,tree,-1);
			else ans[z]=sum(y+1,tree);
		}
	}
	fup(i,0,cc-1,1)printf("%d\n",ans[i]);
}