#include<bits/stdc++.h>
#define int long long
const int N=1e5+3,INF=1e18;
int n,a[N],b[N],mn;
signed main(){
	int T=1;for(;T--;){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	mn=INF;
	for(int i=1;i<=n;i++){
		int s=0;
		std::fill(b+1,b+1+n,0);
		for(int j=i-1;j>=1;j--){
			int tmp=b[j+1]/a[j]+1;
			s+=tmp,b[j]=a[j]*tmp;
		}
		for(int j=i+1;j<=n;j++){
			int tmp=b[j-1]/a[j]+1;
			s+=tmp,b[j]=a[j]*tmp;
		}
		mn=std::min(mn,s);
	}
	printf("%lld\n",mn);
	}return 0;
}