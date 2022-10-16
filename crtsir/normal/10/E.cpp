#include<bits/stdc++.h>
using namespace std;
long long n,a[403],ans=1e18;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1;i<n;i++)
		for(int j=i;j<n;j++){
			long long las=a[i-1]-1,cnt=-1,gt=a[j];
			for(int k=i;k<=j;k++){
				cnt-=las/a[k];
				gt+=(las/a[k])*a[k];
				las%=a[k]; 
			}
			long long tmp=gt;
			for(int k=0;k<n;k++)
				cnt+=tmp/a[k],
				tmp%=a[k];
			if(cnt>0)ans=min(ans,gt);
		}
	if(ans==1e18)
		cout<<-1;
	else
		cout<<ans;
}