#include<stdio.h>
#define R register int
int a[100001];
int main(){
	int n,t,m,lt,ans=0,ct=0;
	scanf("%d%d",&n,&t);
	for(R i=0;i!=t;i++){
		scanf("%d",&m);
		for(R i=0;i!=m;i++){
			scanf("%d",a+i);
		}
		lt=1;
		if(a[0]==1){
			while(lt<m&&a[lt]==a[lt-1]+1){
				lt++;
			}
		}
		ans+=m-lt;
		ct+=m-lt+1;
	}
	printf("%d",ans+ct-1);
	return 0;
}