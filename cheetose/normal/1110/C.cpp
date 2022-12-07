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
#define INF 987654321987654321
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

bool chk[1<<25];
int ans[1<<25];
int main() {
	ans[3]=1;
	ans[7]=1;
	ans[15]=5;
	ans[31]=1;
	ans[63]=21;
	ans[127]=1;
	ans[255]=85;
	ans[511]=73;
	ans[1023]=341;
	ans[2047]=89;
	ans[4095]=1365;
	ans[8191]=1;
	ans[16383]=5461;
	ans[32767]=4681;
	ans[65535]=21845;
	ans[131071]=1;
	ans[262143]=87381;
	ans[524287]=1;
	ans[1048575]=349525;
	ans[2097151]=299593;
	ans[4194303]=1398101;
	ans[8388607]=178481;
	ans[16777215]=5592405;
	ans[33554431]=1082401;
	fup(i,1,25,1)chk[(1<<i)-1]=1;
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int x;
		scanf("%d",&x);
		if(!chk[x])
		{
			int c=1;
			while(c<=x)c<<=1;
			printf("%d\n",c-1);
		}
		else
		{
			printf("%d\n",ans[x]);
		}
	}
}