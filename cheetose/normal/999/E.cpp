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
#define INF 1987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

Vi v[5001], SCCadj[5001];
vector<Vi> SCC;
int num[5001], low[5001], sn[5001], snind[5001];
bool chk[5001];
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
int main() {
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
	}
	fup(i,1,n,1)
		if (num[i] == 0) {
			dfs(i);
		}
	fup(i,1,n,1)
	{
		for(int j:v[i])
			if(sn[i]!=sn[j])
			{
				SCCadj[sn[i]].pb(sn[j]);
				snind[sn[j]]++;
			}
	}
	int ans=0;
	fup(i,0,SN-1,1)if(snind[i]==0)ans++;
	if(snind[sn[s]]==0)ans--;
	printf("%d",ans);
}