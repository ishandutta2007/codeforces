#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1010;
int n,ver[N*2],edge[N*2],nxt[N*2],head[N],tot,d[N],a[N],m,tp;bool flag[N],vis[N],flagg;
struct node{
	int x,y,z;
	void print(){printf("%d %d %d\n",x,y,z);}
}ans[N*4];
void add(int x,int y,int z){
	ver[++tot]=y;edge[tot]=z;nxt[tot]=head[x];head[x]=tot;d[y]++;
}
void find(int x,int fa,int y){
	if(x==y)flagg=1;
	if(flagg&&flag[x])a[++tp]=x;
	for(int i=head[x];i;i=nxt[i]){
		if(x==y&&tp)tp=1;
		int z=ver[i];
		if(z==fa)continue;
		find(z,x,y);
	}
	if(x==y)flagg=0;
}
void solve(int x,int y,int z){
	if(flag[x]&&flag[y])ans[++m]=(node){x,y,z};
	else if(!flag[x]&&!flag[y]){
		find(x,0,y);int b=a[1],c=a[2];tp=0;
		find(y,0,x);int d=a[1],e=a[2];tp=0;
		ans[++m]=(node){b,d,z>>1};
		ans[++m]=(node){c,e,z>>1};
		ans[++m]=(node){b,c,-z/2};
		ans[++m]=(node){d,e,-z/2};
	}
	else{
		if(flag[y])swap(x,y);
		find(x,0,y);int b=a[1],c=a[2];tp=0;
		ans[++m]=(node){x,b,z>>1};
		ans[++m]=(node){x,c,z>>1};
		ans[++m]=(node){b,c,-z/2};
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y,z;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z); 
	}
	for(int i=1;i<=n;i++){
		if(d[i]==2)puts("NO"),exit(0);
		if(d[i]==1)flag[i]=1;
	}
	puts("YES");
	for(int i=1;i<=n;i++)
		for(int j=head[i];j;j=nxt[j])
			if(ver[j]>i)solve(i,ver[j],edge[j]);
	printf("%d\n",m);
	for(int i=1;i<=m;i++)ans[i].print();
	return 0;
}