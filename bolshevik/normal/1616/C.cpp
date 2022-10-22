#include<cstdio>
#include<iostream>
using namespace std;
const int o=80;
int T,n,a[o],ans;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans)){
		scanf("%d",&n);ans=n;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		if(n==1){ans=0;continue;}
		for(int i=1;i<n;++i) for(int j=n,res;j>i;--j){
			res=n;
			for(int k=1;k<=n;++k) res-=((a[k]-a[i])*(j-i)==(a[j]-a[i])*(k-i));
			ans=min(ans,res);
		}
	}
	return 0;
}