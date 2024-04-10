#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
int n;
int vis[1111],a[1111],b[1111];int p[1111],pos[1111],pc;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	
	for(int i=1;i<=n;i++)if(a[i]!=b[i])pos[++pc]=i;
	if(pc==1){
		for(int i=1;i<pos[1];i++)vis[a[i]]=1;
		for(int i=pos[1]+1;i<=n;i++)vis[a[i]]=1;
		for(int i=1;i<=n;i++)if(!vis[i])a[pos[1]]=i;
		for(int i=1;i<=n;i++)printf("%d ",a[i]);
	}else if(pc==2){
		memcpy(p,a,sizeof(a));
		p[pos[1]]=a[pos[1]],p[pos[2]]=b[pos[2]];
		for(int i=1;i<=n;i++)vis[p[i]]=1;
		bool flg=true;
		for(int i=1;i<=n;i++)if(!vis[i]){flg=false;break;}
		if(flg){for(int i=1;i<=n;i++)printf("%d ",p[i]);}
		else{
			p[pos[1]]=b[pos[1]],p[pos[2]]=a[pos[2]];for(int i=1;i<=n;i++)printf("%d ",p[i]);
		}
	}
	return 0;
}