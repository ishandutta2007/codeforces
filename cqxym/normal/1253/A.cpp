#include<stdio.h>
#define R register int
int a[100001];
inline void Solve(){
	int n;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d",a+i); 
	}
	int x;
	bool tag=false;
	for(R i=1;i<=n;i++){
		scanf("%d",&x);
		if(x<a[i]){
			tag=true;
		}
		a[i]=x-a[i];
	}
	if(tag==true){
		puts("NO");
		return;
	}
	R s=1,t;
	while(s<=n&&a[s]==0){
		s++;
	}
	t=s+1;
	while(t<=n&&a[t]==a[s]){
		t++;
	}
	for(R i=t;i<=n;i++){
		if(a[i]!=0){
			puts("NO");
			return;
		}
	}
	puts("YES");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i<t;i++){
		Solve();
	}
	return 0; 
}