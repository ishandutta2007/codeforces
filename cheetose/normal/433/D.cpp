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
#define INF 1987654321
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
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int a[1002][1002];
int L[1002][1002],R[1002][1002],U[1002][1002],D[1002][1002];
int main() {
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	fup(i,1,n,1)fup(j,1,m,1)scanf("%d",a[i]+j);
	fup(i,1,n,1)
	{
		fup(j,1,m,1)
			if(a[i][j])L[i][j]=L[i][j-1]+1;
		fdn(j,m,1,1)
			if(a[i][j])R[i][j]=R[i][j+1]+1;
	}
	fup(j,1,m,1)
	{
		fup(i,1,n,1)
			if(a[i][j])U[i][j]=U[i-1][j]+1;
		fdn(i,n,1,1)
			if(a[i][j])D[i][j]=D[i+1][j]+1;
	}
	while(q--)
	{
		int o,x,y;
		scanf("%d%d%d",&o,&x,&y);
		if(o==1)
		{
			a[x][y]^=1;
			fup(j,1,m,1)
			{
				if(a[x][j])L[x][j]=L[x][j-1]+1;
				else L[x][j]=0;
			}
			fdn(j,m,1,1)
			{
				if(a[x][j])R[x][j]=R[x][j+1]+1;
				else R[x][j]=0;
			}
			fup(i,1,n,1)
			{
				if(a[i][y])U[i][y]=U[i-1][y]+1;
				else U[i][y]=0;
			}
			fdn(i,n,1,1)
			{
				if(a[i][y])D[i][y]=D[i+1][y]+1;
				else D[i][y]=0;
			}
		}
		else
		{
			if(a[x][y]==0)
			{
				puts("0");
				continue;
			}
			int l=y,r=y;
			int ans=-1;
			int tmp=U[x][y],h=tmp;
			while(1)
			{
				if(U[x][l-1]==0 && U[x][r+1]==0)break;
				if(U[x][l-1]>U[x][r+1])
				{
					h=min(h,U[x][l-1]);
					l--;
				}
				else
				{
					h=min(h,U[x][r+1]);
					r++;
				}
				tmp=max(tmp,(r-l+1)*h);
			}
			ans=max(ans,tmp);
			
			l=y,r=y;
			tmp=D[x][y],h=tmp;
			while(1)
			{
				if(D[x][l-1]==0 && D[x][r+1]==0)break;
				if(D[x][l-1]>D[x][r+1])
				{
					h=min(h,D[x][l-1]);
					l--;
				}
				else
				{
					h=min(h,D[x][r+1]);
					r++;
				}
				tmp=max(tmp,(r-l+1)*h);
			}
			ans=max(ans,tmp);
			
			l=x,r=x;
			tmp=L[x][y],h=tmp;
			while(1)
			{
				if(L[l-1][y]==0 && L[r+1][y]==0)break;
				if(L[l-1][y]>L[r+1][y])
				{
					h=min(h,L[l-1][y]);
					l--;
				}
				else
				{
					h=min(h,L[r+1][y]);
					r++;
				}
				tmp=max(tmp,(r-l+1)*h);
			}
			ans=max(ans,tmp);
			
			l=x,r=x;
			tmp=R[x][y],h=tmp;
			while(1)
			{
				if(R[l-1][y]==0 && R[r+1][y]==0)break;
				if(R[l-1][y]>R[r+1][y])
				{
					h=min(h,R[l-1][y]);
					l--;
				}
				else
				{
					h=min(h,R[r+1][y]);
					r++;
				}
				tmp=max(tmp,(r-l+1)*h);
			}
			ans=max(ans,tmp);
			printf("%d\n",ans);
		}
	}
}