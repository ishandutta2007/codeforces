#include<cstdio>
int m,n,a,c;
int main(){
	scanf("%d%d",&m,&n);
	for(int i=n-1;~i;i--)scanf("%d",&a),c^=a&1;
	puts((m&1?c:a&1)?"odd":"even");
	return 0;
}