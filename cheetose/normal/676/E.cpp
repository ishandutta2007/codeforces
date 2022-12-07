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
#define INF 987654321
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
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

const ll MOD1=998244353,MOD2=1000000021;
string s[100001];
int a[100001];
int main() {
	SYNC;
	int n,k;
	cin>>n>>k;
	fup(i,0,n,1)cin>>s[i];
	int cnt=n+1;
	fup(i,0,n,1)if(s[i]=="?")cnt--;
	if(k==0)
	{
		if(s[0]=="0")cout<<"Yes";
		else if(s[0]=="?")cout<<(cnt&1?"Yes":"No");
		else cout<<"No";
		return 0;
	}
	if(cnt<=n)
	{
		if(n&1)cout<<"Yes";
		else cout<<"No";
		return 0;
	}
	fup(i,0,n,1)
	{
		int N=s[i].length();
		if(s[i][0]=='-')
		{
			fup(j,1,N-1,1)a[i]=10*a[i]+s[i][j]-'0';
			a[i]*=-1;
		}
		else
		{
			fup(j,0,N-1,1)a[i]=10*a[i]+s[i][j]-'0';
		}
	}
	ll c1=0,c2=0;
	fup(i,0,n,1)
	{
		c1=(c1+a[i]*POW(k,i,MOD1))%MOD1;
		c2=(c2+a[i]*POW(k,i,MOD2))%MOD2;
		if(c1<0)c1+=MOD1;
		if(c2<0)c2+=MOD2;
	}
	cout<<(c1==0 && c2==0?"Yes":"No");
}