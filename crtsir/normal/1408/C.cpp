#include<bits/stdc++.h>
using namespace std;
int T,n,a[100003],l;
bool check(long double x){
	long double ans=0,res=0;
	for(int i=1;i<=n+1;i++)
		if(a[i]>x){
			ans+=(x-a[i-1])*1.0/i;
			break;
		}
		else
			ans+=(a[i]-a[i-1])*1.0/i;
	for(int i=n;i>=0;i--)
		if(a[i]<x){
			res+=(a[i+1]-x)*1.0/(n+1-i);
			break;
		}
		else
			res+=(a[i+1]-a[i])*1.0/(n+1-i);
	return ans<res;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>l;
		for(int i=1;i<=n;i++)
			scanf("%d",a+i); 
		a[n+1]=l;
		long double L=0,R=l,mid,ans=0;
		while(fabs(L-R)>0.000000001){
			mid=(L+R)/2.0;
			if(check(mid))
				L=mid+0.000000001;
			else
				R=mid-0.000000001;
		}
//		cout<<L<<endl;
		for(int i=1;i<=n+1;i++)
			if(a[i]>L){
				ans+=(L-a[i-1])*1.0/i;
				break;
			}
			else
				ans+=(a[i]-a[i-1])*1.0/i;
		cout<<fixed<<setprecision(8)<<ans<<endl;
	}
}