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
const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;
const ll MOD3 = 1000000021;
const ll H1=31;
const ll H2=37;
const ll H3=43;
//ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

ll h1[1000001],h2[1000001],h3[1000001];
ll POW1[1000001],POW2[1000001],POW3[1000001];
char s[100005],t[1000005];
int N,M;
LLL res(int i,int j)
{
	int k=j-i+1;
	ll x,y,z;
	x=h1[j]-(POW1[k]*h1[i-1])%MOD1;
	if(x<0)x+=MOD1;
	y=h2[j]-(POW2[k]*h2[i-1])%MOD2;
	if(y<0)y+=MOD2;
	z=h3[j]-(POW3[k]*h3[i-1])%MOD3;
	if(z<0)z+=MOD3;
	return LLL(x,y,z);
}
int go(int A,int B)
{
	LLL l0=LLL(-1LL,-1LL,-1LL),l1=LLL(-1LL,-1LL,-1LL);
	int now=1;
	fup(i,1,N,1)
	{
		if(s[i]=='0')
		{
			LLL t=res(now,now+A-1);
			if(get<0>(l0)==-1)l0=t;
			else if(l0!=t)return 0;
			now+=A;
		}
		else
		{
			LLL t=res(now,now+B-1);
			if(get<0>(l1)==-1)l1=t;
			else if(l1!=t)return 0;
			now+=B;
		}
	}
	return l0!=l1;
}
int main() {
	POW1[0]=POW2[0]=POW3[0]=1;
	fup(i,1,1000000,1)
	{
		POW1[i]=(POW1[i-1]*H1)%MOD1;
		POW2[i]=(POW2[i-1]*H2)%MOD2;
		POW3[i]=(POW3[i-1]*H3)%MOD3;
	}
	scanf("%s%s",s+1,t+1);
	N=strlen(s+1),M=strlen(t+1);
	h1[0]=h2[0]=h3[0]=1;
	fup(i,1,M,1)
	{
		int tt=t[i]-'0'+1;
		h1[i]=(h1[i-1]*H1+tt)%MOD1;
		h2[i]=(h2[i-1]*H2+tt)%MOD2;
		h3[i]=(h3[i-1]*H3+tt)%MOD3;
	}
	int c0=0,c1=0;
	fup(i,1,N,1)
	{
		if(s[i]=='0')c0++;
		else c1++;
	}
	int ans=0;
	for(int i=1;i*c0<M;i++)
	{
		int rem=M-i*c0;
		if(rem%c1==0)ans+=go(i,rem/c1);
	}
	printf("%d",ans);
}