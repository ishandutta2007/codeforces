//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=2e5+4;
int n,h[N],z[N],c[N];
vector<int>e[N];
void dfs(int x){for(auto v:e[x])if(!c[v]){c[v]=3-c[x];dfs(v);}}
int main(){
	n=read();
	for(int i=1,x,y;i<=n;i++){
		x=read();y=read();
		if(h[x]){e[h[x]].push_back(i);e[i].push_back(h[x]);h[x]=0;}
		else h[x]=i;
		if(z[y]){e[z[y]].push_back(i);e[i].push_back(z[y]);z[y]=0;}
		else z[y]=i;
	}
	for(int i=1;i<=n;i++)if(!c[i]){c[i]=1;dfs(i);}
	for(int i=1;i<=n;i++)putchar((c[i]==1)?'b':'r');
	return (0-0);
}