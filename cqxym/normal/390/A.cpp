#include<stdio.h>
bool a[101],b[101];
int main(){
	int n,x,y;
	scanf("%d",&n);
	for(register int i=0;i!=n;i++){
		scanf("%d%d",&x,&y);
		a[x]=b[y]=true;
	}
	x=y=0;
	for(register int i=0;i!=101;i++){
		x+=a[i];
		y+=b[i];
	}
	printf("%d",x<y?x:y);
	return 0;
}