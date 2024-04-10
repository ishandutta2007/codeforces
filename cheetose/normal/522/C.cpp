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

int cnt[100001];
Pi p[100001];
void solve()
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector<bool> chk(m),tt(m);
	int c=0;
	int mn=INF;
	fup(i,0,m-1,1)
		scanf("%d",cnt+i);
	int fi=-1;
	fup(i,1,n-1,1)
	{
		scanf("%d%d",&p[i].X,&p[i].Y);
		p[i].X--;
		if(fi==-1 && p[i].Y)fi=i;
		if(fi!=-1 && p[i].X!=-1)tt[p[i].X]=1;
	}
	fup(i,1,n-1,1)
	{
		if(i==fi)
		{
			int t=-1;
			fup(j,0,m-1,1)
			{
				if(tt[j])continue;
				if(cnt[j]<=c)chk[j]=1;
				if(t==-1 || cnt[j]<cnt[t])t=j;
			}
			c-=cnt[t];
			cnt[t]=0;
		}
		if(p[i].X==-1)c++;
		else cnt[p[i].X]--;
	}
	fup(i,0,m-1,1)if(cnt[i]<=c)chk[i]=1;
	fup(i,0,m-1,1)putchar(chk[i]?'Y':'N');
	puts("");
}
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}