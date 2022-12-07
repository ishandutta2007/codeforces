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
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int Ex,Ey;
int a[300][300],d[300][300],t[300][300];
VPi v[90001];
inline int dist(int x1,int y1,int x2,int y2){return abs(x1-x2)+abs(y1-y2);}
int main() {
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	fup(i,0,n-1,1)
		fup(j,0,m-1,1)
	{
		d[i][j]=INF;
		scanf("%d",a[i]+j);
		if(a[i][j]==1)d[i][j]=i+j;
		if(a[i][j]==p)Ex=i,Ey=j;
		v[a[i][j]].pb(mp(i,j));
	}
	fup(i,2,p,1)
	{
		int N=v[i-1].size(),M=v[i].size();
		if(N*M<=n*m)
		{
			fup(ii,0,N-1,1)
			{
				int x1,y1;
				tie(x1,y1)=v[i-1][ii];
				fup(j,0,M-1,1)
				{
					int x2,y2;
					tie(x2,y2)=v[i][j];
					d[x2][y2]=min(d[x2][y2],d[x1][y1]+dist(x1,y1,x2,y2));
				}
			}
		}
		else
		{
			MEM_1(t);
			queue<iii> q;
			Viii V;
			fup(ii,0,N-1,1)
			{
				int x,y;
				tie(x,y)=v[i-1][ii];
				V.pb(iii(d[x][y],x,y));
			}
			sort(ALL(V));
			q.push(V[0]);
			t[get<1>(V[0])][get<2>(V[0])]=get<0>(V[0]);
			int j=1;
			while(!q.empty())
			{
				int z,x,y;
				tie(z,x,y)=q.front();
				q.pop();
				while(j<N && get<0>(V[j])<=z)q.push(V[j++]);
				fup(i,0,3,1)
				{
					int nx=x+dx[i],ny=y+dy[i];
					if(nx>=0 && nx<n && ny>=0 && ny<m && t[nx][ny]==-1)
					{
						t[nx][ny]=z+1;
						q.push(iii(t[nx][ny],nx,ny));
					}
				}
			}
			fup(ii,0,M-1,1)
			{
				int x,y;
				tie(x,y)=v[i][ii];
				d[x][y]=t[x][y];
			}
		}
	}
	printf("%d",d[Ex][Ey]);
}