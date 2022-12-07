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
const ll MOD = 10003;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int a[200002],p[200002],n,ans;
void upd(int l1,int r1,int l2,int r2,int t)
{
	fup(i,l1,r1,1)
	{
		int x=t-a[i];
		if(x>=1 && x<=n && l2<=p[x] && p[x]<=r2)ans++;
	}
}
int Lparent[200002];
int Lfind(int a)
{
	if (Lparent[a] < 0)return a;
	return Lparent[a] = Lfind(Lparent[a]);
}
void Lmerge(int a, int b)
{
	a = Lfind(a), b = Lfind(b);
	if (a != b)
	{
		Lparent[b] = a;
	}
}

int Rparent[200002];
int Rfind(int a)
{
	if (Rparent[a] < 0)return a;
	return Rparent[a] = Rfind(Rparent[a]);
}
void Rmerge(int a, int b)
{
	a = Rfind(a), b = Rfind(b);
	if (a != b)
	{
		Rparent[a] = b;
	}
}
int main(){
	MEM_1(Lparent);MEM_1(Rparent);
	scanf("%d",&n);
	a[0]=a[n+1]=INF;
	fup(i,1,n,1)scanf("%d",a+i),p[a[i]]=i;
	fup(i,1,n,1)
	{
		int t=p[i];
		if(a[t-1]<a[t])Lmerge(t-1,t),Rmerge(t-1,t);
		if(a[t]>a[t+1])Lmerge(t,t+1),Rmerge(t,t+1);
		int L=Lfind(t),R=Rfind(t);
		int Ll=t-L,Rl=R-t;
		if(Ll<Rl)upd(L,t-1,t+1,R,i);
		else upd(t+1,R,L,t-1,i);
	}
	printf("%d",ans);
}