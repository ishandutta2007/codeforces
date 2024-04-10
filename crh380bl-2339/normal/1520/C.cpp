#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int main(){
	int T,n,i,j,k,nx,ny,nw;
	scanf("%d",&T);while(T--){
		scanf("%d",&n);
		if(n==1)puts("1");
		else if(n==2)puts("-1");
		else{
			nw=0;
			for(i=1;i<n;++i){
				nx=i;ny=1;
				while(nx<=n&&ny<=n){
					++nw;
					a[nx][ny]=nw;
					++nx;++ny;
				}
			}
			for(i=2;i<n;++i){
				nx=1;ny=i;
				while(nx<=n&&ny<=n){
					++nw;
					a[nx][ny]=nw;
					++nx;++ny;
				}
			}
			a[n][1]=n*n-1;
			a[1][n]=n*n;
			for(i=1;i<=n;++i){
				for(j=1;j<n;++j){
					printf("%d ",a[i][j]);
				}
				printf("%d\n",a[i][n]);
			}
		}
	}
	return 0;
}