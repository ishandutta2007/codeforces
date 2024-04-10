#include<cstdio>
int n,a,b,c,d,x,y,xx,yy,xxx,yyy;
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&x,&y,&xx,&yy,&xxx,&yyy);
	x-=xx,y-=yy;
	xx=xxx-xx,yy=yyy-yy;
	xxx=x+b-a,yyy=y+d-c;
	puts(xxx<0||xxx>xx||yyy<0||yyy>yy||!xx&&a||!yy&&c?"No":"Yes");
	}return 0;
}