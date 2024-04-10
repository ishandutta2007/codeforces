#include<bits/stdc++.h>
using namespace std;
const int S=5e5+5;
int fir[S],l[S],to[S],n,ec,sz[S],son[S],ans[S],b[1<<22],sta[S],top,V[S],Xor,dep[S];
char s[S];
void link(int a,int b){l[++ec]=fir[a];fir[a]=ec;to[ec]=b;}
void dfs(int p){
	sz[p]=1;
	for(int i=fir[p],y;y=to[i];i=l[i]){
		dep[y]=dep[p]+1; dfs(y);sz[p]+=sz[y];
		if(sz[y]>sz[son[p]])son[p]=y;
	}
}
void ask(int s,int c,int v){s^=Xor;
	ans[c]=max(ans[c],b[s]+v-dep[c]-dep[c]);
	for(int i=0;i<22;++i)ans[c]=max(ans[c],b[s^1<<i]+v-dep[c]-dep[c]);
}
void Dfs(int p,int c,int t){
	ask(t,c,dep[p]);
	for(int i=fir[p],y;y=to[i];i=l[i])Dfs(y,c,t^1<<s[y]);
}
void DFs(int p,int c,int t){
	if(b[Xor^t]<dep[p])sta[++top]=Xor^t,V[top]=b[t^Xor],b[t^Xor]=dep[p];
	for(int i=fir[p],y;y=to[i];i=l[i])DFs(y,c,t^1<<s[y]);
}
void DFS(int p){
	for(int i=fir[p],y;y=to[i];i=l[i])if(y!=son[p]){
		DFS(y); ans[p]=max(ans[p],ans[y]);
		while(top)b[sta[top]]=V[top],top--;
	}
	if(son[p])DFS(son[p]),ans[p]=max(ans[p],ans[son[p]]),Xor^=1<<s[son[p]];
	for(int i=fir[p],y;y=to[i];i=l[i])if(y!=son[p])Dfs(y,p,1<<s[y]),DFs(y,p,1<<s[y]);
	ask(0,p,dep[p]);
	if(b[Xor]<dep[p])sta[++top]=Xor,V[top]=b[Xor],b[Xor]=dep[p];
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<1<<22;++i)b[i]=-S;
	for(int i=2,f;i<=n;++i)scanf("%d%s",&f,s+i),link(f,i),s[i]-='a';
	dfs(1); DFS(1);
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
}