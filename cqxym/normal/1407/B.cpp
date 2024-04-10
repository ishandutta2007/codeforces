#include<stdio.h>
#define R register int
int a[1000];
inline int Gcd(int x,int y){
	return y==0?x:Gcd(y,x%y);
}
inline void Solve(){
	int n,maxid=0;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
	}
	for(R i=1;i!=n;i++){
		if(a[i]>a[maxid]){
			maxid=i;
		}
	}
	int tem=a[0],g;
	g=a[0]=a[maxid];
	a[maxid]=tem;
	printf("%d",a[0]);
	for(R i=1;i!=n;i++){
		maxid=i;
		for(R j=i+1;j!=n;j++){
			if(Gcd(g,a[j])>Gcd(g,a[maxid])){
				maxid=j;
			}
		}
		tem=a[maxid];
		a[maxid]=a[i];
		a[i]=tem;
		g=Gcd(g,tem);
		printf(" %d",tem);
	}
	puts("");
}
int main(){
    int t;
    scanf("%d",&t);
    for(R i=0;i!=t;i++){
    	Solve();
	}
    return 0;
}