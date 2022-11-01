#include<stdio.h>
#define R register int
int x[6000],y[6000];
int main(){
	int n;
	scanf("%d",&n);
	int ct[2][2]={{0,0},{0,0}};
	for(R i=0;i!=n;i++){
		scanf("%d%d",x+i,y+i);
		x[i]=x[i]>>1&1;
		y[i]=y[i]>>1&1;
	}
	long long ans=0;
	for(R i=n-2;i!=0;i--){
		ct[x[i+1]][y[i+1]]++;
		for(R j=0;j!=i;j++){
			int g=(x[i]^x[j])&(y[i]^y[j])&1;
			for(R k=0;k!=2;k++){
				for(R l=0;l!=2;l++){
					int g1=(x[i]^k)&(y[i]^l),g2=(x[j]^k)&(y[j]^l);
					if((g^g1^g2)==0){
						ans+=ct[k][l];
					}
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}