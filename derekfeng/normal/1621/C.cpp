#include<bits/stdc++.h>
using namespace std;
#define ffs fflush(stdout)
int T,n,p[10004];
bool vis[10004];
void sol(){
	scanf("%d",&n),ffs;
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1;i<=n;i++){
		int lst,x;
		printf("? %d\n",i),ffs;
		scanf("%d",&x),ffs;
		if(vis[x])continue;
		lst=x,vis[x]=1;
		for(;;){
			printf("? %d\n",i),ffs;
			scanf("%d",&x),ffs;
			p[lst]=x,lst=x;if(vis[x])break;
			vis[x]=1;
		}
	}
	printf("! ");
	for(int i=1;i<=n;i++)printf("%d ",p[i]);
	puts("");
	ffs;
}
int main(){
	scanf("%d",&T),ffs;
	while(T--)sol();
}