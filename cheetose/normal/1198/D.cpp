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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int d[52][52][52][52];
int c[52][52];
char s[52][52];
int go(int x1,int y1,int x2,int y2)
{
	if(c[x2][y2]-c[x1-1][y2]-c[x2][y1-1]+c[x1-1][y1-1]==0)return 0;
	int &ret=d[x1][y1][x2][y2];
	if(ret!=-1)return ret;
	ret=max(y2-y1+1,x2-x1+1);
	fup(i,x1,x2-1,1)ret=min(ret,go(x1,y1,i,y2)+go(i+1,y1,x2,y2));
	fup(i,y1,y2-1,1)ret=min(ret,go(x1,y1,x2,i)+go(x1,i+1,x2,y2));
	return ret;
}
int main() {
	MEM_1(d);
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)scanf("%s",s[i]+1);
	fup(i,1,n,1)
		fup(j,1,n,1)
	{
		c[i][j]=c[i][j-1]+c[i-1][j]-c[i-1][j-1]+(s[i][j]=='#');
	}
	printf("%d",go(1,1,n,n));
}