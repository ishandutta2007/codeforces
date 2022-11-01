#include<stdio.h>
#define R register int
int a[501],b[500];
inline void Swap(int&x,int&y){
	int t=x;
	x=y;
	y=t;
}
inline void Solve(){
	int n;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
	}
	bool tag1=false,tag2=false;
	for(R i=0;i!=n;i++){
		scanf("%d",b+i);
		tag1|=b[i]==0;
		tag2|=b[i]==1;
	}
	if(tag1==true&&tag2==true){
		puts("Yes");
		return;
	}
	for(R i=1;i!=n;i++){
		for(R j=0;j!=i;j++){
			if(a[j]>a[i]){
				puts("No");
				return;
			}
		}
	}
	puts("YES");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}