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
const ll MOD = 16769023;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int a[300000],ans[300000];
int main(){
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)scanf("%d",a+i),a[i+n]=a[i+n+n]=a[i];
	int mn=INF,mx=0;
	fup(i,0,n-1,1)
		mn=min(mn,a[i]),mx=max(mx,a[i]);
	if(mx<=2*mn)
	{
		fup(i,0,n-1,1)printf("-1 ");
		return 0;
	}
	Vi v;
	v.pb(2*n);
	fdn(i,2*n-1,0,1)
	{
		int l=0,r=v.size()-1;
		while(l<=r)
		{
			int k=(l+r)>>1;
			if(a[v[k]]*2<a[i])l=k+1;
			else r=k-1;
		}
		ans[i]=r==-1?INF:v[r]-i;
		while(!v.empty() && a[i]<=a[v.back()])v.pop_back();
		v.pb(i);
	}
	fup(tt,1,3,1)
		fdn(i,n-1,0,1)ans[i]=min(ans[i],ans[(i+1)%n]+1);
	fup(i,0,n-1,1)printf("%d ",ans[i]);
}