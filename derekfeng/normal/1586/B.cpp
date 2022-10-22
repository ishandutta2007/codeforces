#include<bits/stdc++.h>
using namespace std;
int t,n,m;
bool vis[100006];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			vis[b]=1;
		}
		int rt=-1;
		for(int i=1;i<=n;i++)if(!vis[i])rt=i;
		for(int i=1;i<=n;i++)if(i!=rt)printf("%d %d\n",i,rt);
	}
}