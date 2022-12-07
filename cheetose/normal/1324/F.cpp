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

int col[200005];
Vi v[200005];
int mx[200005],ans[200005];
void dfs(int N,int p=-1)
{
	if(p!=-1 && v[N].size()==1)
	{
		mx[N]=col[N];
		return;
	}
	mx[N]=col[N];
	for(int next:v[N])
	{
		if(next==p)continue;
		dfs(next,N);
		if(mx[next]>0)mx[N]+=mx[next];
	}
}
void dfs2(int N,int p=-1)
{
	sort(ALL(v[N]),[&](int a,int b){
		if(a==p)return false;
		if(b==p)return true;
		return mx[a]>mx[b];
	});
	if(p!=-1)v[N].pop_back();
	for(int next:v[N])dfs2(next,N);
}
void dfs3(int N,int c){
	ans[N]=mx[N]+c;
	Vi vv;
	for(int next:v[N])vv.pb(mx[next]);
	int sum=col[N]+c;
	for(int x:vv)if(x>0)sum+=x;
	fup(i,0,(int)vv.size()-1,1)
	{
		int next=v[N][i];
		if(mx[next]>0)sum-=mx[next];
		dfs3(next,max(0,sum));
		if(mx[next]>0)sum+=mx[next];
	}
}
int main(){
	int n;
	scanf("%d",&n);
	fup(i,1,n,1){
		scanf("%d",col+i);
		if(col[i]==0)col[i]=-1;
	}
	fup(i,2,n,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1);dfs2(1);dfs3(1,0);
	fup(i,1,n,1)printf("%d ",ans[i]);
}