//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=10004;
int n,p=1,a[N],vis[N];
inline int query(int i,int j){
	cout<<"? "<<i<<" "<<j<<"\n";
	fflush(stdout);
	return read();
}
int main(){
	n=read();
	for(int i=2,u,v;i<=n;i++){
		u=query(p,i);v=query(i,p);
		if(u>v){a[p]=u;p=i;}
		else a[i]=v;
		vis[max(u,v)]=1;
	}	
	for(int i=1;i<=n;i++)if(!vis[i]){a[p]=i;break;}
	cout<<"! ";
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	return (0-0);
}