#include <bits/stdc++.h>
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
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<ld> Vd;
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
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

char s[1000005];
ll p1[1000005],p2[1000005];
ll H1[1000005],H2[1000005],R1[1000005],R2[1000005];;
const ll MOD1=1000000009,MOD2=1000000021;
bool pal(int l,int r)
{
	int len=r-l+1;
	Pll P1,P2;
	P1.X=(H1[r]-H1[l-1]*p1[len])%MOD1;
	if(P1.X<0)P1.X+=MOD1;
	P1.Y=(H2[r]-H2[l-1]*p2[len])%MOD2;
	if(P1.Y<0)P1.Y+=MOD2;
	P2.X=(R1[l]-R1[r+1]*p1[len])%MOD1;
	if(P2.X<0)P2.X+=MOD1;
	P2.Y=(R2[l]-R2[r+1]*p2[len])%MOD2;
	if(P2.Y<0)P2.Y+=MOD2;
	return P1==P2;
}
int main(){
	p1[0]=p2[0]=1;
	fup(i,1,1000000,1)
	{
		p1[i]=(p1[i-1]*29)%MOD1;
		p2[i]=(p2[i-1]*37)%MOD2;
	}
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		int l=1,r=n;
		fup(i,1,n,1)
		{
			H1[i]=(H1[i-1]*29+s[i]-'a'+1)%MOD1;
			H2[i]=(H2[i-1]*37+s[i]-'a'+1)%MOD2;
		}
		R1[n+1]=R2[n+1]=0;
		fdn(i,n,1,1)
		{
			R1[i]=(R1[i+1]*29+s[i]-'a'+1)%MOD1;
			R2[i]=(R2[i+1]*37+s[i]-'a'+1)%MOD2;
		}
		while(l<r && s[l]==s[r])l++,r--;
		if(l>=r)
		{
			printf("%s\n",s+1);
			continue;
		}
		int t1=0,t2=n;
		fup(i,l,r,1)if(pal(l,i))t1=i;
		fdn(i,r,l,1)if(pal(i,r))t2=i;
		fup(i,1,l-1,1)printf("%c",s[i]);
		if(t1-l>r-t2)
		{
			fup(i,l,t1,1)printf("%c",s[i]);
		}
		else
		{
			fup(i,t2,r,1)printf("%c",s[i]);
		}
		fup(i,r+1,n,1)printf("%c",s[i]);
		puts("");
	}
}