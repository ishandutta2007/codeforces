#include <bits/stdc++.h>
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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

char s[1001][1002];
int a[1000][1000],d[1000][1000];
int main() {
	int n,m,Q;
	scanf("%d%d%d",&n,&m,&Q);
	fup(i,0,n-1,1)scanf("%s",s[i]);
	fup(i,0,n-1,1){
		fup(j,0,m-1,1){
			bool ok=0;
			fup(ii,0,3,1){
				int nx=i+dx[ii],ny=j+dy[ii];
				if(nx>=0 && nx<n && ny>=0 && ny<m && s[i][j]==s[nx][ny])ok=1;
			}
			a[i][j]=ok;
		}
	}
	MEM_1(d);
	queue<Pi> q;
	fup(i,0,n-1,1)fup(j,0,m-1,1)if(a[i][j]==1){
		q.push(mp(i,j));
		d[i][j]=0;
	}
	while(!q.empty()){
		auto [x,y]=q.front();
		q.pop();
		fup(i,0,3,1){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx>=0 && nx<n && ny>=0 && ny<m && d[nx][ny]==-1){
				q.push(mp(nx,ny));
				d[nx][ny]=d[x][y]+1;
			}
		}
	}
	while(Q--){
		int x,y;
		ll p;
		scanf("%d%d%lld",&x,&y,&p);
		x--,y--;
		if(d[x][y]==-1)printf("%c\n",s[x][y]);
		else if(p<=(ll)d[x][y])printf("%c\n",s[x][y]);
		else{
			int t='0'+'1';
			p-=d[x][y];
			if(p&1)printf("%c\n",(char)(t-s[x][y]));
			else printf("%c\n",s[x][y]);
		}
	}
}