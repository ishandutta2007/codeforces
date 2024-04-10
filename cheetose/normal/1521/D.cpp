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

Vi v[100005];
int d[100005][2],col[100005];
void dfs(int N,int p=-1){
	if(p!=-1 && v[N].size()==1){
		d[N][0]=0,d[N][1]=1;
		return;
	}
	int m1=0,m2=0;
	int s=0;
	for(int next:v[N]){
		if(next==p)continue;
		dfs(next,N);
		s+=d[next][0];
		int t=d[next][1]-d[next][0];
		if(t>m1){
			m2=m1;
			m1=t;
		}else if(t>m2){
			m2=t;
		}
	}
	d[N][0]=s+m1+m2;
	d[N][1]=s+m1+1;
}
VPi V;
Vi vv[100005];
int p[100005],cnt[100005];
int f(int x){return p[x]==x?x:p[x]=f(p[x]);}
void merge(int x,int y){p[f(x)]=f(y);}
void dfs2(int N,int p=-1){
	if(p!=-1 && v[N].size()==1)return;
	Pi m1,m2;
	int s=0;
	for(int next:v[N]){
		if(next==p)continue;
		s+=d[next][0];
		col[next]=0;
		Pi t=mp(d[next][1]-d[next][0],next);
		if(t>m1){
			m2=m1;
			m1=t;
		}else if(t>m2){
			m2=t;
		}
	}
	col[m1.Y]=1;
	if(!col[N])col[m2.Y]=1;
	for(int next:v[N]){
		if(next==p)continue;
		if(col[next]){
			cnt[N]++,cnt[next]++;
			merge(N,next);
		}else{
			V.pb(mp(N,next));
		}
		dfs2(next,N);
	}
}
void solve(){
	V.clear();
	int n;
	scanf("%d",&n);
	fup(i,1,n,1){
		v[i].clear();
		vv[i].clear();
		cnt[i]=0;
		p[i]=i;
	}
	fup(i,1,n-1,1){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1);
	d[1][1]--;
	printf("%d\n",n-1-max(d[1][0],d[1][1]));
	if(d[1][1]>=d[1][0])col[1]=1;
	else col[1]=0;
	dfs2(1);
	fup(i,1,n,1){
		vv[f(i)].pb(i);
	}
	VPi tmp;
	fup(i,1,n,1){
		if(vv[i].empty())continue;
		if(vv[i].size()==1)tmp.pb(mp(i,i));
		else{
			Pi P;
			for(int x:vv[i]){
				if(cnt[x]!=1)continue;
				if(P.X==0)P.X=x;
				else P.Y=x;
			}
			tmp.pb(P);
		}
	}
	assert(tmp.size()==V.size()+1);
	fup(i,0,(int)V.size()-1,1){
		printf("%d %d %d %d\n",V[i].X,V[i].Y,tmp[i].Y,tmp[i+1].X);
	}
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}