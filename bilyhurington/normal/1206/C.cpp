#include<cstdio>
#include<iostream>
using namespace std;
int n,a[200010];
int main(){
	scanf("%d",&n);
	if(n%2==0){
		printf("NO");
		return 0;
	}
	printf("YES\n");
	for(int i=1;i<=n;i++){
		a[i]=2*i-i%2;
		a[n+i]=2*i-(i+1)%2;
	}
	for(int i=1;i<=2*n;i++) printf("%d ",a[i]);
	return 0;
}