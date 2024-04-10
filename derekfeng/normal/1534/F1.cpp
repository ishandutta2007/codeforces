#include<bits/stdc++.h>
using namespace std;
const int d[3][2]={{0,1},{0,-1},{-1,0}};
int n,m,x;
vector<int>g[400004],G[400004];
char c[400004];
int I(int i,int j){
	return (i-1)*m+j;
}
int cmp[400004],cnt,low[400004],vis[400004],t;
stack<int>st;
bool instack[400004],fal[400004],cur[400004];
void tarjan(int x){
	vis[x]=low[x]=++cnt;
	st.push(x),instack[x]=1; 
	for(auto y:g[x]){
		if(!vis[y])tarjan(y);
		if(instack[y])low[x]=min(low[x],low[y]);
	}
	if(vis[x]==low[x]){
		t++;
		while(st.top()!=x)cmp[st.top()]=t,instack[st.top()]=0,st.pop();
		st.pop(),cmp[x]=t,instack[x]=0;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",c+1+(i-1)*m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(c[I(i,j)]=='#'){
		for(int k=i;k<=n;k++){
			if(c[I(k,j)]=='#'&&k>i){
				g[I(i,j)].push_back(I(k,j));
				break; 
			}
			for(int l=0;l<3;l++){
				int ii=k+d[l][0],jj=j+d[l][1];
				if(ii&&jj&&ii<=n&&jj<=m&&c[I(ii,jj)]=='#')g[I(i,j)].push_back(I(ii,jj));
			}
		}
	}
	for(int i=1;i<=n*m;i++)if(!vis[i])tarjan(i);
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		if(x==0)continue;
		for(int j=n;;j--)if(c[I(j,i)]=='#'){
			x--;if(x==0){fal[cmp[I(j,i)]]=1;break;}
		}
	}
	for(int i=1;i<=n*m;i++)for(auto x:g[i])if(cmp[i]!=cmp[x])G[cmp[i]].push_back(cmp[x]);
	int ans=0;
	for(int i=t;i;i--){
		if(fal[i]&&!cur[i])++ans,cur[i]=1;
		for(auto y:G[i])cur[y]=1;
	}
	printf("%d",ans);
}