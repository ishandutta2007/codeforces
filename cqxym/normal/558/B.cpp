#include<stdio.h>
#define R register int
int ct[1000001],lt[1000001],ft[1000001];
int main(){
	int n,mx=0,x,ansl=0,ansr=1e6;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d",&x);
		ct[x]++;
		if(ft[x]==0){
			ft[x]=i;
		}
		lt[x]=i;
		if(ct[x]>mx){
			mx=ct[x];
		}
	}
	for(R i=1;i<=1e6;i++){
		if(ct[i]==mx){
			if(lt[i]-ft[i]<ansr-ansl||(lt[i]-ft[i]==ansr-ansl&&ft[i]<ansl)){
				ansl=ft[i];
				ansr=lt[i];
			}
		}
	}
	printf("%d %d",ansl,ansr);
	return 0;
}