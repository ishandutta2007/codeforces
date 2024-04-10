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
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

char s[150001],t[150001];
Vi vs[27],vt[27];
VPi ans;
int main() {
	int n;
	scanf("%d%s%s",&n,s,t);
	fup(i,0,n-1,1)
	{
		if(s[i]!='?')vs[s[i]-'a'].pb(i+1);
		else vs[26].pb(i+1);
		if(t[i]!='?')vt[t[i]-'a'].pb(i+1);
		else vt[26].pb(i+1);
	}
	fup(i,0,25,1)
	{
		while(!vs[i].empty() && !vt[i].empty())
		{
			ans.pb(mp(vs[i].back(),vt[i].back()));
			vs[i].pop_back();
			vt[i].pop_back();
		}
	}
	fup(i,0,25,1)
	{
		while(!vs[26].empty() && !vt[i].empty())
		{
			ans.pb(mp(vs[26].back(),vt[i].back()));
			vs[26].pop_back();
			vt[i].pop_back();
		}
		while(!vt[26].empty() && !vs[i].empty())
		{
			ans.pb(mp(vs[i].back(),vt[26].back()));
			vt[26].pop_back();
			vs[i].pop_back();
		}
	}
	while(!vs[26].empty() && !vt[26].empty())
	{
		ans.pb(mp(vs[26].back(),vt[26].back()));
		vs[26].pop_back();
		vt[26].pop_back();
	}
	printf("%d\n",ans.size());
	for(Pi p:ans)printf("%d %d\n",p.X,p.Y);
}