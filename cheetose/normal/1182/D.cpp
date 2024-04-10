#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321987654321
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

Vi v[100001];
int t[100005],d[100005],p[100005];
int bfs(int N)
{
	MEM_1(d);
	queue<int> q;
	q.push(N);
	d[N]=0;
	p[N]=-1;
	int last;
	while(!q.empty())
	{
		int x=q.front();
		last=x;
		q.pop();
		for(int next:v[x])
		{
			if(d[next]==-1)
			{
				d[next]=d[x]+1;
				p[next]=x;
				q.push(next);
			}
		}
	}
	return last;
}
bool g(int N)
{
	MEM_1(t);
	MEM_1(d);
	d[N]=0;
	queue<int> q;
	q.push(N);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(t[d[x]]==-1)t[d[x]]=v[x].size();
		else if(t[d[x]]!=v[x].size())return 0;
		for(int next:v[x])
		{
			if(d[next]==-1)
			{
				d[next]=d[x]+1;
				q.push(next);
			}
		}
	}
	return 1;
}
int main(){
	int n;
	scanf("%d",&n);
	if(n<=2)return !printf("1");
	fup(i,1,n-1,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	bool ok=1;
	fup(i,1,n,1)if(v[i].size()>2)ok=0;
	if(ok)
	{
		fup(i,1,n,1)if(v[i].size()==1)return !printf("%d",i);
	}
	int S=bfs(1);
	int E=bfs(S);
	int M;
	for(M=E;d[M]!=d[E]/2;M=p[M]);
	if(g(S))return !printf("%d",S);
	if(g(M))return !printf("%d",M);
	if(g(E))return !printf("%d",E);
	MEM_1(d);
	queue<int> q;
	q.push(M);
	d[M]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int next:v[x])
		{
			if(v[next].size()<=2 && d[next]==-1)
			{
				d[next]=d[x]+1;
				q.push(next);
			}
		}
	}
	int t=-1;
	fup(i,1,n,1)
	{
		if(v[i].size()==1 && d[i]!=-1 && (t==-1 || d[t]>d[i]))t=i;
	}
	if(g(t))return !printf("%d",t);
	puts("-1");
}