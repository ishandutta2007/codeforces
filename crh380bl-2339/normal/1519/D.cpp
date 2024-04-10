#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[5005],b[5005];
int main(){
	int n,i,j,k;
	ll s=0,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(i=1;i<=n;++i)scanf("%lld",&b[i]);
	for(i=1;i<=n;++i){
		s=0;
		for(j=0;i>=j+1&&i+j<=n;++j){
			s=s+(a[i-j]-a[i+j])*(b[i+j]-b[i-j]);
			if(s>ans)ans=s;
		}
	}
	for(i=1;i<n;++i){
		s=0;
		for(j=0;i>=j+1&&i+j<n;++j){
			s=s+(a[i-j]-a[i+1+j])*(b[i+1+j]-b[i-j]);
			if(s>ans)ans=s;
		}
	}
	for(i=1;i<=n;++i)ans=ans+a[i]*b[i];
	printf("%lld\n",ans);
	return 0;
}