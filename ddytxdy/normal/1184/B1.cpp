#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
struct node{
	int x,y;
}b[N];
int n,m,a[N],d[N*2],c[N*2],mm;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),c[i]=a[i];
	for(int i=1;i<=m;i++){
		scanf("%d%d",&b[i].x,&b[i].y);
		c[n+i]=b[i].x;
	}
	sort(c+1,c+n+m+1);mm=unique(c+1,c+n+m+1)-c-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(c+1,c+mm+1,a[i])-c;
	for(int i=1;i<=m;i++)b[i].x=lower_bound(c+1,c+mm+1,b[i].x)-c;
	for(int i=1;i<=m;i++)d[b[i].x]+=b[i].y;
	for(int i=1;i<=mm;i++)d[i]+=d[i-1];
	for(int i=1;i<=n;i++)printf("%d ",d[a[i]]);
	return 0;
}