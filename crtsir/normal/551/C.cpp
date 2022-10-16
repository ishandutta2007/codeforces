#include<bits/stdc++.h>
using namespace std;
long long l=0,r=100000000100000,n,m,a[100003];
bool check(long long x){
	if(x<=n)return 0;
	long long box=0,j=1;
	for(int i=0;i<m;i++)
	{
		for(;j<=n;j++)
			if(a[j]-box+j>=x-1)
				break;
		box=box+x-j-(a[j]-box+j==x-1);
		if(box>=a[n])break;
	}
	//if(x==3)cout<<a[n]<<' '<<box<<' '<<endl;
	return box>=a[n];
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],
		a[i]+=a[i-1];
	for(int i=n;i>0;i--)
		if(a[i]==a[i-1])
			n--;
		else
			break;
	while(l<r){
		//cout<<l<<' '<<r<<endl;
		long long mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	cout<<l;
}