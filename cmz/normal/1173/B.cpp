#include<bits/stdc++.h>
using namespace std;
int n,now,lim;
struct rec{
	int x,y;
}q[10000],ans[10000];
bool vis[1000][1000];
int maxx=1,maxy=1,l,r;
bool judge(int x){
	maxx=1; maxy=1;
	for (int i=2;i<=n;++i){
		lim=0;
		for (int j=1;j<i;++j){
			lim=max(lim,i-j+q[j].x+q[j].y);
		}
		int z=1;
		for (int j=maxx;j<=x;++j){
			if (z==0) break;
			for (int k=maxy;k<=x;++k)
			if (j+k>=lim&&!vis[j][k]){
				q[i].x=j; q[i].y=k; vis[j][k]=1;
				maxx=max(maxx,j); maxy=max(maxy,k);
				z=0; break;
			}
		}
		if (z==1) return 0;
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	q[1].x=q[1].y=1; lim=0;
	l=1; r=1000;
	while (l<=r){
		for (int i=1;i<=n;++i){vis[q[i].x][q[i].y]=0;q[i].x=q[i].y=0;}
		q[1].x=q[1].y=1; vis[1][1]=1;
		int mid=(l+r)/2;
		if (judge(mid)){
			for (int i=1;i<=n;++i) ans[i]=q[i];
			r=mid-1;
		} else l=mid+1;
	}
	printf("%d\n",l);
	for (int i=1;i<=n;++i)
	printf("%d %d\n",ans[i].x,ans[i].y);
}