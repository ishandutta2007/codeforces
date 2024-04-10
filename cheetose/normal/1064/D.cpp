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

bool chk[2000][2000];
char s[2000][2001];
struct node{
	int x,y,l,r;
	node(int x_,int y_,int l_,int r_)
	{
		x=x_,y=y_,l=l_,r=r_;
	}
};
int main() {
	int n,m,x,y,l,r;
	scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&l,&r);
	x--,y--;
	fup(i,0,n-1,1)scanf("%s",s[i]);
	deque<node> q;
	q.pb(node(x,y,l,r));
	chk[x][y]=1;
	while(!q.empty())
	{
		node N=q.front();
		int x,y,l,r;
		q.pop_front();
		x=N.x,y=N.y,l=N.l,r=N.r;
		int nx=x+1,ny=y;
		if(nx<n && s[nx][ny]=='.' && !chk[nx][ny])
		{
			chk[nx][ny]=1;
			q.push_front(node(nx,ny,l,r));
		}
		nx-=2;
		if(nx>=0 && s[nx][ny]=='.' && !chk[nx][ny])
		{
			chk[nx][ny]=1;
			q.push_front(node(nx,ny,l,r));
		}
		nx++;
		ny--;
		if(ny>=0 && s[nx][ny]=='.' && l>0 && !chk[nx][ny])
		{
			chk[nx][ny]=1;
			q.push_back(node(nx,ny,l-1,r));
		}
		ny+=2;
		if(ny<m && s[nx][ny]=='.' && r>0 && !chk[nx][ny])
		{
			chk[nx][ny]=1;
			q.push_back(node(nx,ny,l,r-1));
		}
	}
	int ans=0;
	fup(i,0,n-1,1)fup(j,0,m-1,1)if(chk[i][j])ans++;
	printf("%d",ans);
}