#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=500005,mod=1000000007;
int T,n,sum;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),sum=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),sum+=a[i];
		if(sum%n==0)
			puts("0");
		else puts("1");
	}
	return 0;
}