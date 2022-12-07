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
#define INF 98765432198765321
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

Vi buc[500];
int n,q;
int a[200000],in[200000];
int main() {
	scanf("%d%d",&n,&q);
	fup(i,0,n-1,1)a[i]=i;
	int sz=sqrt(n);
	int N=(n-1)/sz+1;
	ll ans=0;
	fup(i,0,N-1,1)
	{
		int l=i*sz,r=min(n-1,(i+1)*sz-1);
		fup(ii,l,r,1)
		{
			buc[i].pb(a[ii]);
			in[ii]=i;
		}
	}
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		l--,r--;
		if(l==r)
		{
			printf("%lld\n",ans);
			continue;
		}
		if(l>r)swap(l,r);
		bool T=a[l]<a[r];
		int c1=a[l],c2=a[r];
		if(c1>c2)swap(c1,c2);
		int L=in[l],R=in[r],x=0;
		if(R-L>1)
		{
			fup(ii,L+1,R-1,1)
			{
				x+=upper_bound(ALL(buc[ii]),c2)-lower_bound(ALL(buc[ii]),c1);
			}
		}
		if(L==R)
		{
			fup(ii,l+1,r-1,1)
				if(a[ii]>c1 && a[ii]<c2)x++;
		}
		else
		{
			fup(ii,l+1,min(n-1,(L+1)*sz-1),1)if(a[ii]>c1 && a[ii]<c2)x++;
			fup(ii,R*sz,r-1,1)if(a[ii]>c1 && a[ii]<c2)x++;
		}
		if(T)ans+=2*x+1;
		else ans-=2*x+1;
		printf("%lld\n",ans);
		swap(a[l],a[r]);
		buc[L].clear();
		fup(i,L*sz,min(n-1,(L+1)*sz-1),1)buc[L].pb(a[i]);
		sort(ALL(buc[L]));
		buc[R].clear();
		fup(i,R*sz,min(n-1,(R+1)*sz-1),1)buc[R].pb(a[i]);
		sort(ALL(buc[R]));
	}
}