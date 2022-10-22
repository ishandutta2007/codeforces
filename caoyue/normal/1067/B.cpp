#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
#include<vector>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=1e5+7;
const int INF=1e9+7;
int pos[N],dis[N],dg[N];
struct edge{int v,next;}e[N*2];
int n,num=0,k;
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
queue<int>q;

int main(){
	memset(pos,-1,sizeof(pos));
	scanf("%d%d",&n,&k);
	rep(i,n-1){
		int x,y; scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
		dg[x]++; dg[y]++;
	}
	memset(dis,120,sizeof(dis));
	rep(i,n)if(dg[i]==1)dis[i]=0,q.push(i);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		repG(i,t){
			if(dis[e[i].v]>dis[t]+1){
				dis[e[i].v]=dis[t]+1;
				q.push(e[i].v);
			}
		}
	}
	rep(i,n){
		int x1=0,s1=0;
		repG(j,i){
			if(dis[e[j].v]==dis[i]){
				printf("No\n");
				return 0;
			}
			if(dis[e[j].v]==dis[i]-1)x1++;else s1++;
		}
		if(dis[i]!=k&&s1!=1){printf("No\n"); return 0;}
		if(dis[i]&&x1<3){printf("No\n"); return 0;}
	}
	printf("Yes\n");
	return 0;
}