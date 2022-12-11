#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,a[N];bool flag=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i!=1&&(a[i]+a[i-1])&1)flag=1;
	}
	if(flag)sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	return 0;
}