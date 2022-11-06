#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define ll long long
using namespace std;
int st[100002];
int main(){
	int T,i,j,n,m;
	ll k,k1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%lld",&n,&k);
		k1=--k;m=0;
		for(i=1;i<=n-1;++i)k1>>=1LL;
		if(k1){
			puts("-1");
			continue;
		}
		for(i=1;i<n;++i){
			if(n-i-1>=60||k<(1LL<<(ll)n-i-1))st[++m]=i;
			else k-=(1LL<<(ll)n-i-1);
		}
		st[++m]=n;
		for(i=1;i<=m;++i){
			for(j=st[i];j>st[i-1];--j)printf("%d ",j);
		}
		puts("");
	}
	return 0;
}