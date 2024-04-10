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

char s[1000005];
int a[1000005],b[1000005],c[1000005];
int main() {
	int n;
	scanf("%d%s",&n,s);
	int c1=count(s,s+n,'('),c2=count(s,s+n,')');
	if(c1+2==c2)
	{
		reverse(s,s+n);
		a[0]=(s[0]==')'?1:-1);
		fup(i,1,n-1,1)a[i]=a[i-1]+(s[i]==')'?1:-1);
		b[n-1]=a[n-1];
		fdn(i,n-2,0,1)b[i]=min(a[i],b[i+1]);
		c[0]=a[0];
		fup(i,1,n-1,1)c[i]=min(c[i-1],a[i]);
		int ans=0;
		fup(i,1,n-1,1)if(s[i]==')' && b[i]==2 && c[i-1]>=0)ans++;
		printf("%d",ans);
	}
	else if(c2+2==c1)
	{
		a[0]=(s[0]=='('?1:-1);
		fup(i,1,n-1,1)a[i]=a[i-1]+(s[i]=='('?1:-1);
		b[n-1]=a[n-1];
		fdn(i,n-2,0,1)b[i]=min(a[i],b[i+1]);
		c[0]=a[0];
		fup(i,1,n-1,1)c[i]=min(c[i-1],a[i]);
		int ans=0;
		fup(i,1,n-1,1)if(s[i]=='(' && b[i]==2 && c[i-1]>=0)ans++;
		printf("%d",ans);
	}
	else return !printf("0");
}