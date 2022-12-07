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

int d[151][3];
int n,x,y,z;
int go(int N,int c)
{
	if(N<=0)return 0;
	int &ret=d[N][c];
	if(~ret)return ret;
	Vi v;
	v.pb(go(N-x,0));
	if(c!=1)v.pb(go(N-y,1));
	if(c!=2)v.pb(go(N-z,2));
	sort(ALL(v));
	v.resize(unique(ALL(v))-v.begin());
	fup(i,0,(int)v.size()-1,1)if(v[i]!=i)return ret=i;
	return ret=(int)v.size();
}
ll a[300000];
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--){
		MEM_1(d);
		scanf("%d%d%d%d",&n,&x,&y,&z);
		int p=-1;
		Viii v;
		fup(i,0,150,1)v.pb(iii(go(i,0),go(i,1),go(i,2)));
		fup(i,1,20,1)
		{
			bool OK=1;
			fup(k,80,(int)v.size()-1,1)if(v[k]!=v[k-i])OK=0;
			if(OK)
			{
				p=i;
				break;
			}
		}
		int t=0;
		fdn(i,120,0,1)
			if(v[i]!=v[i+p])
			{
				t=i;
				break;
			}
		fup(i,0,n-1,1)
		{
			scanf("%lld",a+i);
			if(a[i]>t+5*p)
			{
				a[i]-=t;
				a[i]%=p;
				a[i]+=t+5*p;
			}
		}
		int ans=0,res=0;
		fup(i,0,n-1,1)res^=go(a[i],0);
		fup(i,0,n-1,1)
		{
			res^=go(a[i],0);
			res^=go(a[i]-x,0);
			if(!res)ans++;
			res^=go(a[i]-x,0);
			res^=go(a[i]-y,1);
			if(!res)ans++;
			res^=go(a[i]-y,1);
			res^=go(a[i]-z,2);
			if(!res)ans++;
			res^=go(a[i]-z,2);
			res^=go(a[i],0);
		}
		printf("%d\n",ans);
	}
}