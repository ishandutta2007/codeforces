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

inline int neg(int x){return 2*x;}
inline int pos(int x){return 2*x-1;}
Vi v[4000004];
vector<Vi> SCC;
int num[4000004], low[4000004], sn[4000004],ans[4000004];
bool chk[4000004];
stack<int> st;
int cnt, SN;
void dfs(int n)
{
	chk[n] = 1;
	st.push(n);
	num[n] = ++cnt;
	low[n] = cnt;
	for (int next : v[n])
	{
		if (num[next] == 0)
		{
			dfs(next);
			low[n] = min(low[n], low[next]);
		}
		else if (chk[next])
			low[n] = min(low[n], num[next]);
	}
	if (num[n] == low[n])
	{
		Vi scc;
		while (!st.empty())
		{
			int x = st.top();
			st.pop();
			sn[x] = SN;
			chk[x] = 0;
			scc.push_back(x);
			if (n == x)
				break;
		}
		SCC.push_back(scc);
		SN++;
	}
}
void solve(){
	SCC.clear();
	while(!st.empty())st.pop();
	int n,m;
	scanf("%d%d",&n,&m);
	cnt=0,SN=0;
	fup(i,1,4*n,1){
		v[i].clear();
		chk[i]=0;
		num[i]=low[i]=sn[i]=0;
		ans[i]=-1;
	}
	fup(i,1,n,1){
		v[neg(i)].pb(pos(i+n));
		v[neg(i+n)].pb(pos(i));
	}
	fup(i,1,m,1){
		int x,y;
		scanf("%d%d",&x,&y);
		v[pos(x)].pb(neg(y+n));
		v[pos(y+n)].pb(neg(x));
	}
	fup(i,1,4*n,1)if(!num[i])dfs(i);
	if(SN==2){
		puts("No");
		return;
	}
	fup(i,1,4*n,1)chk[i]=0;
	Vi ans1,ans2;
	for(int x:SCC[0]){
		chk[(x+1)/2]=1;
		if(x<=2*n && x&1)ans1.pb((x+1)/2);
	}
	fup(i,1,SN-1,1){
		bool ok=0;
		for(int x:SCC[i]){
			if(chk[(x+1)/2]){
				break;
			}
			if(x>2*n && x&1){
				ans2.pb((x-2*n+1)/2);
				ok=1;
			}
		}
		if(ok){
			for(int x:SCC[i]){
				chk[(x+1)/2]=1;
			}
		}
	}
	puts("Yes");
	printf("%d %d\n",ans1.size(),ans2.size());
	for(int x:ans1)printf("%d ",x);
		puts("");
	for(int x:ans2)printf("%d ",x);
		puts("");
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}
}