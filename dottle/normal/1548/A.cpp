#include<bits/stdc++.h>
const int N=200050;
using namespace std;

int cnt[N],a[N],ans,n,m,q,x,y,z;

void add(int x,int y){
	if(a[x]<a[y])ans+=!cnt[x],cnt[x]++;
	else ans+=!cnt[y],cnt[y]++;
}
void del(int x,int y){
	if(a[x]<a[y])cnt[x]--,ans-=!cnt[x];
	else cnt[y]--,ans-=!cnt[y];
}

main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		a[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d%d",&x,&y),add(x,y);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d",&z);
		if(z==1)scanf("%d%d",&x,&y),add(x,y);
		if(z==2)scanf("%d%d",&x,&y),del(x,y);
		if(z==3)printf("%d\n",n-ans);
	}
}