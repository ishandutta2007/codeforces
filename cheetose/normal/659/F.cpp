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

map<ll,Vi> M;
int n,m;
ll k;
ll a[1000][1000],ans[1000][1000];
int parent[1000000];
int find(int a)
{
	if (parent[a] < 0)return a;
	return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a != b)
	{
		parent[a] += parent[b];
		parent[b] = a;
	}
}
inline int sz(int z){return -parent[find(z)];}
int main() {
	MEM_1(parent);
	scanf("%d%d%lld",&n,&m,&k);
	fup(i,0,n-1,1)fup(j,0,m-1,1)
	{
		scanf("%lld",&a[i][j]);
		M[a[i][j]].pb(i*m+j);
	}
	auto it=M.end();
	while(1)
	{
		it--;
		for(int z:it->Y)
		{
			int x=z/m,y=z%m;
			fup(i,0,3,1)
			{
				int nx=x+dx[i],ny=y+dy[i];
				if(nx>=0 && nx<n&&ny>=0&&ny<m&&a[nx][ny]>=a[x][y])
					merge(z,nx*m+ny);
			}
			if(k%it->X==0 && sz(z)>=k/it->X)
					{
						puts("YES");
						ll r=it->X,rem=k/it->X-1;
						ans[x][y]=r;
						queue<Pi> q;
						q.push(mp(x,y));
						while(!q.empty())
						{
							int xx,yy;
							tie(xx,yy)=q.front();
							q.pop();
							fup(i,0,3,1)
							{
								int nxx=xx+dx[i],nyy=yy+dy[i];
								if(nxx>=0&&nxx<n&&nyy>=0&&nyy<m&&!ans[nxx][nyy]&&a[nxx][nyy]>=r&&rem>0)
								{
									rem--;
									ans[nxx][nyy]=r;
									q.push(mp(nxx,nyy));
								}
							}
						}
						fup(i,0,n-1,1)
						{
							fup(j,0,m-1,1)
								printf("%lld ",ans[i][j]);
							puts("");
						}
						return 0;
					}
		}
		if(it==M.begin())break;
	}
	puts("NO");
}