#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,a[N],s;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%1d",&a[i]),s+=a[i];
	if(n%2==0&&s==n/2){
		puts("2");
		printf("%d ",a[1]);
		for(int i=2;i<=n;i++)printf("%d",a[i]);
	}
	else{
		puts("1");
		for(int i=1;i<=n;i++)printf("%d",a[i]);
	}
	return 0;
}