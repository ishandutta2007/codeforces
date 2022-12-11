#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,x[N],y[N],numx[N],numy[N],maxx,minx=100,maxy,miny=100,a[N],tp;bool flag=0,visx[N],visy[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n*4+1;i++){
		scanf("%d%d",&x[i],&y[i]);
		numx[x[i]]++;numy[y[i]]++;
	}
	for(int i=0;i<=50;i++)if(numx[i]>=n)maxx=max(maxx,i),minx=min(minx,i);
	for(int i=0;i<=50;i++)if(numy[i]>=n)maxy=max(maxy,i),miny=min(miny,i);
	for(int i=1;i<=n*4+1;i++)if(x[i]>maxx||x[i]<minx||y[i]>maxy||y[i]<miny)printf("%d %d\n",x[i],y[i]),flag=1;
	if(!flag)for(int i=1;i<=n*4+1;i++)if(x[i]!=maxx&&x[i]!=minx&&y[i]!=maxy&&y[i]!=miny)printf("%d %d\n",x[i],y[i]);
	return 0;
}