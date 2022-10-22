#include<bits/stdc++.h>
typedef long long ll;
const int N=1e5+3,D=323,S=3.7e7;
int n,m,a[N],c[S],ans;
signed main(){
	int T;T=1;for(;T--;){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),m=std::max(m,a[i]);
	ans=std::min(n,2);
	for(int d=0;d<D;d++){
		for(int i=1;i<=n;i++)++c[a[i]+i*d];
		for(int i=1;i<=n;i++)ans=std::max(ans,c[a[i]+i*d]),c[a[i]+i*d]=0;
	}
	for(int d=1;d<D;d++){
		for(int i=1;i<=n;i++)++c[i*d-a[i]+m];
		for(int i=1;i<=n;i++)ans=std::max(ans,c[i*d-a[i]+m]),c[i*d-a[i]+m]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=std::max(1,i-D);j<i;j++)if((a[i]-a[j])%(i-j)==0)++c[(a[i]-a[j])/(i-j)+m];
		for(int j=std::max(1,i-D);j<i;j++)if((a[i]-a[j])%(i-j)==0)ans=std::max(ans,c[(a[i]-a[j])/(i-j)+m]+1),c[(a[i]-a[j])/(i-j)+m]=0;
	}
	printf("%d\n",n-ans);
	}return 0;
}