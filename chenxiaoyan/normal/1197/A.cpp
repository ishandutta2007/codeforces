#include<bits/stdc++.h>
using namespace std;
const int N=100000;
int n;
int a[N+1];
void mian(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1);
	printf("%d\n",min(n-2,a[n-1]-1));
}
int main(){
	int qu;
	scanf("%d",&qu);
	while(qu--)mian();
	return 0;
}