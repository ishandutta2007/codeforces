#include<bits/stdc++.h>
using namespace std;
int t,n;
int f[5],g[5][5],c[5];
void sol(){
	scanf("%d",&n);
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++)scanf("%d",&c[j]);
		for(int j=0;j<5;j++)if(c[j]){
			f[j]++;
			for(int k=0;k<5;k++)if(c[k])g[j][k]++;
		}
	}
	for(int i=0;i<5;i++)for(int j=i+1;j<5;j++){
		int a=f[i]-g[i][j],b=f[j]-g[i][j];
		if(a+b+g[i][j]==n&&max(a,b)<=n/2){
			puts("YES");
			return;
		}
	}
	puts("NO");
}
int main(){
	scanf("%d",&t);
	while(t--)sol();
}