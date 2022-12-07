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
typedef pair<double, double> Pd;
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

bitset<10001> pre[102][102],suf[102][102],bs,tmp;
int n,ans,cnt[101];
int main() {
	scanf("%d",&n);
	fup(i,0,n-1,1)
	{
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}
	int c=0;
	fup(i,1,100,1)if(cnt[i])c++;
	if(c<3)return !printf("%d",n);
	pre[0][0][0]=1;
	fup(x,1,100,1)
	{
		fup(i,0,cnt[x],1)
			fup(j,i,n,1)pre[x][j]|=(pre[x-1][j-i]<<(i*x));
	}
	suf[101][0][10000]=1;
	fdn(x,100,1,1)
	{
		fup(i,0,cnt[x],1)
			fup(j,i,n,1)suf[x][j]|=(suf[x+1][j-i]>>(i*x));
	}
	fup(i,1,100,1)
		fup(j,1,cnt[i],1)
	{
		int x=i*j;
		bs=0;
		fup(k,0,j,1)
		{
			tmp=suf[i+1][j-k];
			tmp>>=(10000-x);
			tmp&=pre[i-1][k];
			bs|=tmp;
		}
		if(bs==0)ans=max(ans,j);
		else break;
	}
	printf("%d",ans);
}