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

struct Edge{
    int to, cnt;
    Edge *dual;
    Edge(): Edge(-1, 0){}
    Edge(int to1, int cnt1): to(to1), cnt(cnt1), dual(nullptr){}
};

bool cc[201],chk[201][201];
vector<Edge*> v[201];
int deg[201];
Vi ans;
VPi res;
void Euler(int N){
	cc[N]=1;
    for(Edge *e: v[N]){
        if(e->cnt > 0){
            e->cnt--;
            e->dual->cnt--;
            Euler(e->to);
        }
    }
    ans.pb(N);
}
void go(int x)
{
	ans.clear();
	Euler(x);
	int N=ans.size();
	fup(i,0,N-2,1)
	{
		if(chk[ans[i]][ans[i+1]])
		{
			res.pb(mp(ans[i],ans[i+1]));
			chk[ans[i]][ans[i+1]]=chk[ans[i+1]][ans[i]]=0;
		}
	}
}
void add(int x,int y)
{
	Edge *e1 = new Edge(y, 1), *e2 = new Edge(x, 1);
	e1->dual=e2,e2->dual=e1;
	v[x].pb(e1);
	v[y].pb(e2);
}
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		MEM0(chk);
		MEM0(deg);
		MEM0(cc);
		res.clear();
		int n,m;
		scanf("%d%d",&n,&m);
		fup(i,1,n,1)v[i].clear();
		fup(i,1,m,1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			chk[x][y]=chk[y][x]=1;
			deg[x]++,deg[y]++;
		}
		Vi vv;
		fup(i,1,n,1)if(deg[i]&1)vv.pb(i);
		fup(i,0,(int)vv.size()-1,2)
		{
			add(vv[i],vv[i+1]);
		}
		fup(i,1,n,1)if(!cc[i])go(i);
		printf("%d\n",n-vv.size());
		for(Pi p:res)printf("%d %d\n",p.X,p.Y);
	}
}