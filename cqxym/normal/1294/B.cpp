#include<stdio.h>
#include<algorithm>
#define R register int
struct Pack{
	int X,Y;
}a[1000];
inline bool Com(Pack x,Pack y){
	if(x.X==y.X){
		return x.Y<y.Y;
	}
	return x.X<y.X;
}
inline void Solve(){
	int n;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d%d",&a[i].X,&a[i].Y);
	}
	std::sort(a,a+n,Com);
	for(R i=1;i!=n;i++){
		for(R j=0;j!=i;j++){
			if(a[j].X<a[i].X&&a[j].Y>a[i].Y){
				puts("NO");
				return;
			}
		}
	}
	puts("YES");
	for(R i=n-1;i!=0;i--){
		a[i].X-=a[i-1].X;
		a[i].Y-=a[i-1].Y;
	}
	for(R i=0;i!=n;i++){
		for(R j=0;j!=a[i].X;j++){
			printf("R");
		}
		for(R j=0;j!=a[i].Y;j++){
			printf("U");
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