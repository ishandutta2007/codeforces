#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+50;
int n,a[N],b[N],c[N*2],cnt,m,ver[N*4],nxt[N*4],head[N*2],tot=1,d[N*2],h,maxn,stck[N*3],tp,now,ans[N];bool vis[N*2];
void add(int x,int y){
	ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;
}
void euler(int x){
	for(int &i=head[x];i;i=nxt[i]){
		if(!vis[i>>1]){
			vis[i>>1]=1,euler(ver[i]);
		} 
	}
	ans[++now]=x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d",&a[i]),c[++cnt]=a[i];
	for(int i=1;i<n;i++)scanf("%d",&b[i]),c[++cnt]=b[i];
	for(int i=1;i<n;i++){
		if(a[i]>b[i]){
			puts("-1");
			return 0;
		}
	}
	sort(c+1,c+cnt+1);m=unique(c+1,c+cnt+1)-c-1;
	for(int i=1;i<n;i++)a[i]=lower_bound(c+1,c+m+1,a[i])-c;
	for(int i=1;i<n;i++)b[i]=lower_bound(c+1,c+m+1,b[i])-c;
	for(int i=1;i<n;i++)add(a[i],b[i]),add(b[i],a[i]),d[a[i]]++,d[b[i]]++;
	int num=0;
	for(int i=1;i<=m;i++)if(d[i]&1)num++,h=i;
	if(num&&num!=2){
		puts("-1");return 0;
	}
	if(!h)h=1;
		euler(h);
		if(now!=n){
			puts("-1");return 0;
		}
		for(int i=1;i<=now;i++)printf("%d ",c[ans[i]]);
	return 0;
}