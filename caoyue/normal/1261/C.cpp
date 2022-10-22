#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=1e6+7;
const int INF=1e9+7;
int xx[8]={1,1,1,0,-1,-1,-1,0},yy[8]={1,0,-1,-1,-1,0,1,1};
int n,m,hd=0,ti=0;
vector<int>a[N],p[N],dis[N];
char s[N];
int Qux[N*5],Quy[N*5];
void bfs(){
	while(hd!=ti){
		int tx=Qux[++hd],ty=Quy[hd];
		rep0(j,8){
			if(tx+xx[j]<0||tx+xx[j]>n+1)continue;
			if(ty+yy[j]<0||ty+yy[j]>m+1)continue;
			if(dis[tx+xx[j]][ty+yy[j]]>dis[tx][ty]+1){
				dis[tx+xx[j]][ty+yy[j]]=dis[tx][ty]+1;
				Qux[++ti]=tx+xx[j];
				Quy[ti]=ty+yy[j];
			}
		}
	}
}
bool check(int x){
	rep0(i,n+1)rep0(j,m+1)p[i][j]=0;
	rep(i,n){
		rep(j,m){
			if(dis[i][j]>=x){
				if(i-x+1<=0)return 0;
				if(i+x-1>n)return 0;
				if(j-x+1<=0)return 0;
				if(j+x-1>m)return 0;
				p[i-x+1][j-x+1]++;
				p[i-x+1][j+x]--;
				p[i+x][j-x+1]--;
				p[i+x][j+x]++;
			}
		}
	}
	rep(i,n){
		rep(j,m){
			p[i][j]=p[i][j]+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
			if(!p[i][j]&&a[i][j])return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,m){
		Qux[++ti]=0;
		Quy[ti]=i;
		Qux[++ti]=n+1;
		Quy[ti]=i;
	}
	rep0(i,n+2)rep0(j,m+2)dis[i].push_back(0);
	rep0(i,n+2)rep0(j,m+2)p[i].push_back(0);
	rep(i,n){
		scanf("%s",s+1);
		a[i].push_back(0);
		Qux[++ti]=i;
		Quy[ti]=0;
		Qux[++ti]=i;
		Quy[ti]=m+1;
		rep(j,m){
			if(s[j]=='X'){
				a[i].push_back(1);
				dis[i][j]=INF;
			}
			else {
				a[i].push_back(0);
				Qux[++ti]=i;
				Quy[ti]=j;
			}
		}
	}
	bfs();
	int l=1,r=(min(n,m)+1)/2;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	int ans;
	if(check(r))ans=r;
	else ans=l;
	check(ans);
	printf("%d\n",ans-1);
	rep(i,n){
		rep(j,m)if(dis[i][j]>=ans)putchar('X');else putchar('.');
		puts("");
	}
	return 0;
}