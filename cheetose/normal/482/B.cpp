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

VPi v[30];
int a[100001],d[100001][17],l[100001],r[100001],q[100001];
int AND(int l,int r)
{
	int t=r-l+1;
	int now=l,ans=(1<<30)-1;
	fdn(i,16,0,1)
	{
		if(t&(1<<i))
		{
			ans&=d[now][i];
			now+=(1<<i);
		}
	}
	return ans;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,0,m-1,1)
	{
		scanf("%d%d%d",l+i,r+i,q+i);
		fup(k,0,29,1)
			if(q[i]&(1<<k))v[k].pb(mp(l[i],r[i]));
	}
	fup(i,0,29,1)
	{
		sort(ALL(v[i]));
		int p=1;
		for(Pi P:v[i])
		{
			int L,R;
			tie(L,R)=P;
			if(L>p)p=L;
			while(p<=R)a[p++]|=(1<<i);
		}
	}
	fup(i,1,n,1)d[i][0]=a[i];
	fup(j,1,16,1)
	{
		fup(i,1,n,1)
		{
			if(i+(1<<(j-1))>n)break;
			d[i][j]=d[i][j-1]&d[i+(1<<(j-1))][j-1];
		}
	}
	fup(i,0,m-1,1)
	{
		if(AND(l[i],r[i])!=q[i])return !printf("NO");
	}
	puts("YES");
	fup(i,1,n,1)printf("%d ",a[i]);
}