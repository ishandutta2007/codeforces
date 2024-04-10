#include<bits/stdc++.h>
using namespace std;
int n,ans,num;
bool a[103];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++){
			int num=0;
			for(int k=0;k<n;k++)
				if(i<=k&&k<=j)
					num+=a[k]^1;
				else
					num+=a[k];
			ans=max(ans,num);
		}
	cout<<ans;
}