#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 1000010
int pre[MAXN][10],g[MAXN],f[MAXN],n,l,r,k;
int find(int i){
	if(f[i])return f[i];
	int x=i;f[i]=1;
	while(x){
		if(x%10)f[i]=f[i]*(x%10);
		x/=10;
	}
	return f[i];
}
int get(int i){
	if(i<10)return i;
	if(g[i])return g[i];
	return g[i]=get(find(i));
}
int main(){
	for(int i=1;i<=1000000;++i)g[i]=get(i);
	for(int i=1;i<=1000000;++i){
		for(int j=0;j<=9;++j)
			pre[i][j]=pre[i-1][j];
		++pre[i][g[i]];
	}
	//puts("OK");
	scanf("%d",&n);
	while(n--){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",pre[r][k]-pre[l-1][k]);
	}

	return 0;
}