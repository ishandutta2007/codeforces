#include<cstdio>
#include<iostream>
using namespace std;
const int o=510;
int n,K,a[o][o],c,mxx[o*o],mnx[o*o],mxy[o*o],mny[o*o],b[o][o];
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n*n;++i) mnx[i]=mny[i]=o;
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j)
		scanf("%d",&a[i][j]),
		mxx[a[i][j]]=max(mxx[a[i][j]],i),mnx[a[i][j]]=min(mnx[a[i][j]],i),
		mxy[a[i][j]]=max(mxy[a[i][j]],j),mny[a[i][j]]=min(mny[a[i][j]],j);
	for(int i=1;i<=n*n;++i) if(mnx[i]<o) ++c;
	if(c<=K){printf("%d",K-c);return 0;}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) for(int k=1;k<=n;++k) b[j][k]=0;
		for(int j=1,lx,rx,ly,ry;j<=n*n;++j) if(mnx[j]<o){
			lx=max(1,mxx[j]-i+1);ly=max(1,mxy[j]-i+1);
			rx=min(mnx[j],n-i+1);ry=min(mny[j],n-i+1);
			if(lx<=rx&&ly<=ry) ++b[lx][ly],--b[lx][ry+1],--b[rx+1][ly],++b[rx+1][ry+1];
		}
		for(int j=1;j<=n;++j) for(int k=1;k<=n;++k) b[j][k]+=b[j-1][k]+b[j][k-1]-b[j-1][k-1];
		for(int j=1;j<=n;++j) for(int k=1;k<=n;++k) if(c-b[j][k]==K||c-b[j][k]+1==K){printf("1");return 0;}
	}
	printf("2");
	return 0;
}