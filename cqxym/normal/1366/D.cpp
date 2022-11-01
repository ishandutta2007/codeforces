#include<stdio.h>
#define R register int
#define P 10000001
int ans[500000][2],d[P];
int main(){
	int n,x;
	for(R i=2;i!=P;i++){
		if(d[i]==0){
			d[i]=i;
			for(R j=i<<1;j<P;j+=i){
				if(d[j]==0){
					d[j]=i;
				}
			}
		}
	}
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",&x);
		if(x==1){
			ans[i][0]=ans[i][1]=-1;
		}else{
			int t=d[x];
			do{
				x/=t;
			}while(x%t==0);
			if(x==1){
				ans[i][0]=ans[i][1]=-1;
			}else{
				ans[i][0]=t;
				ans[i][1]=x;
			}
		}
	}
	for(R i=0;i!=n;i++){
		printf("%d ",ans[i][0]);
	}
	puts("");
	for(R i=0;i!=n;i++){
		printf("%d ",ans[i][1]);
	}
	return 0;
}