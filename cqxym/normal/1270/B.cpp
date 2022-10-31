#include<stdio.h>
#define R register int
int a[200000];
inline int Abs(int &x,int &y){
	return x>y?x-y:y-x;
}
inline void Solve(){
	int n;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
	}
	for(R i=1;i!=n;i++){
		if(Abs(a[i],a[i-1])>1){
			printf("YES\n%d %d\n",i,i+1);
			return;
		}
	}
	puts("NO");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}