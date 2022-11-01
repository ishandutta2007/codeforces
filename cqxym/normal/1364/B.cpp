#include<stdio.h>
#define R register int
bool v[100000];
int a[100000];
inline void Solve(){
	int n,m;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
		v[i]=true;
	}
	m=n;
	for(R i=2;i!=n;i++){
		if(a[i-2]<=a[i-1]&&a[i-1]<=a[i]||a[i-2]>=a[i-1]&&a[i-1]>=a[i]){
			m--;
			v[i-1]=false;
		}
	}
	printf("%d\n",m);
	for(R i=0;i!=n;i++){
		if(v[i]==true){
			printf("%d ",a[i]);
		}
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