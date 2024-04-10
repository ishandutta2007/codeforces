#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	scanf("%d",&n);
	m=ceil(1.0*(n-1)/2)+1;
	printf("%d\n",m);
	for(int k=1,i=0,j=1;k<=n;k++){
		if(i==m)j++;
		else i++;
		printf("%d %d\n",i,j);
	}
	return 0;
}