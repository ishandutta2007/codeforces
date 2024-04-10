#include<stdio.h>
#define R register int
int f[200001][2],a[200001],b[200001];
int Min(int x,int y){
	return x<y?x:y;
}
int main(){
	int n,mx1,mx2,c;
	scanf("%d%d",&n,&c);
	for(R i=1;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(R i=1;i<n;i++){
		scanf("%d",&b[i]);
	}
	mx1=a[1];
	mx2=b[1];
	f[0][1]=c;
	printf("0");
	for(R i=2;i<=n;i++){
		f[i][0]=mx1;
		f[i][1]=mx2+c;
		mx1=Min(mx1,f[i][1])+a[i];
		mx2=Min(mx2,f[i][0])+b[i];
		printf(" %d",Min(f[i][0],f[i][1]));
	}
	return 0;
}