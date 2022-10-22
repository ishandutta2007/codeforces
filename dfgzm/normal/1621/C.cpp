#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=500005;
int T,n,ans,vs;
int p[maxn],stp[maxn],v[maxn],vis[maxn],nxt[maxn],q[maxn];
string s; 
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0,scanf("%d",&n); 
		int tot=-1;
		for(int i=1,x,y;i<=n;i++){
			if(nxt[i])
				continue;
			printf("? %d\n",i),fflush(stdout),scanf("%d",&x),stp[x]=tot,tot++;
			printf("? %d\n",i),fflush(stdout),scanf("%d",&y),tot++,nxt[x]=y;
			while(nxt[y]==0)
				x=y,printf("? %d\n",i),fflush(stdout),scanf("%d",&y),tot++,nxt[x]=y;
		}
		for(int i=1;i<=n;i++){
			if(p[i])
				continue;
			vs=0;
			int now=0;
			for(int j=i;vis[j]==0;j=nxt[j]){
				vis[j]=1,v[vs++]=j;
				if(stp[j])
					now=j;
			}
			int t=(stp[now]%vs+vs)%vs;
			p[now]=v[t];
			for(int j=1;j<vs;j++)
				now=nxt[now],p[now]=v[(t+j)%vs];
		}
		for(int i=1;i<=n;i++)
			q[p[i]]=i;
		printf("! ");
		for(int i=1;i<=n;i++)
			printf("%d%c",q[i],i==n? '\n':' '),vis[i]=stp[i]=nxt[i]=p[i]=0;
		fflush(stdout);
	}
	return 0;
}