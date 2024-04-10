#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321987654321
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
typedef pair<db, db> Pd;
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
const int MOD = 1000000021;
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

Vi v[300001];
bool chk[300001];
int col[300001];
void bfs(int N){
	queue<int> q;
	q.push(N);
	chk[N]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int next:v[x]){
			if(!chk[next]){
				chk[next]=1;
				q.push(next);
			}
		}
	}
}
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,1,n,1)v[i].clear(),chk[i]=0,col[i]=-1;
	fup(i,1,m,1){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	int cc=0;
	fup(i,1,n,1){
		if(!chk[i]){
			cc++;
			bfs(i);
		}
	}
	if(cc!=1){
		puts("NO");
		return;
	}
	puts("YES");
	queue<int> q;
	q.push(1);
	col[1]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int next:v[x]){
			if(col[next]!=-1)continue;
			col[next]=1;
			for(int j:v[next]){
				if(col[j]==1)col[next]=0;
			}
			q.push(next);
		}
	}
	Vi ans;
	fup(i,1,n,1)if(col[i]==1)ans.pb(i);
	printf("%d\n",ans.size());
	for(int x:ans)printf("%d ",x);
		puts("");
}
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}