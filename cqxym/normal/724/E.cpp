#include<stdio.h>
#define R register int
#define L long long
L f[10001];
int p[10001];
int main(){
	int n,s,c;
	scanf("%d%d",&n,&c);
	for(R i=1;i<=n;i++){
		scanf("%d",p+i);
	}
	for(R i=1;i<=n;i++){
		scanf("%d",&s);
		register L v=(L)i*c+p[i];
		f[i]=f[i-1]+s;
		for(R j=i-1;j>0;j--){
			v-=c;
			f[j]+=v;
			if(f[j-1]+s<f[j]){
				f[j]=f[j-1]+s;
			}
		}
		f[0]+=p[i];
	}
	long long ans=f[0];
	for(R i=1;i<=n;i++){
		if(f[i]<ans){
			ans=f[i];
		}
	}
	printf("%lld",ans);
	return 0;
}