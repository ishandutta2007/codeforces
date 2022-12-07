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
#define INF 98765432
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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={-1,-2,1,-2,2,-1,2,1},ddy[]={-2,-1,-2,1,-1,2,1,2};

int n,m;
int a[300001],b[300001],c[300001],cnt[300001],tree2[300001];
bool chk[300001];
void upd(int i)
{
	while (i <= n)
	{
		tree2[i]++;
		i += (i&-i);
	}
}
int sum(int i)
{
	int c = 0;
	while (i > 0)
	{
		c += tree2[i];
		i -= (i&-i);
	}
	return c;
}
Vi tree[1048576];
Vi v[300001];
Vi merge(const Vi& v1, const Vi& v2)
{
	Vi v;
	int i = 0, j = 0, n = v1.size(), m = v2.size();
	while (1)
	{
		if (i == n && j == m)break;
		if (i == n) v.push_back(v2[j++]);
		else if (j == m)v.push_back(v1[i++]);
		else if (v1[i] > v2[j]) v.push_back(v2[j++]);
		else v.push_back(v1[i++]);
	}
	return v;
}
void init(int node, int S, int E)
{
	if (S == E)
	{
		tree[node].push_back(b[S]);
		return;
	}
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
	tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}
int find(int node, int S, int E, int i,int j, int k)
{
	if (i > E || j < S) return 0;
	if (S == E)
	{
		if (b[S] > k)return 1;
		else return 0;
	}
	if (j >= E && i <= S) return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
	return find(2 * node, S, (S + E) / 2, i, j, k) + find(2 * node + 1, (S + E) / 2 + 1, E, i, j, k);
}
int main(){
	scanf("%d%d",&n,&m);
	int tot=0;
	fup(i,1,m,1)
	{
		scanf("%d",a+i);
		v[a[i]].pb(i);
		if(!chk[a[i]])
		{
			chk[a[i]]=1;
			cnt[a[i]]=tot-sum(a[i]);
			tot++;
			upd(a[i]);
		}
	}
	fup(i,1,n,1)c[i]=m+1;
	fdn(i,m,1,1)
	{
		b[i]=c[a[i]];
		c[a[i]]=i;
	}
	init(1,1,m);
	fup(i,1,n,1)
	{
		if(v[i].empty())
		{
			printf("%d %d\n",i,i+tot-sum(i));
		}
		else
		{
			Pi res=mp(1,i+cnt[i]);
			fup(j,1,(int)v[i].size()-1,1)
			{
				int l=v[i][j-1],r=v[i][j];
				res.Y=max(res.Y,1+find(1,1,m,l+1,r-1,r-1));
			}
			res.Y=max(res.Y,1+find(1,1,m,v[i].back()+1,m,m));
			printf("%d %d\n",res.X,res.Y);
		}
	}
}