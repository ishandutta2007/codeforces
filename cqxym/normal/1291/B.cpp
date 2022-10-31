#include<stdio.h>
#define R register int
int a[300000];
inline void Solve(){
	int n,lt=-1,x,l=n,r=-1;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
	}
	for(R i=0;i!=n;i++){
		if(a[i]<i){
			l=i;
			break;
		}
	}
	for(R i=n-1;i!=-1;i--){
		if(a[i]<n-1-i){
			r=i;
			break;
		}
	}
	if(l-2<r){
		puts("No");
	}else{
		puts("Yes");
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