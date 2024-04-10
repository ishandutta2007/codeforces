#include<stdio.h>
#define R register int
int ans[10001]; 
int main(){
	int maxid=1,n,x,y;
	scanf("%d",&n);
	for(R i=2;i<=n;i++){
		printf("? %d %d\n",maxid,i);
		fflush(stdout);
		scanf("%d",&x);
		printf("? %d %d\n",i,maxid);
		fflush(stdout);
		scanf("%d",&y);
		if(x<y){
			ans[i]=y;
		}else{
			ans[maxid]=x;
			maxid=i;
		}
	}
	printf("!");
	ans[maxid]=n;
	for(R i=1;i<=n;i++){
		printf(" %d",ans[i]);
	}
	fflush(stdout);
	return 0;
}