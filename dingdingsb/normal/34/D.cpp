#include<bits/stdc++.h>
using namespace std;
int cnt=0,n,r1,r2;
const int maxn=5e4+10;
struct E{
	int v;
	int nxt;
}edge[2*maxn];
int head[maxn];
inline void add(int u,int v){
	cnt++;
	edge[cnt].v=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
#define TP int
inline TP read(){
	TP x=0;char c=getchar();bool k=false;
	for(;!isdigit(c);c=getchar())k|=c=='-';
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+c-'0';
	if(k)x=-x;return x;
}
void write(TP x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
int fa[maxn];
signed main(){
	n=read();r1=read();r2=read();
	for(int i=1;i<=n;i++){
		if(i==r1)continue;
		int u=i,v=read();
		add(u,v),add(v,u);
	}
	queue<int>q;
	q.push(r2);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=edge[i].nxt)
			if(!fa[edge[i].v]){
				fa[edge[i].v]=u;
				q.push(edge[i].v);
			}
	}
	for(int i=1;i<=n;i++)
		if(i!=r2)
			printf("%d ",fa[i]);
}