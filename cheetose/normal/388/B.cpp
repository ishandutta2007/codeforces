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

Vi v[10];
char c[1005][1005];
void add(int x,int y)
{
	c[x][y]=c[y][x]='Y';
}
void solve()
{
	int a[10],n[10];
	fup(i,0,9,1)a[i]=i+2;
	fup(k,0,9,1)
	{
		a[k]+=10;
		add(0,a[k]);
	}
	fup(tt,1,8,1)
	{
		fup(k,0,9,1)
		{
			n[k]=a[k]+10;
			add(a[k],n[k]);
		}
		fup(ii,0,9,1)fup(jj,0,9,1)add(a[ii],n[jj]);
		fup(k,0,9,1)a[k]=n[k];
	}
	fup(k,0,9,1)add(a[k],1);
}
void Print()
{
	puts("1000");
	fup(i,0,999,1)
	{
		fup(j,0,999,1)printf("%c",c[i][j]);
		puts("");
	}
}
int main() {
	memset(c,'N',sizeof(c));
	int kk;
	scanf("%d",&kk);
	if(kk==1000000000)
	{
		solve();
		Print();
		return 0;
	}
	int a[10],n[10];
	fup(i,0,9,1)a[i]=i+2;
	fup(i,0,8,1)
	{
		fup(k,0,9,1)
		{
			a[k]+=10;
			v[i].pb(a[k]);
		}
		int t=i;
		fup(tt,1,8,1)
		{
			fup(k,0,9,1)
			{
				n[k]=a[k]+10;
				add(a[k],n[k]);
			}
			if(t>0)
			{
				fup(ii,0,9,1)fup(jj,0,9,1)add(a[ii],n[jj]);
				t--;
			}
			fup(k,0,9,1)a[k]=n[k];
		}
		fup(k,0,9,1)add(a[k],1);
	}
	fup(ii,0,9,1)
	{
		int t=kk%10;
		fup(i,0,t-1,1)add(0,v[ii][i]);
		kk/=10;
	}
	Print();
}