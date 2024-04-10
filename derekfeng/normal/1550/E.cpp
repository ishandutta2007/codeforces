#include <bits/stdc++.h>
using namespace std;
int n,K,p[20][200004],f[131172];
char c[200004];
bool check(int x){
	for(int i=0;i<K;i++)p[i][n+1]=n+1;
	for(int i=0;i<K;i++){
		int lst=n+1;
		for(int j=n;j;j--){
			if(c[j]!='?'&&c[j]!=i+'a')lst=j;
			p[i][j]=p[i][j+1];
			if(lst-j>=x)p[i][j]=j+x-1;
		}
	}
	for(int i=1;i<(1<<K);i++)f[i]=n+1;
	for(int i=1;i<(1<<K);i++)
		for(int j=0;j<K;j++)if((1<<j)&i)if(f[i^(1<<j)]<=n)
			f[i]=min(f[i],p[j][f[i^(1<<j)]+1]);
	return f[(1<<K)-1]<=n;
}
int main(){
	scanf("%d%d%s",&n,&K,c+1);
	int l=0,r=n+1;
	while(r>l+1){
		int mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	printf("%d\n",l);
}