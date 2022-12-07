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
const ll MOD = 1000000021;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

char a[300005];
int ne[26][300005];
ll ans[27];
int main() {
	scanf("%s",a);
	int n=strlen(a);
	fup(i,0,n-1,1)a[i]-='a';
	fup(i,0,25,1)
	{
		int t=INF;
		fdn(j,n-1,0,1)
		{
			ne[i][j]=t;
			if(a[j]==i)t=j;
		}
	}
	fup(i,0,n-1,1)
	{
		int cnt=1,k=1<<a[i],now=i;
		while(1)
		{
			int next=INF,what=-1;
			fup(t,0,25,1)
			{
				if(k&(1<<t))continue;
				int it=ne[t][now];
				if(it<next)
				{
					next=it;
					what=t;
				}
			}
			if(next==INF)
			{
				ans[cnt]+=n-now;
				break;
			}
			else
			{
				ans[cnt++]+=next-now;
				k|=(1<<what);
				now=next;
			}
		}
	}
	fdn(i,26,0,1)
		if(ans[i])
		{
			printf("%d\n",i);
			fup(j,1,i,1)
				printf("%lld\n",ans[j]);
			return 0;
		}
}