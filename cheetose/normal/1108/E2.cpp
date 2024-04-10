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
#define INF 987654321
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

Vi vv;
int n,m;
int l[303],r[303],a[100005],s[100005];
int main() {
	scanf("%d%d",&n,&m);
	fup(i,1,n,1)scanf("%d",a+i);
	fup(i,1,m,1)
	{
		scanf("%d%d",l+i,r+i);
		vv.pb(l[i]);
		vv.pb(r[i]);
	}
	int res=*max_element(a+1,a+n+1)-*min_element(a+1,a+n+1),pp=-1;
	sort(ALL(vv));
	vv.resize(unique(ALL(vv))-vv.begin());
	int N=vv.size();
	fup(i,0,N-1,1)
	{
		fup(j,1,m,1)if(l[j]<=vv[i]&&vv[i]<=r[j])s[l[j]]--,s[r[j]+1]++;
		int mx=-INF,mn=INF;
		fup(j,1,n,1)
		{
			s[j]+=s[j-1];
			int t=a[j]+s[j];
			mx=max(mx,t);
			mn=min(mn,t);
		}
		if(res<mx-mn)
		{
			pp=i;
			res=mx-mn;
		}
		MEM0(s);
	}
	printf("%d\n",res);
	Vi ans;
	fup(i,1,m,1)if(l[i]<=vv[pp] && vv[pp]<=r[i])ans.pb(i);
	printf("%d\n",ans.size());
	for(int x:ans)printf("%d ",x);
}