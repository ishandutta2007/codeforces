//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e5+4;
int t,T,n,m,n1=1e9,n2,l[N],r[N],c[N];
vector<int>e[N];
void dfs(int x){
	for(auto v:e[x]){
		if(!c[v]){c[v]=3-c[x];dfs(v);}
		else if(c[x]==c[v]){puts("IMPOSSIBLE");exit(0);}
	}
}
int main(){
	t=read();T=read();n=read();m=read();
	for(int i=1;i<=n;i++){
		l[i]=read();r[i]=read();
		n1=min(n1,r[i]);n2=max(n2,l[i]);
	}
	if(n1+n2<t)n2=t-n1;
	if(n1+n2>T)n1=T-n2;
	if(n1<0||n2<0){puts("IMPOSSIBLE");return (0-0);}
	for(int i=1;i<=n;i++){
		if(!(l[i]<=n1&&n1<=r[i])&&!(l[i]<=n2&&n2<=r[i])){puts("IMPOSSIBLE");return (0-0);}
		if((l[i]<=n1&&n1<=r[i])&&!(l[i]<=n2&&n2<=r[i]))c[i]=1;//
		if(!(l[i]<=n1&&n1<=r[i])&&(l[i]<=n2&&n2<=r[i]))c[i]=2;//
	}
	for(int i=1,u,v;i<=m;i++){
		u=read();v=read();
		e[u].push_back(v);e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)if(c[i])dfs(i);
	for(int i=1;i<=n;i++)if(!c[i]){c[i]=1;dfs(i);}
	cout<<"POSSIBLE\n"<<n1<<" "<<n2<<"\n";
	for(int i=1;i<=n;i++)cout<<c[i];
	return (0-0);
}