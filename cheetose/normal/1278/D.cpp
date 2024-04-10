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
const int MOD = 1000000009;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={-1,-2,1,-2,2,-1,2,1},ddy[]={-2,-1,-2,1,-1,2,1,2};

int tree[1000005];
int parent[500005];
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
int n;
void upd(int i, int k)
{
	while (i <= 2*n)
	{
		tree[i] += k;
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
Pi p[500005];
Viii v;
int main(){
	MEM_1(parent);
	scanf("%d",&n);
	fup(i,1,n,1)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		v.pb(iii(l,1,i));
		v.pb(iii(r,-1,i));
		p[i]=mp(l,r);
	}
	sort(ALL(v));
	ll ans=0;
	for(auto &I:v)
	{
		int x,c,i;
		tie(x,c,i)=I;
		if(c==-1)
		{
			upd(x,-1);
		}
		else
		{
			ans+=sum(p[i].Y-1);
			upd(p[i].Y,1);
		}
	}
	if(ans!=n-1)return !printf("NO");
	priority_queue<Pi,VPi,greater<Pi> > q;
	stack<Pi> st;
	for(auto &I:v)
	{
		int x,c,i;
		tie(x,c,i)=I;
		if(c==-1)
		{
			q.pop();
		}
		else
		{
			while(!q.empty() && q.top().X<p[i].Y)
			{
				st.push(q.top());
				merge(i,q.top().Y);
				q.pop();
			}
			while(!st.empty())
			{
				q.push(st.top());
				st.pop();
			}
			q.push(mp(p[i].Y,i));
		}
	}
	int com=0;
	fup(i,1,n,1)if(find(i)==i)com++;
	puts(com==1?"YES":"NO");
}