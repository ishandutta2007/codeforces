#include<stdio.h>
inline void Solve(){
	int a,b,c,d,x,y,x1,x2,y1,y2;
	scanf("%d%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&x,&y,&x1,&y1,&x2,&y2);
	if(a!=0||b!=0){
		if(x==x1&&x==x2){
			puts("No");
			return;
		}
		x-=a-b;
		if(x<x1||x>x2){
			puts("No");
			return;
		}
	}
	if(c!=0||d!=0){
		if(y==y1&&y==y2){
			puts("No");
			return;
		}
		y-=c-d;
		if(y<y1||y>y2){
			puts("No");
			return;
		}
	}
	puts("Yes");
}
int main(){
	int t;
	scanf("%d",&t);
	for(register int i=0;i!=t;i++){
		Solve();
	}
	return 0;
}