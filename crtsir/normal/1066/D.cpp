#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[200003];
bool check(long long mid){
	long long cnt=0,tmp=m-1;
	for(int i=mid;i<n;i++)
	{
		if(cnt+a[i]>k)
			cnt=a[i],
			tmp--;
		else
			cnt+=a[i];
	}
	return tmp>=0;
}
int main(){
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	long long l=0,r=n;
	while(l!=r){
		long long mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<n-l;
}