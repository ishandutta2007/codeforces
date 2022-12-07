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
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

struct node {
	int idx,cnt;
	int child[2];
	node()
	{
		idx = -1,cnt=0;
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
void add(int n, int s, int i,int idx_)
{
	trie[n].cnt++;
	if(i==-1)
	{
		trie[n].idx=idx_;
		return;
	}
	int c = s&(1<<i);
	if(c)c=1;
	if (trie[n].child[c] == -1)
	{
		int next = init();
		trie[n].child[c] = next;
	}
	add(trie[n].child[c], s, i - 1, idx_);
}
void remove(int n,int s,int i)
{
	trie[n].cnt--;
	if(i==-1)return;
	int c=s&(1<<i);
	if(c)c=1;
	remove(trie[n].child[c],s,i-1);
}
int query(int n,int s,int i)
{
	if(i==-1)return trie[n].idx;
	int c=s&(1<<i);
	if(c)c=1;
	if(trie[n].child[c]!=-1 && trie[trie[n].child[c]].cnt>0)return query(trie[n].child[c],s,i-1);
	else return query(trie[n].child[1-c],s,i-1);
}
int a[200000];
int parent[200000];
int find(int a)
{
	if (parent[a] < 0)return a;
	return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a != b)
	{
		parent[a] += parent[b];
		parent[b] = a;
	}
}
int main() {
	MEM_1(parent);
	int n;
	scanf("%d", &n);
	init();
	fup(i,0,n-1,1)scanf("%d",a+i);
	sort(a,a+n);
	n=unique(a,a+n)-a;
	fup(i,0,n-1,1)add(0,a[i],29,i);
	ll ans=0;
	while(1)
	{
		map<int,Vi> M;
		fup(i,0,n-1,1)M[find(i)].pb(i);
		if(M.size()==1)break;
		
		for(auto it=M.begin();it!=M.end();it++)
		{
			Vi &v=it->Y;
			for(int x:v)remove(0,a[x],29);
			int mn=1<<30,what=-1;
			for(int x:v)
			{
				int i=query(0,a[x],29);
				int res=a[i]^a[x];
				if(res<mn)
					what=i,mn=res;
			}
			if(find(what)!=find(it->X))
			{
				ans+=mn;
				merge(what,it->X);
			}
			for(int x:v)add(0,a[x],29,x);
		}
	}
	printf("%lld",ans);
}