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
const ll MOD = 1000000021;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

ll h[5005],rh[5005],p[5005];
char s[5005];
int d[5005][5005],ans[5005];
ll ha(int l,int r)
{
	int t=r-l+1;
	ll tt=(p[t]*h[l-1])%MOD;
	tt=h[r]-tt;
	if(tt<0)tt+=MOD;
	return tt;
}
ll rha(int l,int r)
{
	int t=r-l+1;
	ll tt=(p[t]*rh[r+1])%MOD;
	tt=rh[l]-tt;
	if(tt<0)tt+=MOD;
	return tt;
}
bool pal(int l,int r){return ha(l,r)==rha(l,r);}
int main() {
	p[0]=1;
	fup(i,1,5004,1)p[i]=(p[i-1]*37)%MOD;
	scanf("%s",s+1);
	int n=strlen(s+1);
	fup(i,1,n,1)
		h[i]=(h[i-1]*37+s[i]-'0')%MOD;
	fdn(i,n,1,1)
		rh[i]=(rh[i+1]*37+s[i]-'0')%MOD;
	fup(i,1,n,1)d[i][i]=1;
	fup(l,1,n,1)
	{
		fup(k,2,n,1)
		{
			int r=l+k-1;
			int m=(l+r)/2;
			if(r>n)break;
			if(pal(l,r))
			{
				if(k&1)
				{
					if(ha(l,m-1)==ha(m+1,r) && pal(l,m-1))d[l][r]=d[l][m-1]+1;
					else d[l][r]=1;
				}
				else
				{
					if(ha(l,m)==ha(m+1,r) && pal(l,m))d[l][r]=d[l][m]+1;
					else d[l][r]=1;
				}
			}
		}
	}
	fup(i,1,n,1)fup(j,i,n,1)ans[d[i][j]]++;
	fdn(i,n,1,1)ans[i]+=ans[i+1];
	fup(i,1,n,1)printf("%d ",ans[i]);
}