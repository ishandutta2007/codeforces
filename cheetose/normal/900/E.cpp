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
#define INF 1987654321
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

char s[100005];
int n,m;
int a[2],b[2];
int cnt[100005];
Pi d[100005];
int main() {
	MEM_1(cnt);
	scanf("%d%s%d",&n,s,&m);
	d[n]=mp(0,0);
	fup(i,0,m-2,1)
	{
		if(s[i]=='a')a[i&1]++;
		if(s[i]=='b')b[i&1]++;
	}
	fup(i,m-1,n-1,1)
	{
		if(s[i]=='a')a[1-(m&1)]++;
		if(s[i]=='b')b[1-(m&1)]++;
		if(a[1]==0 && b[0]==0)
		{
			cnt[i-m+1]=m-a[0]-b[1];
		}
		if(s[i-m+1]=='a')a[0]--;
		if(s[i-m+1]=='b')b[0]--;
		swap(a[0],a[1]);swap(b[0],b[1]);
	}
	fdn(i,n-1,0,1)
	{
		d[i]=d[i+1];
		if(i+m<=n && cnt[i]!=-1)
		{
			if(d[i+m].X+1>d[i].X)
			{
				d[i].X=d[i+m].X+1;
				d[i].Y=d[i+m].Y+cnt[i];
			}
			else if(d[i+m].X+1==d[i].X && d[i+m].Y+cnt[i]<d[i].Y)
			{
				d[i].Y=d[i+m].Y+cnt[i];
			}
		}
	}
	printf("%d",d[0].Y);
}