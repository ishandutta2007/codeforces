#include <iostream>
#include <cstdio>
#define inf 200000000
using namespace std;
int n,x[1000005],y[1000005],minx,maxx,miny,maxy;
int work1(){
	int mny=inf,mxy=-inf;
	for (int i=1;i<=n;i++){
		if (x[i]==minx||x[i]==maxx)
			mny=min(mny,y[i]),mxy=max(mxy,y[i]);
	}
	return 2*(maxx-minx+max(maxy-mny,mxy-miny));
}
int work2(){
	int mnx=inf,mxx=-inf;
	for (int i=1;i<=n;i++){
		if (y[i]==miny||y[i]==maxy)
			mnx=min(mnx,x[i]),mxx=max(mxx,x[i]);
	}
	return 2*(max(maxx-mnx,mxx-minx)+maxy-miny);
}
int main(){
	cin>>n;
	minx=inf,maxx=-inf,miny=inf,maxy=-inf;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		minx=min(minx,x[i]),miny=min(miny,y[i]);
		maxx=max(maxx,x[i]),maxy=max(maxy,y[i]);
	}
	int ans=max(work1(),work2());
	for (int i=1;i<=n;i++)ans=max(ans,2*(x[i]-minx+y[i]-miny)),ans=max(ans,2*(maxx-x[i]+maxy-y[i]));
	for (int i=1;i<=n;i++)ans=max(ans,2*(x[i]-minx+maxy-y[i])),ans=max(ans,2*(maxx-x[i]+y[i]-miny));
	cout<<ans<<' ';
	for (int i=4;i<=n;i++)printf("%d ",2*(maxx-minx+maxy-miny));
	return 0;
}