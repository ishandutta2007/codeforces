#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define int long long
using namespace std;
const int maxn=500005;
int T,n,L;
int a[maxn];
string s; 
signed main(){
	memset(a,0x3f,sizeof(a));
	scanf("%lld%lld",&n,&L);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=2;i<=31;i++)
		a[i]=min(a[i],2*a[i-1]);
	int i=1,now=0;
	while(i<=31){
		if((((L>>(i-1)))&1)==1)
			now+=a[i];
		else now=min(now,a[i]);
		i++;
	}
	printf("%lld\n",now);
	return 0;
}