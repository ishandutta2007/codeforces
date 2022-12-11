#include<bits/stdc++.h>
using namespace std;
const int N=2020;
int n,a[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)scanf("%d",&a[i]);
	sort(a+1,a+2*n+1);
	if(a[1]==a[2*n])puts("-1");
	else for(int i=1;i<=2*n;i++)printf("%d ",a[i]);
	return 0;
}