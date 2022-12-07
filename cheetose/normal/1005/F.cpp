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
#define INF 1987654321987654321
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
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int n,m,k;
int x[200000],y[200000];
Vi v[200001],vv[200001];
int d[200001],t[200001];
vector<string> ans;
int main() {
	MEM_1(d);
	scanf("%d%d%d",&n,&m,&k);
	fup(i,0,m-1,1)
	{
		scanf("%d%d",x+i,y+i);
		v[x[i]].pb(y[i]);
		v[y[i]].pb(x[i]);
	}
	queue<int> q;
	q.push(1);
	d[1]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int next:v[x])
		{
			if(d[next]==-1)
			{
				d[next]=d[x]+1;
				q.push(next);
			}
		}
	}
	fup(i,0,m-1,1)
	{
		if(d[x[i]]+1==d[y[i]])vv[y[i]].pb(i);
		if(d[y[i]]+1==d[x[i]])vv[x[i]].pb(i);
	}
	fup(i,0,k-1,1)
	{
		string s(m,'0');
		fup(j,2,n,1)s[vv[j][t[j]]]='1';
		ans.pb(s);
		bool ok=0;
		fup(j,2,n,1)
		{
			if(t[j]+1<vv[j].size())
			{
				ok=1;
				t[j]++;
				break;
			}
			else t[j]=0;
		}
		if(!ok)break;
	}
	printf("%d\n",ans.size());
	for(auto &s:ans)printf("%s\n",s.c_str());
}