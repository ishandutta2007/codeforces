#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
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
const int MAXN=2010,nxtx[4]={0,0,-1,1},nxty[4]={-1,1,0,0};
int T,n,m,pre[MAXN][MAXN];
char a[MAXN][MAXN];
int d[MAXN][MAXN];
bitset<MAXN>vis[MAXN],ins[MAXN],tag[MAXN];
il int valid(int x,int y){return x>=1 && x<=n && y>=1 && y<=m;}
void solve(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m){
		char tmp;scanf(" %c",&tmp);
		if(tmp=='L')a[i][j]=0;
		else if(tmp=='R')a[i][j]=1;
		else if(tmp=='U')a[i][j]=2;
		else a[i][j]=3;
	}
	rep(i,1,n)rep(j,1,m)vis[i][j]=ins[i][j]=d[i][j]=tag[i][j]=0;
	// 
	rep(i,1,n)rep(j,1,m){if(vis[i][j])continue; 
		int x=i,y=j,sx=-1,sy=-1,ex=-1,ey=-1,cx,cy;
	//	printf("new %d %d",x,y);
		while(1){
			vis[x][y]=1;ins[x][y]=1;
			int cx=x+nxtx[a[x][y]],cy=y+nxty[a[x][y]];
		//	printf("(%d,%d)->(%d,%d)\n",x,y,cx,cy);
			if(!valid(cx,cy))break;
			if(vis[cx][cy] && !ins[cx][cy])break;
			if(ins[cx][cy]){
				sx=cx,sy=cy;ex=x;ey=y;
				break;
			}
			x=cx;y=cy;
		}
		x=i,y=j;
		while(1){
			ins[x][y]=0;
			int cx=x+nxtx[a[x][y]],cy=y+nxty[a[x][y]];
			if(!valid(cx,cy))break;
			if(vis[cx][cy] && !ins[cx][cy])break;
			x=cx;y=cy;
		}
		//printf("ring:(%d,%d)->(%d,%d)\n",sx,sy,ex,ey);
		if(sx==-1)continue;
		//(sx,sy)->(ex,ey)->(sx,sy)
		int cnt=0;
		x=sx,y=sy;
		while(1){
			cnt++;tag[x][y]=1;
			if(x==ex && y==ey)break;
			int cx=x+nxtx[a[x][y]],cy=y+nxty[a[x][y]];
			x=cx;y=cy;
		}
		x=sx,y=sy;
		while(1){
			d[x][y]=cnt;
			if(x==ex && y==ey)break;
			int cx=x+nxtx[a[x][y]],cy=y+nxty[a[x][y]];
			x=cx;y=cy;
		}
	}
	rep(i,1,n)rep(j,1,m){
		vis[i][j]=0;
	}
	rep(i,1,n)rep(j,1,m){
		if(vis[i][j] || tag[i][j])continue;
		int x=i,y=j,ex,ey,cx,cy;
		while(1){
			int cx=x+nxtx[a[x][y]],cy=y+nxty[a[x][y]];
			pre[cx][cy]=(x-1)*m+y;
			if(!valid(cx,cy)){
				ex=x;ey=y;
				break;
			}
			if(vis[cx][cy] || tag[cx][cy]){
				ex=x;ey=y;
				break;
			}
			x=cx;y=cy;
		}
		cx=ex+nxtx[a[ex][ey]],cy=ey+nxty[a[ex][ey]];
		if(!valid(cx,cy))d[ex][ey]=1;
		else d[ex][ey]=d[cx][cy]+1;
		while(1){
			vis[ex][ey]=1;
			if(ex==i && ey==j)break;
			cx=(pre[ex][ey]-1)/m+1;cy=(pre[ex][ey]-1)%m+1;
			d[cx][cy]=d[ex][ey]+1;
			ex=cx;ey=cy;
		}
	}	
	int x=0,y=0;
	rep(i,1,n)rep(j,1,m)if(d[x][y]<d[i][j])x=i,y=j;
	printf("%d %d %d\n",x,y,d[x][y]);
}
int main(){
	scanf("%d",&T);
	while(T--){
		solve();
	}

	return 0;
}