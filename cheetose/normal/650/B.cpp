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
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int R[500005],L[500005];
int n,a,b,T;
char s[500005];
int main() {
	scanf("%d%d%d%d%s",&n,&a,&b,&T,s);
	R[n-1]=-1-('h'==s[n-1]?0:b);
	fdn(i,n-2,0,1)
	{
		R[i]=R[i+1]-a-1-('h'==s[i]?0:b);
	}
	L[1]=1+(s[1]=='h'?0:b);
	fup(i,2,n-1,1)
	{
		L[i]=L[i-1]+a+1+('h'==s[i]?0:b);
	}
	int cnt=0,ans=0,t=-a;
	fup(i,0,n-1,1)
	{
		t+=1+a+('h'==s[i]?0:b);
		if(t>T)break;
		cnt++;
		int tp=t+(i+1)*a;
		ans=max(ans,cnt+(int)(R+n-lower_bound(R+i+1,R+n,tp-T)));
	}
	t=1+('h'==s[0]?0:b),cnt=1;
	fdn(i,n-1,1,1)
	{
		t+=1+a+('h'==s[i]?0:b);
		if(t>T)break;
		cnt++;
		int tp=t+(n+1-i)*a;
		ans=max(ans,cnt+(int)(upper_bound(L+1,L+i,T-tp)-L-1));
	}
	printf("%d",ans);
}