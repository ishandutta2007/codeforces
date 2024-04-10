#include<stdio.h>
#define R register int
#define I inline
int f[200001],ct[200001];
I int GetF(int x){
	if(f[x]==x){
		return x;
	}
	f[x]=GetF(f[x]);
	return f[x];
}
I void Solve(){
	int n,x;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		f[i]=i;
		ct[i]=0;
	}
	for(R i=1;i<=n;i++){
		scanf("%d",&x);
		f[GetF(i)]=GetF(x);
	}
	for(R i=1;i<=n;i++){
		ct[GetF(i)]++;
	}
	for(R i=1;i<=n;i++){
		printf("%d ",ct[f[i]]);
	}
	puts("");
}
int main(){
	int q;
	scanf("%d",&q);
	for(R i=0;i<q;i++){
		Solve();
	}
	return 0;
}