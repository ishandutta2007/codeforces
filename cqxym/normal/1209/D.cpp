#include<stdio.h>
#define R register int
int f[100001],ct[100001];
int GetF(int x){
	if(f[x]==x){
		return x;
	}
	f[x]=GetF(f[x]);
	return f[x];
}
int main(){
	int n,k,x,y;
	scanf("%d%d",&n,&k);
	for(R i=1;i<=n;i++){
		f[i]=i;
	}
	for(R i=0;i<k;i++){
		scanf("%d%d",&x,&y);
		if(GetF(x)!=GetF(y)){
			f[f[x]]=f[y];
		}
	}
	for(R i=1;i<=n;i++){
		x=GetF(i);
		ct[f[x]]++;
	}
	y=0;
	for(R i=1;i<=n;i++){
		if(ct[i]>0){
			y+=ct[i]-1;
		}
	}
	printf("%d",k-y);
	return 0;
}