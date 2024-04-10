#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const ll MAXN=2e3+10,INF=1e18,nextx[4]={0,1,0,-1},nexty[4]={1,0,-1,0};
int n,m,w,a[MAXN][MAXN];
ll dis[2][MAXN][MAXN],ans;
queue<pi>q;
int valid(int x,int y){
	return (x>=1) && (x<=n) && (y>=1) && (y<=m);
}
int main(){
	scanf("%d%d%d",&n,&m,&w);
	rep(i,1,n){
		rep(j,1,m){
			scanf("%d",&a[i][j]);
		}
	}
	rep(i,1,n){
		rep(j,1,m){
			dis[0][i][j]=dis[1][i][j]=INF;
		}
	}
	dis[0][1][1]=0;
	q.push(mp(1,1));
	while(q.size()){
		int x=q.front().fr,y=q.front().se;q.pop();
		rep(k,0,3){
			int cx=x+nextx[k],cy=y+nexty[k];
			if(valid(cx,cy) && a[cx][cy]!=-1 && dis[0][cx][cy]>dis[0][x][y]+w){
				dis[0][cx][cy]=dis[0][x][y]+w;
				q.push(mp(cx,cy));
			}
		}
	}
	dis[1][n][m]=0; 
	q.push(mp(n,m));
	while(q.size()){
		int x=q.front().fr,y=q.front().se;q.pop();
		rep(k,0,3){
			int cx=x+nextx[k],cy=y+nexty[k];
			if(valid(cx,cy) && a[cx][cy]!=-1 && dis[1][cx][cy]>dis[1][x][y]+w){
				dis[1][cx][cy]=dis[1][x][y]+w;
				q.push(mp(cx,cy));
			}
		}
	}
	ans=dis[0][n][m];
	ll min1=INF,min2=INF;
	rep(i,1,n){
		rep(j,1,m){
			if(a[i][j]<=0)continue;
			min1=min(min1,a[i][j]+dis[0][i][j]);
			min2=min(min2,a[i][j]+dis[1][i][j]);
		}
	}
	ans=min(ans,min1+min2);
	if(ans==INF)printf("-1\n");
	else printf("%lld\n",ans); 
	return 0;
}