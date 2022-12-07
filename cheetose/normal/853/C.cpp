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
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
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
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

struct NODE{
    NODE(): v(0), left(0), right(0) {}
    int v;
    NODE *left, *right;
} *Tree[200001];

NODE *make_tree(NODE *now, int s, int e, int y, int v)
{
    if (y < s || e < y) return now;
    NODE *ret = new NODE();
    if (s == e){
        ret->v = now->v + v;
        return ret;
    }
    int m = (s+e) >> 1;
    ret->left = make_tree(now->left, s, m, y, v);
    ret->right = make_tree(now->right, m+1, e, y, v);
    ret->v = (ret->left ? ret->left->v : 0) + (ret->right ? ret->right->v : 0);
    return ret;
}

void init(NODE *now,int s,int e)
{
	if(s==e)return;
	now->left=new NODE;
	now->right=new NODE;
	init(now->left,s,(s+e)/2);
	init(now->right,(s+e)/2+1,e);
}

int find(NODE *now, int S, int E, int i, int j)
{
	if (i > E || j < S)return 0;
	if (i <= S && j >= E)return now->v;
	int ret=0;
	if(now->left)ret+=find(now->left,S,(S+E)/2,i,j);
	if(now->right)ret+=find(now->right,(S+E)/2+1,E,i,j);
	return ret;
}

int a[200001];
int n,q;
inline ll nC2(int x){return 1LL*x*(x-1)/2;}
inline ll cnt(int x1,int x2,int y1,int y2){
	if(x2>n || y2>n)return 0;
	if(x1>x2 || y1>y2)return 0;
	return nC2(find(Tree[x2],1,n,y1,y2)-find(Tree[x1-1],1,n,y1,y2));
}
int main() {
	scanf("%d%d",&n,&q);
	fup(i,1,n,1)scanf("%d",a+i);
	Tree[0]=new NODE;
	init(Tree[0],1,n);
	fup(i,1,n,1)
	{
		Tree[i] = make_tree(Tree[i-1], 1, n, a[i], 1);
	}
	while(q--)
	{
		ll ans=nC2(n);
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		ans-=nC2(x1-1)+nC2(n-x2)+nC2(y1-1)+nC2(n-y2);
		ans+=cnt(1,x1-1,1,y1-1)+cnt(1,x1-1,y2+1,n)+cnt(x2+1,n,1,y1-1)+cnt(x2+1,n,y2+1,n);
		printf("%lld\n",ans);
	}
}