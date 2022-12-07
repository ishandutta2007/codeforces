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

Vi vv,ans;
int a[200001],b[200001],c[400001],cnt[400001];
int main() {
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	fup(i,0,n-1,1)scanf("%d",a+i),vv.pb(a[i]);
	fup(i,0,m-1,1)scanf("%d",b+i),vv.pb(b[i]);
	sort(ALL(vv));
	vv.resize(unique(ALL(vv))-vv.begin());
	fup(i,0,n-1,1)a[i]=lower_bound(ALL(vv),a[i])-vv.begin();
	fup(i,0,m-1,1)b[i]=lower_bound(ALL(vv),b[i])-vv.begin(),cnt[b[i]]++;
	int cc=vv.size();
	int tt=0;
	fup(i,0,cc-1,1)if(cnt[i]==0)tt++;
	fup(k,0,p-1,1)
	{
		int tot=tt;
		if(1LL*(m-1)*p+k>=(ll)n)break;
		fup(i,k,k+(m-2)*p,p)
		{
			c[a[i]]++;
			if(c[a[i]]==cnt[a[i]])tot++;
			if(c[a[i]]==cnt[a[i]]+1)tot--;
		}
		fup(i,k+(m-1)*p,n-1,p)
		{
			int l=i-(m-1)*p;
			c[a[i]]++;
			if(c[a[i]]==cnt[a[i]])tot++;
			if(c[a[i]]==cnt[a[i]]+1)tot--;
			if(tot==cc)ans.pb(l+1);
			c[a[l]]--;
			if(c[a[l]]==cnt[a[l]])tot++;
			if(c[a[l]]==cnt[a[l]]-1)tot--;
		}
		fup(i,k,n-1,p)c[a[i]]=0;
	}
	sort(ALL(ans));
	printf("%d\n",ans.size());
	for(int x:ans)printf("%d ",x);
}