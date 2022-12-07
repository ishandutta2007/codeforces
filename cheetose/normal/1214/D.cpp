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
#define INF 9876543219876543
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
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

vector<string> s;
vector<vector<bool> > chk;
int n,m;
void init(){
	fup(i,0,n-1,1)fup(j,0,m-1,1)chk[i][j]=0;
}
bool bfs(){
	init();
	queue<Pi> q;
	q.push(mp(0,0));
	chk[0][0]=1;
	while(!q.empty())
	{
		int x,y;
		tie(x,y)=q.front();
		q.pop();
		fup(i,0,1,1)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if(nx>=0 && nx<n && ny>=0 && ny<m && s[nx][ny]=='.' && !chk[nx][ny])
			{
				chk[nx][ny]=1;
				q.push(mp(nx,ny));
			}
		}
	}
	return chk[n-1][m-1];
}
vector<Vi> d;
int go(int i,int j)
{
	if(i>=n || j>=m)return 0;
	if(s[i][j]=='#')return 0;
	if(i==n-1 && j==m-1)return 1;
	int &ret=d[i][j];
	if(ret!=-1)return ret;
	return ret=max({0,go(i+1,j),go(i,j+1)});
}
int cc[2000002];
int main() {
	SYNC;
	cin>>n>>m;
	s.resize(n);
	chk.resize(n,vector<bool>(m));
	d.resize(n,Vi(m,-1));
	fup(i,0,n-1,1)cin>>s[i];
	if(!bfs())return !printf("0");
	if(n==1 || m==1)return !printf("1");
	fup(i,0,n-1,1)fup(j,0,m-1,1)
	{
		if(i==0 && j==0)continue;
		if(i==n-1 && j==m-1)continue;
		if(chk[i][j] && go(i,j)==1)cc[i+j]++;
	}
	fup(i,0,n+m-2,1)if(cc[i]==1)return !printf("1");
	return !printf("2");
}