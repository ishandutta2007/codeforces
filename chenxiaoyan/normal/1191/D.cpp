#include<bits/stdc++.h>
using namespace std;
#define N 100000
int n;
int a[N+1];
int main(){
	scanf("%d",&n);
	if(n==1){
		scanf("%d",&n);
		return printf(n&1?"sjfnb":"cslnb"),0;
	}
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1);
	int samecnt=0;
	for(int i=1;i<n;i++)if(a[i]==a[i+1])samecnt++;
	if(samecnt>=2)return printf("cslnb"),0;
	bool rev=false;
	if(samecnt==1)
		for(int i=1;i<=n;i++)if(a[i]==a[i+1])
			if(!a[i])return printf("cslnb"),0;
			else if(i-1&&a[i]==a[i-1]+1)return printf("cslnb"),0;
			else a[i]--,rev=true;
	bool odd=false;
	for(int i=1;i<=n;i++)odd^=a[i]-(i-1)&1;
	if(!odd&&!rev||odd&&rev)printf("cslnb");
	else printf("sjfnb");
	return 0;
}