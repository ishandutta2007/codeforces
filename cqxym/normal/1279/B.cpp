#include<stdio.h>
#define R register int
struct Max{
	int num,from;
}mx[100001];
int a[100001];
long long b[100001];
inline void Solve(){
	int n,s;
	scanf("%d%d",&n,&s);
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
		b[i]=b[i-1]+a[i];
		if(a[i]>mx[i-1].num){
			mx[i].num=a[i];
			mx[i].from=i;
		}else{
			mx[i]=mx[i-1];
		}
	}
	if(b[n]<=s){
		puts("0");
		return;
	}else{
		for(R i=n;i!=0;i--){
			if(b[i]-mx[i].num<=s){
				printf("%d\n",mx[i].from);
				return;
			}
		}
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