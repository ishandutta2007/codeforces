#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const int o=110;
int T,n,a[o],b[o],ans;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans+min(b[0],1)),ans=0){
		for(int i=0;i<101;++i) b[i]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),++b[abs(a[i])];
		for(int i=1;i<101;++i) ans+=min(b[i],2);
	}
	return 0;
}