#include<stdio.h>
#define R register int
int a[200001],L[200001];
inline void Min(int &x,int y){
	x=x<y?x:y;
}
inline void Solve(){
	int n,s=3e5;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
		L[i]=0;
	}
	for(R i=1;i<=n;i++){
		if(L[a[i]]!=0){
			Min(s,i-L[a[i]]);
		}
		L[a[i]]=i;
	}
	if(s==3e5){
		puts("-1");
	}else{
		printf("%d\n",s+1);
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}