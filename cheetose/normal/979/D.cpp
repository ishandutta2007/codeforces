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
#define INF 1987654321
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

Vi di[100001];

bool chk[100001];

struct FenwickTree{
	int n,tt;
	Vi tree;
	
	void init(int N){
		tt=N;
		n=100000/N+2;
		tree.resize(n);
	}
	
	void upd(int i)
	{
		while (i < n)
		{
			tree[i]++;
			i += (i&-i);
		}
	}
	int sum(int i)
	{
		int c = 0;
		while (i > 0)
		{
			c += tree[i];
			i -= (i&-i);
		}
		return c;
	}
	int z(int x)
	{
		return x/tt;
	}
	int query(int L,int R,int d,int x)
	{
		if(L==R)
		{
			if(chk[L] && L%tt==0)return L;
			return -1;
		}
		int t=1<<d;
		if(L+t>R)return query(L,R,d-1,x);
		if(x&t)
		{
			if(sum(z(L+t-1))-sum(z(L-1)))return query(L,L+t-1,d-1,x);
			return query(L+t,R,d-1,x);
		}
		else
		{
			if(sum(z(R))-sum(z(L+t-1)))return query(L+t,R,d-1,x);
			return query(L,L+t-1,d-1,x);
		}
	}
}T[100001];
int main() {
	fup(i,1,100000,1)T[i].init(i);
	fup(i,1,100000,1)
		fup(j,i,100000,i)di[j].pb(i);
	int q,o,x,k,s;
	scanf("%d",&q);
	while(q--)
	{
		int o;
		scanf("%d",&o);
		if(o==1)
		{
			scanf("%d",&x);
			if(chk[x])continue;
			chk[x]=1;
			for(int y:di[x])T[y].upd(x/y);
		}
		else
		{
			scanf("%d%d%d",&x,&k,&s);
			if(x%k || s-x<=0)puts("-1");
			else
			{
				printf("%d\n",T[k].query(0,s-x,16,x));
			}
		}
	}
}