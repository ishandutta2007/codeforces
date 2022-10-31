#include<stdio.h>
#include<algorithm>
#define R register int
inline void Solve(){
	int a[3],s=0;
	scanf("%d%d%d",a,a+1,a+2);
	if(a[0]!=0){
		a[0]--;
		s++;
	}
	if(a[1]!=0){
		a[1]--;
		s++;
	}
	if(a[2]!=0){
		a[2]--;
		s++;
	}
	std::sort(a,a+3);
	if(a[2]!=0&&a[1]!=0){
		a[2]--;
		a[1]--;
		s++;
	}
	if(a[2]!=0&&a[0]!=0){
		a[0]--;
		a[2]--;
		s++;
	}
	if(a[1]!=0&&a[0]!=0){
		a[1]--;
		a[0]--;
		s++;
	}
	if(a[0]!=0&&a[1]!=0&&a[2]!=0){
		s++;
	}
	printf("%d\n",s);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}