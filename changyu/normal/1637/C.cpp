#include<bits/stdc++.h>
#define int long long
const int N=1e5+3;
int n,a[N],s,t;
signed main(){
	int T;scanf("%lld",&T);for(;T--;){
	scanf("%lld",&n);
	s=t=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
		if(i!=1&&i!=n)s+=a[i],t+=a[i]&1;
	}
	printf("%lld\n",s==n-2||n==3&&t?-1:(s+t)/2);
	}return 0;
}