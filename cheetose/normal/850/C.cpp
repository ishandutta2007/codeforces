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
#define INF 1987654321
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

map<int,int> M;
int go(int k)
{
	if(k==0)return 0;
	if(M.find(k)!=M.end())return M[k];
	Vi v;
	fup(i,1,29,1)
	{
		if(k>>(i-1))
		{
			int nk=(k&((1<<(i-1))-1))|(k>>i);
			v.pb(go(nk));
		}
		else break;
	}
	sort(ALL(v));
	v.resize(unique(ALL(v))-v.begin());
	fup(i,0,(int)v.size()-1,1)
		if(v[i]!=i)return M[k]=i;
	return M[k]=v.size();
}
int n;
map<int,Vi> m;
int main() {
	scanf("%d",&n);
	fup(i,1,n,1)
	{
		int x;
		scanf("%d",&x);
		for(int j=2;j*j<=x;j++)
		{
			if(x%j==0)
			{
				int c=0;
				while(x%j==0)
				{
					c++;
					x/=j;
				}
				m[j].pb(c);
			}
		}
		if(x>1)m[x].pb(1);
	}
	int res=0;
	for(auto it=m.begin();it!=m.end();it++)
	{
		auto &v=it->Y;
		int t=0;
		for(auto y:v)t|=(1<<y);
		res^=go(t>>1);
	}
	puts(res?"Mojtaba":"Arpa");
}