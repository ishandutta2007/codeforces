#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=5e5+7;
const int INF=1e9+7;
int num=0,n,m,q;
int pos[N],s[N],p[33],t[33],ans[N],dis[N];
struct edge{int v,next,c;}e[N*2];
struct wt{int l,r,q,id;}w[N];
void add(int x,int y,int z){e[num]=(edge){y,pos[x],z}; pos[x]=num++;}
void dfs(int x,int f,int c){
	dis[x]=dis[f]^c;
	repG(i,x)if(e[i].v!=f)dfs(e[i].v,x,e[i].c);
}
bool cmp(wt a,wt b){return a.r<b.r;}

int main(){
	memset(pos,-1,sizeof(pos));
	scanf("%d",&m);
	rep(i,m)scanf("%d",&s[i]);
	scanf("%d",&q);
	rep(i,q){
		int l,r; scanf("%d%d",&l,&r);
		w[i]=(wt){l,r,0,i};
	}
	sort(w+1,w+q+1,cmp);
	int now=0;
	rep(i,m){
		int hh=s[i],gg=i;
		for(int j=29;~j;j--){
			if(!(hh&(1<<j)))continue;
			if(!p[j]){p[j]=hh; t[j]=gg; break;}
			else{
				if(t[j]<gg)swap(t[j],gg),swap(p[j],hh);
				hh^=p[j];
			}
		}
		while(now<q&&w[now+1].r==i){
			now++;
			for(int j=29;~j;j--){
				if((w[now].q&(1<<j)))continue;
				if(t[j]>=w[now].l)w[now].q^=p[j];
			}
			ans[w[now].id]=w[now].q;
		}
	}
	rep(i,q)printf("%d\n",ans[i]);
	return 0;
}