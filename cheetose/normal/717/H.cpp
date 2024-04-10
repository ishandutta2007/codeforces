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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int n,m;
int x[100001],y[100001];
Vi v[50000];
int team[50000],col[1000001];
int main() {
	srand(time(NULL));
	scanf("%d%d",&n,&m);
	fup(i,0,m-1,1)
	{
		scanf("%d%d",x+i,y+i);
		x[i]--,y[i]--;
	}
	int T=-1;
	fup(i,0,n-1,1)
	{
		int t;
		scanf("%d",&t);
		while(t--)
		{
			int xx;
			scanf("%d",&xx);
			v[i].pb(xx);
			if(xx>T)T=xx;
		}
	}
	while(1)
	{
		fup(i,0,n-1,1)
		{
			int t=rand()%v[i].size();
			team[i]=v[i][t];
		}
		fup(i,1,T,1)col[i]=rand()%2;
		int tot=0;
		fup(i,0,m-1,1)tot+=(col[team[x[i]]]!=col[team[y[i]]]);
		if(2*tot>=m)
		{
			fup(i,0,n-1,1)printf("%d ",team[i]);
			puts("");
			fup(i,1,T,1)printf("%d ",col[i]+1);
			return 0;
		}
	}
}