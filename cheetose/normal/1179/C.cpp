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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int c1[1000001],c2[1000001];
int a[300001],b[300001];
int n,m,q;
struct A{
	int x,y,z;
}tree[2097152];
void init(int node,int S,int E)
{
	if(S==E)
	{
		tree[node].x=c1[S];
		tree[node].y=c2[S];
		tree[node].z=max(0,tree[node].x-tree[node].y);
		return;
	}
	int L=node<<1,R=L+1;
	init(L,S,(S+E)/2);
	init(R,(S+E)/2+1,E);
	int t=max(0,tree[R].y-tree[R].x+tree[R].z);
	tree[node].x=tree[L].x+tree[R].x;
	tree[node].y=tree[L].y+tree[R].y;
	tree[node].z=tree[R].z+max(0,tree[L].z-t);
}
void upd(int node,int S,int E,int k,int c,int o)
{
	if(S==E)
	{
		if(o==1)tree[node].x+=c;
		else tree[node].y+=c;
		tree[node].z=max(0,tree[node].x-tree[node].y);
		return;
	}
	int L=node<<1,R=L+1;
	if(k<=(S+E)/2)upd(L,S,(S+E)/2,k,c,o);
	else upd(R,(S+E)/2+1,E,k,c,o);
	int t=max(0,tree[R].y-tree[R].x+tree[R].z);
	tree[node].x=tree[L].x+tree[R].x;
	tree[node].y=tree[L].y+tree[R].y;
	tree[node].z=tree[R].z+max(0,tree[L].z-t);
}
int find(int node,int S,int E,int c)
{
	if(tree[node].z<=c)return -1;
	if(S==E)return S;
	int L=(node<<1),R=L+1;
	if(tree[R].z>c)return find(R,(S+E)/2+1,E,c);
	else
	{
		
		return find(L,S,(S+E)/2,max(0,tree[R].y-tree[R].x+tree[R].z)+c-tree[R].z);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	fup(i,1,n,1)
	{
		scanf("%d",a+i);
		c1[a[i]]++;
	}
	fup(i,1,m,1)
	{
		scanf("%d",b+i);
		c2[b[i]]++;
	}
	init(1,1,1000000);
	scanf("%d",&q);
	while(q--)
	{
		int o,x,y;
		scanf("%d%d%d",&o,&x,&y);
		if(o==1)
		{
			upd(1,1,1000000,a[x],-1,o);
			a[x]=y;
			upd(1,1,1000000,a[x],1,o);
		}
		else
		{
			upd(1,1,1000000,b[x],-1,o);
			b[x]=y;
			upd(1,1,1000000,b[x],1,o);
		}
		printf("%d\n",find(1,1,1000000,0));
	}
}