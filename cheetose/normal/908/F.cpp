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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

Vi v[3];
int res(Vi &V)
{
	if(V.empty())return 0;
	return V.back()-V[0];
}
int main() {
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)
	{
		int x;
		char s[2];
		scanf("%d%s",&x,s);
		if(s[0]=='R')v[0].pb(x);
		if(s[0]=='B')v[1].pb(x);
		if(s[0]=='G')v[2].pb(x);
	}
	if(v[2].empty())return !printf("%d",res(v[0])+res(v[1]));
	ll ans=0;
	fup(i,0,1,1)
		if(!v[i].empty())
		{
			if(v[i][0]<v[2][0])ans+=v[2][0]-v[i][0];
			if(v[i].back()>v[2].back())ans+=v[i].back()-v[2].back();
		}
	fup(i,0,(int)v[2].size()-2,1)
	{
		int s1=lower_bound(ALL(v[0]),v[2][i])-v[0].begin(),e1=lower_bound(ALL(v[0]),v[2][i+1])-v[0].begin()-1;
		int s2=lower_bound(ALL(v[1]),v[2][i])-v[1].begin(),e2=lower_bound(ALL(v[1]),v[2][i+1])-v[1].begin()-1;
		int m1=-1,m2=-1;
		if(e1<s1)m1=v[2][i+1]-v[2][i];
		else if(v[0][s1]>v[2][i] && v[0][e1]<v[2][i+1])
		{
			m1=max({m1,v[0][s1]-v[2][i],v[2][i+1]-v[0][e1]});
			fup(i,s1,e1-1,1)m1=max(m1,v[0][i+1]-v[0][i]);
		}
		else m1=v[2][i+1]-v[2][i];
		if(e2<s2)m2=v[2][i+1]-v[2][i];
		else if(v[1][s2]>v[2][i] && v[1][e2]<v[2][i+1])
		{
			m2=max({m2,v[1][s2]-v[2][i],v[2][i+1]-v[1][e2]});
			fup(i,s2,e2-1,1)m2=max(m2,v[1][i+1]-v[1][i]);
		}
		else m2=v[2][i+1]-v[2][i];
		ans+=min(2LL*(v[2][i+1]-v[2][i]),1LL*3*(v[2][i+1]-v[2][i])-m1-m2);
	}
	printf("%lld",ans);
}