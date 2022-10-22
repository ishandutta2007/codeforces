#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,k,T;
int p[maxn],vis[maxn];
inline void add(int a,int b){
	p[a]=b,p[b]=a;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		if(n==4&&k==3){
			puts("-1");
			continue;
		}
		for(int i=0;i<n;i++)
			p[i]=n-1-i;
		if(k==n-1)
			add(1,3),add(n-1,n-2),add(0,n-4);
		else add(n-1,k),add(0,n-1-k);
		for(int i=0;i<n;i++)
			if(vis[i]==0)
				vis[i]=vis[p[i]]=1,printf("%d %d\n",i,p[i]);
		for(int i=0;i<n;i++)
			p[i]=vis[i]=0;
	}
	return 0;
}