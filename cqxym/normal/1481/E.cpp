#include<stdio.h>
#define R register int
#define N 500002
int a[N],ct[N],f[N],rt[N],lf[N];
inline int Max(int x,int y){
	return x>y?x:y;
}
int main(){
	int n;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
		if(lf[a[i]]==0){
			lf[a[i]]=i;
		}
		rt[a[i]]=i;
	}
	for(R i=n;i!=0;i--){
		ct[a[i]]++;
		f[i]=Max(f[i+1],ct[a[i]]);
		if(i==lf[a[i]]){
			f[i]=Max(f[i],f[rt[a[i]]+1]+ct[a[i]]);
		}
	}
	printf("%d",n-f[1]);
	return 0;
}