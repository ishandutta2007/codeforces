#include <bits/stdc++.h>
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
typedef pair<ld, ld> Pd;
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
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

char s[1005];
int t[1005],a[1005],b[1005],n;
void gg(int j,int i,int f)
{
	if(j==0)
	{
		if(i>=f)
		{
			if(b[i]==-1 || t[i]==-1)return;
			a[n-1-i]=a[i]=b[i]^t[i];
			if(n-1-i>=f && b[n-1-i]==-1)gg(1,n-1-i,f);
		}
		else
		{
			if(t[i]==-1)return;
			a[n-1-i]=a[i]=t[i];
			if(n-1-i>=f && b[n-1-i]==-1)gg(1,n-1-i,f);
		}
	}
	else
	{
		if(a[i]==-1 || t[i]==-1)return;
		b[f+n-1-i]=b[i]=a[i]^t[i];
		if(a[f+n-1-i]==-1)gg(0,f+n-1-i,f);
	}
}
void ff(int j,int i,int f)
{
	if(j==0)
	{
		a[i]=3;
		a[n-1-i]=3;
		if(i>=f && b[i]==-1 && t[i]!=-1)ff(1,i,f);
		if(n-1-i>=f && b[n-1-i]==-1 && t[n-1-i]!=-1)ff(1,n-1-i,f);
	}
	else
	{
		b[i]=3;
		b[f+n-1-i]=3;
		if(a[i]==-1 && t[i]!=-1)ff(0,i,f);
		if(a[f+n-1-i]==-1 && t[f+n-1-i]!=-1)ff(0,f+n-1-i,f);
	}
}
int g(int k)
{
	int f=n-k;
	MEM_1(a);MEM_1(b);
	a[0]=a[n-1]=b[f]=b[n-1]=1;
	fup(i,1,f-1,1)
	{
		if(t[i]!=-1)
		{
			a[i]=t[i];
			if(a[n-1-i]!=-1 && a[i]!=a[n-1-i])return 0;
			a[n-1-i]=a[i];
		}
	}
	if(a[f]!=-1)
	{
		if(t[f]!=-1 && a[f]^b[f]!=t[f])return 0;
	}
	else if(t[f]!=-1)
	{
		int x=b[f]^t[f];
		if(a[n-1-f]!=-1 && a[n-1-f]!=x)return 0;
		a[n-1-f]=a[f]=x;
	}
	fup(i,f+1,n-2,1)
	{
		if(a[i]!=-1 && t[i]!=-1)
		{
			if(b[i]!=-1 && b[i]!=a[i]^t[i])return 0;
			b[i]=a[i]^t[i];
			if(b[f+n-1-i]!=-1 && b[f+n-1-i]!=b[i])return 0;
			b[f+n-1-i]=b[i];
			if(a[f+n-1-i]==-1)gg(0,f+n-1-i,f);
		}
	}
	int res=1;
	fup(i,1,n-2,1)
	{
		if(a[i]==-1)
		{
			ff(0,i,f);
			res=(res<<1)%MOD;
		}
		if(i>=f && b[i]==-1)
		{
			ff(1,i,f);
			res=(res<<1)%MOD;
		}
	}
	return res;
}
int main() {
	scanf("%s",s);
	n=strlen(s);
	if(s[n-1]=='1')return !printf("0");
	fup(i,0,n-1,1)
	{
		if(s[i]!='?')t[i]=s[i]-'0';
		else t[i]=-1;
	}
	int ans=0;
	fup(i,1,n-1,1)ans=(ans+g(i))%MOD;
	printf("%d",ans);
}