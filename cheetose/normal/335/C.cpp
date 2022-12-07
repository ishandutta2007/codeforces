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
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
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
const ll MOD1 = 1000000009;
const ll MOD2 = 1000000021;
//ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int n,m;
bool chk[100][2];
int d[100][100][4][4];
int go(int l,int r,int ll,int rr)
{
	if(l>r)return 0;
	int &ret=d[l][r][ll][rr];
	if(ret!=-1)return ret;
	Vi mex;
	fup(i,l,r,1)
	{
		fup(j,0,1,1)
		{
			if(chk[i][j] || (i==l && (ll&(1<<j))) || (i==r && (rr&(1<<j))) )continue;
			mex.pb(go(l,i-1,ll,1<<(1-j)) ^ go(i+1,r,1<<(1-j),rr));
		}
	}
	if(mex.empty())return ret=0;
	sort(ALL(mex));
	mex.resize(unique(ALL(mex))-mex.begin());
	fup(i,0,(int)mex.size(),1)if(mex[i]!=i)return ret=i;
	return ret=(int)mex.size();
}
int main() {
	MEM_1(d);
	scanf("%d%d",&n,&m);
	fup(i,0,m-1,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--,y--;
		chk[x][y]=chk[x][1-y]=1;
		if(x)chk[x-1][1-y]=1;
		if(x+1<n)chk[x+1][1-y]=1;
	}
	if(go(0,n-1,0,0))puts("WIN");
	else puts("LOSE");
}