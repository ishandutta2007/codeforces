#include<bits/stdc++.h>
using namespace std;
int n,a[503],ans;
bool check(int x){
	if(x==0)return 1;
	for(int i=0;i<n;i++)
		if(a[i]%x>a[i]/x)
			return 0;
	return 1;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1;i<=sqrt(a[0]);i++){
		if(a[0]%i==0)
			if(check(i-1))ans=max(ans,i-1);
		if(check(i))ans=max(ans,i);
	}
	for(int i=1;i<=sqrt(a[0]);i++){
		int x=a[0]/i;
		if(a[0]%i==0)
			if(check(x-1))ans=max(ans,x-1);
		if(check(x))ans=max(ans,x);
	} 
	long long res=0;
	for(int i=0;i<n;i++)
		res+=((a[i]-1)/(ans+1)+1);
	cout<<res;
}