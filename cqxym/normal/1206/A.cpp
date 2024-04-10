#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
	int n,m,i,x;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		a=max(a,x);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&x);
		b=max(b,x);
	}
	printf("%d %d",a,b);
	return 0;
}