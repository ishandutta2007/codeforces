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
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

Vi v[100001];
Vi vv[100001];
ll g[100001];
int main() {
	fup(i,1,100000,1)
		fup(j,i+i,100000,i)vv[j].pb(i);
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,0,m-1,1)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>b)swap(a,b);
		int t=min(a+n-b,b-a);
		if(a+n-b==t)v[t].pb(b);
		if(b-a==t)v[t].pb(a);
	}
	
	fup(i,1,n-1,1)
	{
		sort(ALL(v[i]));
		if(v[i].empty())continue;
		if(v[i].size()==1)return !printf("No");
		else
		{
			Vi V;
			int N=v[i].size();
			fup(j,1,N-1,1)V.pb(v[i][j]-v[i][j-1]);
			V.pb(v[i][0]+n-v[i][N-1]);
			bool ook=0;
			for(int sz:vv[N])
			{
				bool ok=1;
				Vi t;
				int sum=0;
				fup(j,0,sz-1,1)
				{
					t.pb(V[j]);
					sum+=V[j];
				}
				fup(j,sz,N-1,1)if(V[j]!=t[j%sz])ok=0;
				if(ok)
				{
					ook=1;
					g[i]=sum;
					break;
				}
			}
			if(!ook)return !printf("No");
		}
	}
	ll ans=0;
	fup(i,1,n-1,1)
	{
		ans=lcm(ans,g[i]);
		if(ans>=(ll)n)return !printf("No");
	}
	puts("Yes");
}