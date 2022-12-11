#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+50;
int n,ver[N*2],nxt[N*2],head[N],tot,s[N],d[N];LL ans,anss;
void add(int x,int y){
	ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;
}
void dfs1(int x,int fa){
	s[x]=1;d[x]=d[fa]+1;
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(y==fa)continue;
		dfs1(y,x);
		s[x]+=s[y];
	}
}
void dfs2(int x,int fa){
	LL lans=ans;
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(y==fa)continue;
		ans+=(n-s[y])-s[y];
		anss=max(ans,anss);
		dfs2(y,x);
		ans=lans;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	dfs1(1,0);
	for(int i=1;i<=n;i++)ans+=d[i];anss=ans;
	dfs2(1,0);
	cout<<anss;
	return 0;
}