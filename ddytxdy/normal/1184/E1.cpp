#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50,M=1e6+50,inf=1e9;
int n,m,X,Y,f[N],Z,ans;
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x!=y)f[x]=y;
}
struct node{
	int x,y,z;
	bool friend operator <(node a,node b){return a.z<b.z;}
}a[M];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)f[i]=i;
	scanf("%d%d%d",&X,&Y,&Z),a[1]=(node){X,Y,inf};
	for(int i=2;i<=m;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++){
		int x=a[i].x,y=a[i].y,z=a[i].z;
		merge(x,y);
		if(find(X)==find(Y)){ans=z;break;}
	}
	printf("%d\n",ans);
	return 0;
}