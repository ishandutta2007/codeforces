#include<bits/stdc++.h>
using namespace std;
int n,a[103];
int Maximum,Minimum=114,p1,p2,ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(Maximum<a[i])Maximum=a[i],p1=i;
	}
	while(p1)ans++,swap(a[p1-1],a[p1]),p1--;
	for(int i=n-1;~i;i--)
		if(Minimum>a[i])Minimum=a[i],p2=i;
	ans+=n-1-p2;
	cout<<ans;
}