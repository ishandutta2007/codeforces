#include <bits/stdc++.h>
using namespace std;
int n,m,N,u,v,D;
int cnt,head[500005],to[2000005],nxt[2000005];
void add(int f,int t){
	nxt[++cnt]=head[f],to[cnt]=t,head[f]=cnt;
}
stack<int>st;
bool vis[500005],ins[500005];
int cnt1,head1[250005],to1[500005],nxt1[500005]; 
void add1(int f,int x){
	nxt1[++cnt1]=head1[f],to1[cnt1]=x,head1[f]=cnt1;
}
bool dfs(int x,int p,int dep){
	D=max(D,dep);
	vis[x]=ins[x]=1;
	st.push(x);
	if(dep==N){
		printf("PATH\n%d\n",N);
		while(!st.empty())printf("%d ",st.top()),st.pop();
		puts("");
		return 1;
	}
	add1(dep,x);
	for(int i=head[x];i;i=nxt[i])if(!vis[to[i]])
		if(dfs(to[i],x,dep+1))return 1;
	st.pop(),ins[x]=0;
	return 0;
}
int ans[500004],ret;
void sol(){
	scanf("%d%d",&n,&m),N=(n+1)/2;
	cnt=cnt1=D=ret=0;
	for(int i=1;i<=n;i++)head[i]=head1[i]=vis[i]=ins[i]=0;
	while(m--)scanf("%d%d",&u,&v),add(u,v),add(v,u);
	if(!dfs(1,0,1)){
		for(int i=1;i<=D;i++){
			for(int j=head1[i];j;){
				if(!nxt1[j])break;
				int jj=nxt1[j];
				ans[++ret]=to1[j],ans[++ret]=to1[jj];
				j=nxt1[jj];
			}
		}
		printf("PAIRING\n%d\n",ret/2);
		for(int i=1;i<=ret;i+=2)printf("%d %d\n",ans[i],ans[i+1]);
		puts("");
	}
}
int T;
int main(){
	scanf("%d",&T);
	while(T--)sol();
}