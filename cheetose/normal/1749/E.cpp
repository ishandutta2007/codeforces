#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define COMPRESS(a) sort(ALL(a));a.resize(unique(ALL(a))-a.begin())
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
typedef vector<ld> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

string s[200005];
char tmp[200005];
VPi v[800005];
int dist[800005],p[800005];
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,0,n-1,1){
		scanf("%s",tmp);
		s[i]="#";
		s[i]+=tmp;
		s[i]+='#';
	}
	m+=2;
	fup(i,0,n*m-1,1)v[i].clear();
	fup(i,0,n*m-1,1){
		int x=i/m,y=i%m;
		for(int nx:{x-1,x+1}){
			for(int ny:{y-1,y+1}){
				if(nx<0 || nx==n)continue;
				if(ny<0 || ny==m)continue;
				if(s[nx][ny]=='#')v[x*m+y].eb(nx*m+ny,0);
				else{
					bool ok=1;
					fup(k,0,3,1){
						int nnx=nx+dx[k],nny=ny+dy[k];
						if(nny>=1 && nnx>=0 && nnx<n && nny<m-1 && s[nnx][nny]=='#')ok=0;
					}
					if(ok)v[x*m+y].eb(nx*m+ny,1);
				}
			}
		}
	}
	fill(dist,dist+n*m,INF);
	deque<int> q;
	fup(i,0,n-1,1){
		dist[i*m]=0;
		q.pb(i*m);
	}
	while(!q.empty()){
		int x=q.front();
		q.pop_front();
		for(auto [next,c]:v[x]){
			if(dist[next]>dist[x]+c){
				dist[next]=dist[x]+c;
				if(c==0)q.push_front(next);
				else q.push_back(next);
				p[next]=x;
			}
		}
	}
	int t=-1;
	fup(i,0,n-1,1){
		if(t==-1 || dist[t]>dist[i*m+m-1])t=i*m+m-1;
	}
	if(dist[t]==INF)puts("NO");
	else{
		puts("YES");
		while(t%m){
			s[t/m][t%m]='#';
			t=p[t];
		}
		fup(i,0,n-1,1){
			fup(j,1,m-2,1)printf("%c",s[i][j]);
			puts("");
		}
	}
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}