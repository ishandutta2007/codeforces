#include <iostream>
#include <cstdio>
using namespace std;
int n,t,ll=0,tt;
int main(){
	scanf("%d %d",&n,&t);
	for(int i=1;i<=n;++i)scanf("%d",&tt),ll+=tt;
	if(n==0)puts("YES");
	else if(ll+n-1==t)puts("YES");else puts("NO");
	return 0;
}