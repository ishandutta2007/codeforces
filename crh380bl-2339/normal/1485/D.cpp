#include<bits/stdc++.h>
#define N 720720
using namespace std;
int a[505][505];
int main(){
	int n,m,i,j,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			scanf("%d",&x);
			if((i+j)&1)a[i][j]=N;
			else a[i][j]=N-x*x*x*x;
		}
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j)printf("%d ",a[i][j]);
		puts("");
	}
	return 0;
}