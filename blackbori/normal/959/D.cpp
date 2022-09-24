#include <bits/stdc++.h>

using namespace std;

bool chk[5050505];
int n;

void factorize(int a)
{
	int i,j;
	
	for(i=2;i*i<=a;i++){
		if(a%i == 0){
			for(j=i;j<=5e6;j+=i) chk[j] = 1;
			for(;a%i == 0;a/=i);
		}
	}
	
	if(a != 1){
		for(j=a;j<=5e6;j+=a) chk[j] = 1;
	}
}

int main()
{
	int i,j,a;
	
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		if(chk[a]) break;
		else factorize(a);
		
		printf("%d ",a);
	}
	
	if(i <= n){
		for(;chk[a];a++);
		printf("%d ",a);
		factorize(a);
		for(j=1,i++;i<=n;i++){
			for(j++;chk[j];j++);
			printf("%d ",j);
			factorize(j);
		}
	}
	
	printf("\n");
	
	return 0;
}