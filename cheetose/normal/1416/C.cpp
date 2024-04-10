#include <bits/stdc++.h>
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
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<db> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

struct node {
	Vi v;
	int child[2];
	node()
	{
		MEM_1(child);
	}
};
vector<node> trie;
int init()
{
	node x;
	trie.push_back(x);
	return (int)trie.size() - 1;
}
void add(int n, int x, int i)
{
	if (i == -1)
	{
		return;
	}
	int c = x&(1<<i);
	if(c>0)c=1;
	trie[n].v.pb(c);
	if (trie[n].child[c] == -1)
	{
		int next = init();
		trie[n].child[c] = next;
	}
	add(trie[n].child[c], x, i - 1);
}
Pll res[31];
void dfs(int n,int i){
	if(i==-1)return;
	int c1=0,c2=0;
	for(int x:trie[n].v){
		if(x==1){
			c1++;
			res[i].Y+=c2;
		}else{
			c2++;
			res[i].X+=c1;
		}
	}
	fup(c,0,1,1){
		if(trie[n].child[c]!=-1){
			dfs(trie[n].child[c],i-1);
		}
	}
}
int main() {
	init();
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1){
		int x;
		scanf("%d",&x);
		add(0,x,30);
	}
	dfs(0,30);
	int ans=0;
	ll rr=0;
	fup(i,0,30,1){
		if(res[i].X>res[i].Y)ans^=(1<<i);
		rr+=min(res[i].X,res[i].Y);
	}
	printf("%lld %d\n",rr,ans);
}