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
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int n,m;
char s[2002][2002];
int cnt[2002][2002];
int cc(int a,int b,int c,int d)
{
	return cnt[c][d]-cnt[a-1][d]-cnt[c][b-1]+cnt[a-1][b-1];
}
int main() {
	scanf("%d%d",&n,&m);
	fup(i,1,n,1)scanf("%s",s[i]+1);
	int mnx=INF,mxx=-1,mny=INF,mxy=-1;
	fup(i,1,n,1)
		fup(j,1,m,1)
		{
			if(s[i][j]=='w')
			{
				cnt[i][j]++;
				mnx=min(mnx,i);
				mxx=max(mxx,i);
				mny=min(mny,j);
				mxy=max(mxy,j);
			}
			cnt[i][j]+=cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1];
		}
	int t=max(mxx-mnx,mxy-mny);
	if(t==0)
	{
		fup(i,1,n,1)printf("%s\n",s[i]+1);
		return 0;
	}
	fup(i,1,n,1)
	{
		fup(j,1,m,1)
		{
			if(i+t>n || j+t>m)break;
			if(cc(i,j,i+t,j+t)!=cnt[n][m])continue;
			if(t>=2 && cc(i+1,j+1,i+t-1,j+t-1)>0)continue;
			fup(ii,0,t,1)
			{
				if(s[i+ii][j]=='.')s[i+ii][j]='+';
				if(s[i+ii][j+t]=='.')s[i+ii][j+t]='+';
				if(s[i][j+ii]=='.')s[i][j+ii]='+';
				if(s[i+t][j+ii]=='.')s[i+t][j+ii]='+';
			}
			fup(i,1,n,1)printf("%s\n",s[i]+1);
			return 0;
		}
	}
	puts("-1");
}