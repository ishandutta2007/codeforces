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
#define INF 987654321987654231
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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

struct node {
	int child[26];
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
Vi v[2][800002];
bool chk[2][100001];
void add(int n, string &s, int i, int d,int cc,int ii)
{
	v[cc][n].pb(ii);
	if (i == s.length())
		return;
	int c = s[i] - 'a';
	if (trie[n].child[c] == -1)
	{
		int next = init();
		trie[n].child[c] = next;
	}
	add(trie[n].child[c], s, i + 1, d+1,cc,ii);
}
char temp[800001];
VPi res;
ll ans;
void find(int n,int d)
{
	fup(i,0,25,1)
		if(trie[n].child[i]!=-1)find(trie[n].child[i],d+1);
	bool ok=1;
	while(ok)
	{
		ok=0;
		while(!v[0][n].empty() && chk[0][v[0][n].back()])v[0][n].pop_back();
		while(!v[1][n].empty() && chk[1][v[1][n].back()])v[1][n].pop_back();
		if(v[0][n].size() && v[1][n].size())
		{
			ok=1;
			int x=v[0][n].back(),y=v[1][n].back();
			ans+=d;
			res.pb(mp(x,y));
			chk[0][x]=chk[1][y]=1;
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	init();
	fup(i, 0, n - 1, 1)
	{
		scanf("%s", temp);
		string s = temp;
		add(0, s, 0,0,0,i+1);
	}
	fup(i, 0, n - 1, 1)
	{
		scanf("%s", temp);
		string s = temp;
		add(0, s, 0,0,1,i+1);
	}
	find(0,0);
	printf("%lld\n",ans);
	for(Pi p:res)printf("%d %d\n",p.X,p.Y);
}