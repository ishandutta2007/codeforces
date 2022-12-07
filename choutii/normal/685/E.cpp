#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,q,dis[3000][3000],u[220000],v[220000];
bool ans[220000]={};
struct node{
	int l,r,s,t,id;
}a[220000];
bool cmp(node x,node y){
	return x.l<y.l;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	memset(dis,220000,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]);
	for(int i=1;i<=q;i++){
		scanf("%d%d%d%d",&a[i].l,&a[i].r,&a[i].s,&a[i].t);
		a[i].id=i;
	}
	sort(a+1,a+1+q,cmp);
	int t=q;
	for(int i=m;i>=1;i--){
		dis[u[i]][v[i]]=dis[v[i]][u[i]]=i;
		for(int j=1;j<=n;j++){
			dis[u[i]][j]=min(dis[u[i]][j],max(dis[v[i]][j],i));
		}	
		for(int j=1;j<=n;j++){
			dis[v[i]][j]=min(dis[v[i]][j],max(dis[u[i]][j],i));
		}	
		while(t&&a[t].l==i){
			if(dis[a[t].s][a[t].t]<=a[t].r)  ans[a[t].id]=true;
			t--;
		}
	}
	for(int i=1;i<=q;i++) {
		if(ans[i]) puts("Yes");
	    else puts("No");
	}
	return 0;
}