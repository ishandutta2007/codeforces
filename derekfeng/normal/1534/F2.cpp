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
bool instack[400004];
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
int a[400004],L[400004],R[400004];
int Rmax[400004];
bool flg[400004],cur[400004],era[400004];
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
	for(int i=1;i<=n*m;i++)for(auto x:g[i])if(cmp[i]!=cmp[x])G[cmp[i]].push_back(cmp[x]);
	for(int i=1;i<=t;i++)L[i]=m+1,R[i]=0;
	for(int i=1;i<=m;i++){
		scanf("%d",&x),a[i]=x;
		if(x==0)continue;
		for(int j=n;;j--)if(c[I(j,i)]=='#'){
			x--;
			if(x==0){
				flg[cmp[I(j,i)]]=1;
				break;
			}
		}
	}
	for(int i=t;i;i--){
		if(flg[i]&&cur[i])era[i]=1;
		cur[i]|=flg[i];
		for(auto x:G[i])cur[x]|=cur[i];
	}
	for(int i=1;i<=m;i++){
		x=a[i];
		if(x==0)continue;
		for(int j=n;;j--)if(c[I(j,i)]=='#'){
			x--;
			if(x==0){
				if(era[cmp[I(j,i)]]){
					a[i]=0;
				}else{
					L[cmp[I(j,i)]]=min(L[cmp[I(j,i)]],i);
					R[cmp[I(j,i)]]=max(R[cmp[I(j,i)]],i);
				}
				break;
			}
		}
	}
	for(int i=1;i<=t;i++)for(auto x:G[i])L[i]=min(L[i],L[x]),R[i]=max(R[i],R[x]);
	for(int i=1;i<=t;i++)Rmax[L[i]]=max(Rmax[L[i]],R[i]);
	int lstmax=0,curmax=0,ans=0;
	for(int i=1;i<=m;i++){
		curmax=max(curmax,Rmax[i]);
		if(lstmax<i&&a[i]>0)ans++,lstmax=curmax;
	}
	printf("%d",ans);
}