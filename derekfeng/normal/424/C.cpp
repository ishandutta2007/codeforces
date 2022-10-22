#include<bits/stdc++.h>
using namespace std;
int n,ans,x,a[1000004];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x),ans^=x;
		a[i]=a[i-1]^i,ans^=a[n%i];
		if((n/i)%2==1)ans^=a[i-1];
	}
	printf("%d",ans);
}