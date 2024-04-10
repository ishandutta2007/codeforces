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
#define INF 2000000005
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
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int n,m;
inline int Z(int x,int y){return x*m+y;}
int cnt[4000000];
char s[2000][2001];
int main() {
	scanf("%d%d",&n,&m);
	fup(i,0,n-1,1)scanf("%s",s[i]);
	fup(x,0,n-1,1)
		fup(y,0,m-1,1)
	{
		int z=Z(x,y);
		if(s[x][y]=='*')continue;
		fup(i,0,3,1)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&s[nx][ny]=='.')
				cnt[Z(nx,ny)]++;
		}
	}
	queue<int> q;
	fup(i,0,n*m-1,1)if(cnt[i]==1)q.push(i);
	while(!q.empty())
	{
		int z=q.front();
		q.pop();
		int x=z/m,y=z%m;
		if(s[x][y]!='.')continue;
		fup(i,0,3,1)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&s[nx][ny]=='.')
			{
				int nz=Z(nx,ny);
				if(i==0) s[x][y]='<',s[nx][ny]='>';
				else if(i==1) s[x][y]='^',s[nx][ny]='v';
				else if(i==2) s[x][y]='>',s[nx][ny]='<';
				else s[x][y]='v',s[nx][ny]='^';
				fup(ii,0,3,1)
				{
					int nnx=nx+dx[ii],nny=ny+dy[ii];
					if(nnx>=0&&nnx<n&&nny>=0&&nny<m&&s[nnx][nny]=='.')
					{
						int nnz=Z(nnx,nny);
						cnt[nnz]--;
						if(cnt[nnz]==1)q.push(nnz);
					}
				}
			}
		}
	}
	fup(i,0,n-1,1)fup(j,0,m-1,1)if(s[i][j]=='.')return !printf("Not unique");
	fup(i,0,n-1,1)puts(s[i]);
}