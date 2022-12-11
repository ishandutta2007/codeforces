#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,a[N];
int main(){
	scanf("%d",&n);
	a[1]=1;
	for(int i=2;i<=n;i++)a[i]=a[i-1]+i*4-4;
	printf("%d\n",a[n]);
	return 0;
}