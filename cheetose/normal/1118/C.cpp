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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int ans[20][20];
int cnt[1001];
int main() {
	int n;
	scanf("%d",&n);
	fup(i,1,n*n,1)
	{
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}
	Vi v;
	fup(i,1,1000,1)if(cnt[i]&1)v.pb(i);
	if(v.size()>1)return !printf("NO");
	if(v.size() && n%2==0)return !printf("NO");
	if(n&1)
	{
		cnt[v[0]]--;
		ans[n/2][n/2]=v[0];
		int now=1;
		fup(i,0,n/2-1,1)
		{
			fup(j,0,n/2-1,1)
			{
				while(now<=1000 && cnt[now]<4)now++;
				if(now>1000)break;
				ans[i][j]=ans[n-1-i][j]=ans[i][n-1-j]=ans[n-1-i][n-1-j]=now;
				cnt[now]-=4;
			}
		}
		now=1;
		fup(i,0,n/2-1,1)
		{
			while(now<=1000 && !cnt[now])now++;
			if(now>1000)break;
			ans[i][n/2]=ans[n-1-i][n/2]=now;
			cnt[now]-=2;
		}
		fup(i,0,n/2-1,1)
		{
			while(now<=1000 && !cnt[now])now++;
			if(now>1000)break;
			ans[n/2][i]=ans[n/2][n-1-i]=now;
			cnt[now]-=2;
		}
		fup(i,0,n-1,1)fup(j,0,n-1,1)if(!ans[i][j])return !printf("NO");
		puts("YES");
		fup(i,0,n-1,1)
		{
			fup(j,0,n-1,1)printf("%d ",ans[i][j]);
			puts("");
		}
	}
	else
	{
		int now=1;
		fup(i,0,n/2-1,1)
		{
			fup(j,0,n/2-1,1)
			{
				while(now<=1000 && !cnt[now])now++;
				if(now>1000)break;
				if(cnt[now]%4)return !printf("NO");
				ans[i][j]=ans[n-1-i][j]=ans[i][n-1-j]=ans[n-1-i][n-1-j]=now;
				cnt[now]-=4;
			}
		}
		puts("YES");
		fup(i,0,n-1,1)
		{
			fup(j,0,n-1,1)printf("%d ",ans[i][j]);
			puts("");
		}
	}
}