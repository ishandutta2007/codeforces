#include<stdio.h>
#include<algorithm>
#define R register int
int a[100001];
int main(){
	int t,n,r,s;
	scanf("%d",&t);
	for(R i=0;i<t;i++){
		scanf("%d%d",&n,&r);
		for(R j=0;j<n;j++){
			scanf("%d",&a[j]);
		}
		std::sort(a,a+n);
		n=std::unique(a,a+n)-a-1; 
		s=0;
		while(a[n]>s*r){
			n--;
			s++;
		}
		printf("%d\n",s);
	}
	return 0;
}