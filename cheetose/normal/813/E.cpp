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

int n,k;
Vi v[100001];
int a[100001],b[100001];
struct NODE{
    NODE(): v(0), left(0), right(0) {}
    int v;
    NODE *left, *right;
} *Tree[100001];

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
int main() {
	scanf("%d%d",&n,&k);
	fup(i,1,n,1)
	{
		scanf("%d",a+i);
		v[a[i]].pb(i);
	}
	fup(i,1,100000,1)
	{
		fup(j,0,(int)v[i].size()-1,1)
		{
			if(j<k)b[v[i][j]]=0;
			else b[v[i][j]]=v[i][j-k];
		}
	}
	Tree[0]=new NODE;
	init(Tree[0],0,100000);
	fup(i,1,n,1)
		Tree[i] = make_tree(Tree[i-1], 0, 100000, b[i], 1);
	int ans=0;
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		l=(l+ans)%n+1,r=(r+ans)%n+1;
		if(l>r)swap(l,r);
		ans=find(Tree[r],0,100000,0,l-1)-find(Tree[l-1],0,100000,0,l-1);
		printf("%d\n",ans);
	}
}