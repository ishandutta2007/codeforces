#include<bits/stdc++.h>
using namespace std;
int n,a[1003];
pair<long long,int>ret;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		int maxm=a[i];long long cnt=0;
		for(int j=i-1;j>=0;j--)
			cnt+=min(a[j],maxm),
			maxm=min(a[j],maxm);
		maxm=a[i];
		for(int j=i;j<n;j++)
			cnt+=min(a[j],maxm),
			maxm=min(a[j],maxm);
		ret=max(ret,make_pair(cnt,i));
	}
	for(int i=ret.second-1;i>=0;i--)
		a[i]=min(a[i],a[i+1]);
	for(int i=ret.second+1;i<n;i++)
		a[i]=min(a[i],a[i-1]);
	for(int i=0;i<n;i++)cout<<a[i]<<' ';
}