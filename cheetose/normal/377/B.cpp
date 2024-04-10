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
#define INF 1987654321
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
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

struct XXX{
	int ab,pr,id;
}a[100000];
int n,m;
ll c;
Pi bug[100000];
int ans[100000];
bool ok(int k)
{
	priority_queue<Pi,VPi,greater<Pi> > q;
	int t=0;
	ll tot=0;
	fup(i,0,m-1,k)
	{
		while(t<n && a[t].ab>=bug[i].X)
		{
			q.push(mp(a[t].pr,a[t].id));
			t++;
		}
		if(q.empty())return 0;
		tot+=q.top().X;
		int N=q.top().Y;
		q.pop();
		fup(ii,i,min(m-1,i+k-1),1)ans[bug[ii].Y]=N;
	}
	return tot<=c;
}
int main() {
	scanf("%d%d%lld",&n,&m,&c);
	fup(i,0,m-1,1)
	{
		scanf("%d",&bug[i].X);
		bug[i].Y=i;
	}
	fup(i,0,n-1,1)
		scanf("%d",&a[i].ab);
	fup(i,0,n-1,1)
	{
		scanf("%d",&a[i].pr);
		a[i].id=i+1;
	}
	sort(a,a+n,[&](XXX a1,XXX a2){return a1.ab>a2.ab;});
	sort(bug,bug+m,[&](Pi p1,Pi p2){return p1.X>p2.X;});
	int tt=INF;
	fup(i,0,n-1,1)if(a[i].ab>=bug[0].X)tt=min(tt,a[i].pr);
	if(tt>(int)c)return !printf("NO");
	puts("YES");
	int l=1,r=m;
	while(l<=r)
	{
		int k=(l+r)>>1;
		if(ok(k))r=k-1;
		else l=k+1;
	}
	ok(l);
	fup(i,0,m-1,1)printf("%d ",ans[i]);
}