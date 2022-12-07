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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int a[5002],d[2501][5002],MIN[2501][5002];
int main() {
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)scanf("%d",a+i);
	d[1][0]=INF;
	MIN[1][0]=INF;
	fup(i,1,n,1)
	{
		d[1][i]=max(0,a[i-1]-a[i]+1)+max(0,a[i+1]-a[i]+1);
		MIN[1][i]=min(MIN[1][i-1],d[1][i]);
	}
	fup(k,2,(n+1)/2,1)
	{
		d[k][0]=INF;
		MIN[k][0]=INF;
		fup(i,1,n,1)
		{
			if((i+1)/2<k)
			{
				d[k][i]=INF;
				MIN[k][i]=min(MIN[k][i-1],d[k][i]);
			}
			else
			{
				int t1=MIN[k-1][i-3]+d[1][i];
				int t=min(a[i-1],a[i-2]-1);
				int t2=d[k-1][i-2]+max(0,t-a[i]+1)+max(0,a[i+1]-a[i]+1);
				d[k][i]=min(t1,t2);
				MIN[k][i]=min(MIN[k][i-1],d[k][i]);
			}
		}
	}
	fup(k,1,(n+1)/2,1)
	{
		printf("%d ",*min_element(d[k]+1,d[k]+n+1));
	}
}