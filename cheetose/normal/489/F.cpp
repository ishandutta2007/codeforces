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
ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

inline ll nC2(int n){return n*(n-1)/2;}
char s[501][501];
int r[501],c[501];
ll d[501][501];
ll go(int a,int b)
{
	if(a==0 && b==0)return 1;
	if(a==0 && b==1)return 0;
	ll &ret=d[a][b];
	if(ret!=-1)return ret;
	ret=0;
	if(b>=2)ret=(ret+nC2(b)*go(a+2,b-2))%MOD;
	if(a>=1&&b>=1)ret=(ret+a*b*go(a,b-1))%MOD;
	if(a>=2)ret=(ret+nC2(a)*go(a-2,b))%MOD;
	return ret;
}
int main() {
	MEM_1(d);
	int n,m;
	scanf("%d%d%lld",&m,&n,&MOD);
	fup(i,0,n-1,1)scanf("%s",s[i]);
	fup(i,0,n-1,1)fup(j,0,m-1,1)r[i]+=s[i][j]-'0',c[j]+=s[i][j]-'0';
	fup(i,0,n-1,1)if(r[i]!=2)return !printf("0");
	fup(j,0,m-1,1)if(c[j]>2)return !printf("0");
	int c1=0,c2=0;
	fup(i,0,m-1,1)
	{
		if(c[i]==0)c2++;
		if(c[i]==1)c1++;
	}
	printf("%lld",go(c1,c2));
}