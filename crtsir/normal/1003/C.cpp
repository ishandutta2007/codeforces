#include<bits/stdc++.h>
using namespace std;
int n,a,k;
double sum[5003];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		sum[i]=sum[i-1]+a;
	}
	double ans=0;
	for(int i=k;i<=n;i++)
		for(int j=0;j+i<=n;j++)
			ans=max(ans,(sum[i+j]-sum[i-k])/(j+k));
	cout<<fixed<<setprecision(9)<<ans<<endl;
}