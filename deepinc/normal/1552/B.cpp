#include<bits/stdc++.h>
using namespace std;
int n,rk[6][55555];
int win(int a,int b){
	int w=0;
	for(int i=1;i<=5;++i)w+=rk[i][a]<rk[i][b];
	return w>=3?a:b;
}
int main(){
	int t;scanf("%d",&t);while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)for(int j=1;j<=5;++j)scanf("%d",&rk[j][i]);
		int nw=1;
		for(int i=2;i<=n;++i)nw=win(nw,i);
		
		for(int i=1;i<=n;++i)if(nw!=i)if(nw!=win(nw,i)){puts("-1");goto z;}
		printf("%d\n",nw);z:;
		
	}
}