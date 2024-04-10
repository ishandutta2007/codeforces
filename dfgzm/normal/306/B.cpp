#include<bits/stdc++.h>
using namespace std;
const int maxn=2000010;
int i,j,k,n,m,to[maxn],vis[maxn],id[maxn];
int main(){
	cin>>n>>m;
	for(i=1;i<=m;i++){
		int w1,w2;
		scanf("%d%d",&w1,&w2);
		if(w1+w2>to[w1])to[w1]=w1+w2-1,id[w1]=i;
	}
	for(i=1;i<=n;i++){
		if(to[i-1]>to[i])id[i]=id[i-1];
		to[i]=max(to[i-1],to[i]);
	}
	int now=1,ans=0;
	while(now<=n){
		if(to[now]+1>now){
			vis[id[now]]=1;
			now=to[now]+1;
			ans++;
		}else ++now;
	}
	cout<<m-ans<<endl;
	for(i=1;i<=m;i++)if(!vis[i])printf("%d ",i);
	return 0;
}