#include<bits/stdc++.h>
using namespace std;
int c[100001];
int main(){
	int n,i;
	scanf("%d",&n);
	if(n%2==0){
		printf("NO");
		return 0;
	}
	printf("YES\n1");
	c[0]=2;
	int m=3;
	bool f=true;
	for(i=1;i<n;i++){
		if(f==true){
			printf(" %d",m+1);
			c[i]=m;
		}else{
			printf(" %d",m);
			c[i]=m+1;
		}
		m+=2;
		f=!f;
	}
	for(i=0;i<n;i++){
		printf(" %d",c[i]);
	}
	return 0;
}