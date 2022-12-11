#include<cstdio>
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	if(a==b){
		printf("%d 0\n",a);
		return 0;
	}
	if(a<b)a^=b^=a^=b;
	int day=0;
	while(a-b>1)a-=2,++day;
	printf("%d %d\n",b,day);
	return 0;
}