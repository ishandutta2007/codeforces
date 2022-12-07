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
typedef vector<ld> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={-1,-2,1,-2,2,-1,2,1},ddy[]={-2,-1,-2,1,-1,2,1,2};

struct FenwickTree{
	int n,sz;
	Vi tree1,tree2;
	
	FenwickTree(){}
	FenwickTree(int N){
		sz=0;
		n=N;
		tree1.resize(N+1);
		tree2.resize(N+1);
	}
	
	void upd1(int i, int k)
	{
		while (i <= n)
		{
			tree1[i] += k;
			i += (i&-i);
		}
	}
	int sum1(int i)
	{
		int c = 0;
		while (i > 0)
		{
			c += tree1[i];
			i -= (i&-i);
		}
		return c;
	}
	
	void upd2(int i, int k)
	{
		while (i <= n)
		{
			tree2[i] += k;
			i += (i&-i);
		}
	}
	int sum2(int i)
	{
		ll c = 0;
		while (i > 0)
		{
			c += tree2[i];
			i -= (i&-i);
		}
		return c;
	}
};
struct A{
	int x1,y1,x2,y2;
}a[100000];
VPi v[400000];
int main(){
	int n;
	scanf("%d",&n);
	Vi vv;
	fup(i,0,n-1,1)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		vv.pb(x1);vv.pb(y1);vv.pb(x2);vv.pb(y2);
		a[i].x1=x1,a[i].x2=x2,a[i].y1=y1,a[i].y2=y2;
	}
	sort(ALL(vv));
	vv.resize(unique(ALL(vv))-vv.begin());
	fup(i,0,n-1,1)
	{
		a[i].x1=lower_bound(ALL(vv),a[i].x1)-vv.begin()+1;
		a[i].y1=lower_bound(ALL(vv),a[i].y1)-vv.begin()+1;
		a[i].x2=lower_bound(ALL(vv),a[i].x2)-vv.begin()+1;
		a[i].y2=lower_bound(ALL(vv),a[i].y2)-vv.begin()+1;
	}
	int N=vv.size();
	sort(a,a+n,[&](A a1,A a2){
		return a1.x1<a2.x1;
	});
	FenwickTree t1(N+2),t2(N+2);
	int j=0;
	fup(i,0,n-1,1)
	{
		int x1=a[i].x1,y1=a[i].y1,x2=a[i].x2,y2=a[i].y2;
		while(j<N && j<x1)
		{
			for(Pi p:v[j])
			{
				t1.sz--;
				t2.sz++;
				t1.upd1(p.X,-1);
				t1.upd2(p.Y,-1);
				t2.upd1(p.X,1);
				t2.upd2(p.Y,1);
			}
			j++;
		}
		if(t1.sz-t1.sum1(y2)>0 || t1.sum2(x2-1)>0)return !printf("NO");
		if(t2.sum1(y2)!=t2.sum2(x2-1))return !printf("NO");
		t1.sz++;
		v[y1].pb(mp(x2,y2));
		t1.upd1(x2,1);
		t1.upd2(y2,1);
	}
	puts("YES");
}