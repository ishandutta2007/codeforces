#include<stdio.h>
#define R register int
int a[200005];
inline void Solve(){
	int n,s=0;
	scanf("%d%d",&n,&n);
	for(R i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	a[n]=a[n+1]=0;
	for(R i=0;i<n;i++){
		if(a[i]-a[i+1]>1){
			a[i]=a[i+1]+1;
			i--;
			continue;
		}
		if(a[i+2]<a[i+1]-1){
			s++;
			a[i+1]=a[i]-2;
		}else{
			i++;
		}
	}
	printf("%d\n",s);
}
int main(){
	int t,n,r,s;
	scanf("%d",&t);
	for(R i=0;i<t;i++){
		Solve();
	}
	return 0;
}