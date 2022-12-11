#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,dx[7]={0,1,0,1,2,1,2},dy[7]={0,0,1,1,1,2,2};
int main(){
	scanf("%d",&n);
	printf("%d\n",n*3+4);
	for(int i=0;i<n;i++)
		printf("%d %d\n%d %d\n%d %d\n",i,i,i,i+1,i,i+2);
	printf("%d %d\n%d %d\n%d %d\n%d %d\n",-1,0,-1,1,n,n,n,n+1);
	return 0;
}