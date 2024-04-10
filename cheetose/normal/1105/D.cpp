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
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int n,m,p;
int a[10],cnt[10];
VPi v[10];
char s[1000][1001];
deque<iii> q;
int main() {
	scanf("%d%d%d",&n,&m,&p);
	fup(i,1,p,1)scanf("%d",a+i);
	fup(i,0,n-1,1)scanf("%s",s[i]);
	fup(i,0,n-1,1)
		fup(j,0,m-1,1)
		if(s[i][j]>='1' && s[i][j]<='9')v[s[i][j]-'0'].pb(mp(i,j));
	fup(i,1,p,1)
	{
		for(auto P:v[i])
			q.pb(iii(P.X,P.Y,a[i]));
	}
	while(!q.empty())
	{
		iii P=q.front();
		int x,y,ss;
		tie(x,y,ss)=P;
		queue<iii> Q;
		while(!q.empty() && s[get<0>(q.front())][get<1>(q.front())]==s[x][y])
		{
			Q.push(q.front());
			q.pop_front();
		}
		int t=s[x][y]-'0';
		while(!Q.empty())
		{
			int xx,yy,S;
			tie(xx,yy,S)=Q.front();
			Q.pop();
			fup(i,0,3,1)
			{
				int nx=xx+dx[i],ny=yy+dy[i];
				if(nx>=0&&nx<n&&ny>=0&&ny<m&&s[nx][ny]=='.')
				{
					s[nx][ny]=s[x][y];
					if(S==1)q.pb(iii(nx,ny,a[t]));
					else Q.push(iii(nx,ny,S-1));
				}
			}
		}
	}
	//fup(i,0,n-1,1)printf("%s\n",s[i]);
	fup(i,0,n-1,1)fup(j,0,m-1,1)if(s[i][j]>='1'&&s[i][j]<='9')cnt[s[i][j]-'0']++;
	fup(i,1,p,1)printf("%d ",cnt[i]);
}