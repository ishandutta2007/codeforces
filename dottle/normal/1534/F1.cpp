#include<bits/stdc++.h>
#define _to e[i].to
const int N=5000008;
using namespace std;

int n,m,a[N],ans,dfn[N],low[N],s[N],t,c,b[N],res;
char C[N];
struct edge{
	int fr,to,nx;
}e[N];int hd[N],S,in[N];
void add(int fr,int to){
	if(to<=n*m)
	e[++S]=(edge){fr,to,hd[fr]},hd[fr]=S;
}int pos(int x,int y){
	if(!x||!y||x>n||y>m)return n*m+1;
	return (x-1)*m+y;
}

void tarjan(int k){
	dfn[k]=low[k]=++c,s[t++]=k,in[k]=1;
	for(int i=hd[k];i;i=e[i].nx)
		if(!dfn[_to])
			tarjan(_to),low[k]=min(low[k],low[_to]);
		else if(in[_to])low[k]=min(low[k],dfn[_to]);
	if(dfn[k]==low[k]&&++ans)
		while(s[t]!=k)
			--t,b[s[t]]=ans,in[s[t]]=0;
}

int main(){
	scanf("%d%d",&n,&m); 
	for(int i=1;i<=n;i++){
		scanf("%s",C);
		for(int j=1;j<=m;j++)
			if(C[j-1]=='#')a[pos(i,j)]=1;
	}
	for(int j=1;j<=m;j++){
		int pr0=0,pr1=0,pr2=0;
		for(int i=n;i;i--){
			if(a[pos(i,j-1)])pr0=i;
			if(a[pos(i,j+1)])pr2=i;
			if(a[pos(i,j)]){
				if(a[pos(i-1,j)])add(pos(i,j),pos(i-1,j));
				add(pos(i,j),pos(pr0,j-1)),pr0=0;
				add(pos(i,j),pos(pr1,j));
				add(pos(i,j),pos(pr2,j+1)),pr2=0;
				pr1=i;
			}
		} 
	}
	for(int i=1;i<=n*m;i++)if(a[i]&&!dfn[i])tarjan(i);
	for(int i=1;i<=S;i++)if(b[_to]!=b[e[i].fr])in[b[_to]]++;
	for(int i=1;i<=ans;i++)if(!in[i])res++;
	printf("%d",res);
}