#include<bits/stdc++.h>
using namespace std;
const int N=100000;
int n,x,y;
int a[N+1];
bool ok(int z){
	for(int i=max(z-x,1);i<z;i++)if(a[z]>=a[i])return false;
	for(int i=z+1;i<=z+y&&i<=n;i++)if(a[z]>=a[i])return false;
}
int main(){
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;;i++)if(ok(i))return printf("%d",i),0;
}