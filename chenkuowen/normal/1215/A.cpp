#include<bits/stdc++.h>
using namespace std;
int main(){
	int a1,a2,k1,k2,n; scanf("%d%d%d%d%d",&a1,&a2,&k1,&k2,&n);
	if(k1>k2) swap(k1,k2),swap(a1,a2);
	printf("%d ",min(max(0,n-a1*(k1-1)-a2*(k2-1)),a1+a2));
	if(n<a1*k1){
		printf("%d\n",n/k1);
	}else{
		printf("%d\n",a1+(n-a1*k1)/k2);
	}
	return 0;
}