#include<cstdio>
int a[105],s=0;
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
		s+=a[i];
	}
	printf("%d\n",s);
	return 0;
}