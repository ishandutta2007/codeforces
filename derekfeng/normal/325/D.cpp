#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
const int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int r,c,n,ans,x,y;
int f[18000001],d[18000001];
bool t[18000001];
stack<pii>sta;
int F(int x){
	return x==f[x]?x:F(f[x]);
}
int id(int x,int y){
	return (x-1)*(c+c)+y;
}
void merge(int u,int v){
	u=F(u),v=F(v);
	if(u==v)return;
	if(d[u]<d[v])swap(u,v);
	sta.push({v,d[u]});
	f[v]=u,d[u]=max(d[u],f[v]+1);
}
void solve(){
	scanf("%d%d",&x,&y);
	if(t[id(x,y)])return;
	t[id(x,y)]=t[id(x,y+c)]=1;
	for(int i=0;i<8;i++){
		int xx=x+dir[i][0],yy=y+dir[i][1];
		if(yy<1)yy=c+c;
		if(yy>c+c)yy=1;
		if(1<=xx&&xx<=r&&1<=yy&&t[id(xx,yy)])
			merge(id(x,y),id(xx,yy));
	}
	for(int i=0;i<8;i++){
		int xx=x+dir[i][0],yy=y+c+dir[i][1];
		if(yy<1)yy=c+c;
		if(yy>c+c)yy=1;
		if(1<=xx&&xx<=r&&t[id(xx,yy)])
			merge(id(x,y+c),id(xx,yy));
	}
	if(F(id(x,y))!=F(id(x,y+c))){
		ans++;
		while(!sta.empty())sta.pop();
	}else{
		t[id(x,y)]=t[id(x,y+c)]=0;
		while(!sta.empty()){
			pii u=sta.top();sta.pop();
			d[f[u.fi]]=u.se,f[u.fi]=u.fi;
		}
	}
}
int main(){
	scanf("%d%d%d",&r,&c,&n);
	for(int i=1;i<=r*c+r*c;i++)f[i]=i;
	for(int i=1;i<=n;i++)solve();
	printf("%d",ans);
}