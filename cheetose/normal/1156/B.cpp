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
#define INF 987654321987654321
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

char s[101];
int cnt[26];
void print(int i)
{
	while(cnt[i]--)printf("%c",i+'a');
}
void solve()
{
	MEM0(cnt);
	scanf("%s",s);
	int n=strlen(s);
	fup(i,0,n-1,1)cnt[s[i]-'a']++;
	Vi v;
	fup(i,0,25,1)if(cnt[i])v.pb(i);
	int N=v.size();
	if(N>=5)
	{
		fup(i,0,N-1,2)print(v[i]);
		fup(i,1,N-1,2)print(v[i]);
		puts("");
		return;
	}
	if(N==4)
	{
		print(v[1]);
		print(v[3]);
		print(v[0]);
		print(v[2]);
		puts("");
		return;
	}
	if(N==3)
	{
		if(v[2]-v[0]==2)
		{
			puts("No answer");
			return;
		}
		print(v[1]);
		if(v[2]-v[1]==1)
		{
			print(v[0]);
			print(v[2]);
			puts("");
		}
		else
		{
			print(v[2]);
			print(v[0]);
			puts("");
		}
		return;
	}
	if(N==2)
	{
		if(v[1]-v[0]==1)
		{
			puts("No answer");
			return;
		}
		print(v[0]);
		print(v[1]);
		puts("");
		return;
	}
	if(N==1)
	{
		print(v[0]);
		puts("");
		return;
	}
}
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}