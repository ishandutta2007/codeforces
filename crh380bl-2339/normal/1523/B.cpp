#include<bits/stdc++.h>
using namespace std;
int a[1005],b[1005];
int main(){
	int T,n,i,j;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;++i){
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		printf("%d\n",3*n);
		for(i=1;i<=n;i+=2){
			for(j=1;j<=6;++j){
				if(j&1)printf("1");
				else printf("2");
				printf(" %d %d\n",i,i+1);
				//if(j&1)b[i]+=b[i+1];
				//else b[i+1]-=b[i];
			}
		}
		//for(i=1;i<=n;++i)assert(b[i]+a[i]==0);
	}
	return 0;
}