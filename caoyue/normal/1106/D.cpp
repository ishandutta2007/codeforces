#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
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
const int N=1e5+7;
const int INF=1e9+7;
int n,m,num=0;
int pos[N];
bool vis[N];
struct edge{int v,next;}e[N*2];
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
priority_queue<int,vector<int>,greater<int> >q;
 
int main(){
	scanf("%d%d",&n,&m);
	memset(pos,-1,sizeof(pos));
	rep(i,m){
		int x,y; scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	vis[1]=1;
	q.push(1);
	while(!q.empty()){
		int t=q.top();
		q.pop();
		printf("%d ",t);
		repG(i,t){
			if(!vis[e[i].v]){
				vis[e[i].v]=1;
				q.push(e[i].v);
			}
		}
	}
	puts("");
	return 0;
}