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
#define INF 2087654321
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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int cnt[1000001],t[2000001];
int main() {
	MEM_1(t);
	int asd=1;
	t[1]=0;
	while(1)
	{
		asd<<=1;
		if(asd>2000000)break;
		t[asd]=t[asd/2]+1;
	}
	int n;
	scanf("%d",&n);
	if(n==1)return !printf("1 0");
	for(int i=2;i*i<=n;i++)
	{
		while(n%i==0)
		{
			cnt[i]++;
			n/=i;
		}
	}
	if(n!=1)cnt[n]++;
	VPi v;
	fup(i,1,1000000,1)if(cnt[i])v.pb(mp(i,cnt[i]));
	int mm=INF,MM=0;
	int N=v.size();
	int ans=1;
	fup(i,0,N-1,1)
	{
		ans*=v[i].X;
		mm=min(mm,v[i].Y);
		MM=max(MM,v[i].Y);
	}
	printf("%d ",ans);
	if(MM==mm && t[MM]!=-1)return !printf("%d",t[MM]);
	while(t[MM]==-1)MM++;
	printf("%d",t[MM]+1);
}