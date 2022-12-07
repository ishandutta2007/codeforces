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
#define INF 987654321987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
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
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int n,m,q;
int parent[300001];
Vi v[300001];
bool chk[300001];
int cc[300001];
int find(int a)
{
	if (parent[a] <= 0)return a;
	return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a != b)
	{
		int t1=-parent[a],t2=-parent[b];
		if(t1<t2)swap(t1,t2);
		parent[a]=-(max(t1,(t1+1)/2+(t2+1)/2+1));
		parent[b] = a;
	}
}
int dia(int x)
{
	queue<int> q;
	stack<int> st;
	cc[x]=1;
	q.push(x);
	st.push(x);
	int last=-1;
	while(!q.empty())
	{
		int y=q.front();
		q.pop();
		last=y;
		for(int next:v[y])
		{
			if(cc[next]==-1)
			{
				cc[next]=1;
				q.push(next);
				st.push(next);
			}
		}
	}
	while(!st.empty())
	{
		cc[st.top()]=-1;
		st.pop();
	}
	cc[last]=0;
	q.push(last);
	st.push(last);
	while(!q.empty())
	{
		int y=q.front();
		q.pop();
		last=y;
		for(int next:v[y])
		{
			if(cc[next]==-1)
			{
				cc[next]=cc[y]+1;
				q.push(next);
				st.push(next);
			}
		}
	}
	int res=cc[last];
	while(!st.empty())
	{
		cc[st.top()]=-1;
		st.pop();
	}
	return res;
}
int main() {
	MEM_1(cc);
	MEM_1(parent);
	scanf("%d%d%d",&n,&m,&q);
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		merge(x,y);
		v[x].pb(y);
		v[y].pb(x);
	}
	fup(i,1,n,1)
	{
		if(chk[find(i)])continue;
		chk[find(i)]=1;
		parent[find(i)]=-dia(find(i));
	}
	while(q--)
	{
		int o,x,y;
		scanf("%d",&o);
		if(o==1)
		{
			scanf("%d",&x);
			printf("%d\n",-parent[find(x)]);
		}
		else
		{
			scanf("%d%d",&x,&y);
			merge(x,y);
		}
	}
}