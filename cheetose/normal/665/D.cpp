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

int cnt[1000001];
bitset<2000001> prime;
int main() {
	prime.set();
	fup(i,2,1000000,1)
	{
		if(!prime[i])continue;
		fup(j,i+i,2000000,i)
			prime[j]=0;
	}
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)
	{
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}
	if(cnt[1])
	{
		fup(i,2,1000000,2)
		{
			if(cnt[i] && prime[i+1])
			{
				printf("%d\n",cnt[1]+1);
				while(cnt[1]--)printf("1 ");
				return !printf("%d",i);
			}
		}
		if(cnt[1]>=2)
		{
			printf("%d\n",cnt[1]);
			while(cnt[1]--)printf("%d ",1);
			return 0;
		}
	}
	Vi v[2];
	fup(i,2,1000000,1)
	{
		if(cnt[i])v[i&1].pb(i);
	}
	int N=v[0].size(),M=v[1].size();
	fup(i,0,N-1,1)fup(j,0,M-1,1)
	{
		if(prime[v[0][i]+v[1][j]])
		{
			puts("2");
			return !printf("%d %d",v[0][i],v[1][j]);
		}
	}
	puts("1");
	fup(i,1,1000000,1)
		if(cnt[i])return !printf("%d",i);
}