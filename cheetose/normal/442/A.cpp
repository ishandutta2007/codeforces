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

int z(char c)
{
	if(c=='R')return 0;
	if(c=='G')return 1;
	if(c=='B')return 2;
	if(c=='Y')return 3;
	return 4;
}
int n;
int a[5][5],b[5][5],r[5],c[5];
char s[3];
int main() {
	scanf("%d",&n);
	fup(i,0,n-1,1)
	{
		scanf("%s",s);
		a[z(s[0])][s[1]-'1']=1;
	}
	int ans=INF;
	fup(i,0,31,1)
	{
		fup(j,0,31,1)
		{
			memcpy(b,a,sizeof b);
			int tmp=0;
			fup(k,0,4,1)
			{
				if(i&(1<<k))
				{
					r[k]=1;
					tmp++;
				}
				else r[k]=0;
				if(j&(1<<k))
				{
					c[k]=1;
					tmp++;
				}
				else c[k]=0;
			}
			fup(ii,0,4,1)fup(jj,0,4,1)if(r[ii]&&c[jj])b[ii][jj]=0;
			bool ok=1;
			while(ok)
			{
				ok=0;
				fup(ii,0,4,1)
				{
					if(!r[ii])continue;
					int t=0;
					fup(jj,0,4,1)t+=b[ii][jj];
					if(t==1)
					{
						ok=1;
						fup(jj,0,4,1)b[ii][jj]=0;
					}
				}
				fup(jj,0,4,1)
				{
					if(!c[jj])continue;
					int t=0;
					fup(ii,0,4,1)t+=b[ii][jj];
					if(t==1)
					{
						ok=1;
						fup(ii,0,4,1)b[ii][jj]=0;
					}
				}
			}
			int t=0;
			fup(ii,0,4,1)fup(jj,0,4,1)t+=b[ii][jj];
			if(t<=1)ans=min(ans,tmp);
		}
	}
	printf("%d",ans);
}