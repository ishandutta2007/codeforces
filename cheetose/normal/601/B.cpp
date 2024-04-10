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
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

ll a[100001];
Pll b[100001];
int L[100001],R[100001];
int n,q;
void init(int l,int r)
{
	fup(i,l,r,1)
		L[i]=i-1,R[i]=i+1;
}
void del(int x)
{
	int l=L[x],r=R[x];
	L[r]=l,R[l]=r;
}
ll query(int l,int r)
{
	ll res=0;
	init(l,r);
	fup(i,1,n-1,1)
	{
		if(l<=b[i].Y && b[i].Y<=r)
		{
			int x=b[i].Y;
			res+=b[i].X*(R[x]-x)*(x-L[x]);
			del(x);
		}
	}
	return res;
}
int main() {
	scanf("%d%d",&n,&q);
	fup(i,1,n,1)scanf("%lld",a+i);
	fup(i,1,n-1,1)
	{
		b[i].X=abs(a[i+1]-a[i]);
		b[i].Y=i;
	}
	sort(b+1,b+n);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		r--;
		printf("%lld\n",query(l,r));
	}
}