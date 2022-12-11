#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
int a,b,c,ans,k;LL now;
int main(){
	scanf("%d%d",&a,&b);
	c=abs(a-b);now=1e18;
	for(int i=1;i<=sqrt(c);i++){
		if(c%i==0){
			int d=b%i;
			k=i-d;if(k==i)k=0;
			if(1ll*(a+k)*(b+k)/i<now)now=1ll*(a+k)*(b+k)/i,ans=k;
			int j=c/i;
			d=b%j;
			k=j-d;if(k==j)k=0;
			if(1ll*(a+k)*(b+k)/j<now)now=1ll*(a+k)*(b+k)/j,ans=k;
		}
	}
	printf("%d",ans);
	return 0;
}