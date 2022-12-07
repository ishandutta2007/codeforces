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
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int a[1000001],b[1000001],to[1000001],x,n;
struct NODE{
    NODE(): v(0), left(0), right(0) {}
    int v;
    int left, right;
} Tree[1000001*30];
int p;
int newNODE()
{
	p++;
	Tree[p]=NODE();
	return p;
}
int insertNODE(NODE N)
{
	p++;
	Tree[p]=N;
	return p;
}
int make_tree(int now, int s, int e, int y, int v)
{
    if (y < s || e < y) return now;
	int ret=insertNODE(Tree[now]);
    if (s == e){
        Tree[ret].v = Tree[now].v + v;
        return ret;
    }
    int m = (s+e) >> 1;
    Tree[ret].left = make_tree(Tree[now].left, s, m, y, v);
    Tree[ret].right = make_tree(Tree[now].right, m+1, e, y, v);
    Tree[ret].v = (Tree[ret].left ? Tree[Tree[ret].left].v : 0) + (Tree[ret].right ? Tree[Tree[ret].right].v : 0);
    return ret;
}

int init(int s,int e)
{
	int t=newNODE();
	if(s!=e)
	{
		Tree[t].left=init(s,(s+e)/2);
		Tree[t].right=init((s+e)/2+1,e);
	}
	return t;
}

int find(int now, int S, int E, int i, int j)
{
	if (i > E || j < S)return 0;
	if (i <= S && j >= E)return Tree[now].v;
	int ret=0;
	if(Tree[now].left)ret+=find(Tree[now].left,S,(S+E)/2,i,j);
	if(Tree[now].right)ret+=find(Tree[now].right,(S+E)/2+1,E,i,j);
	return ret;
}
inline int f(int z)
{
	return (z-1+x)%n + 1;
}
int tree[1000001];
int main() {
	scanf("%d",&n);
	fup(i,1,n,1)
	{
		int xx;
		scanf("%d",&xx);
		a[xx]=i;
	}
	fup(i,1,n,1)
	{
		int xx;
		scanf("%d",&xx);
		b[xx]=i;
	}
	fup(i,1,n,1)to[a[i]]=b[i];
	tree[0]=init(1,n);
	fup(i,1,n,1)
		tree[i] = make_tree(tree[i-1], 1, n, to[i], 1);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int aa,bb,cc,dd;
		scanf("%d%d%d%d",&aa,&bb,&cc,&dd);
		int l1=f(aa),r1=f(bb),l2=f(cc),r2=f(dd);
		if(l1>r1)swap(l1,r1);
		if(l2>r2)swap(l2,r2);
		x=find(tree[r1],1,n,l2,r2)-find(tree[l1-1],1,n,l2,r2);
		printf("%d\n",x);
		x++;
	}
}