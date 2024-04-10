#include<stdio.h>
#include<algorithm>
#define R register int
#define I inline
int a[1000];
I Min(int &x,int y){
	return x<y?x:y;

}
I Max(int &x,int y){
	x=x>y?x:y;
}
I void Solve(){
	int n,s=0;
	scanf("%d",&n);
	for(R i=0;i<n;i++){
		scanf("%d",a+i);
	}
	std::sort(a,a+n);
	for(R i=n-1;i>-1;i--){
		Max(s,Min(a[i],n-i));
	}
	printf("%d\n",s);
}
int main(){
	int k;
	scanf("%d",&k);
	for(R i=0;i<k;i++){
		Solve();
	}
	return 0;
}