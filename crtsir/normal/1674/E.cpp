#include<bits/stdc++.h>
using namespace std;
int n,a[200003],T;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int ret=19260817;
	for(int i=1;i<n;i++){
		int x=a[i],y=a[i-1];
		ret=min(ret,max(max((x+1)/2,(y+1)/2),(x+y+2)/3));
	}
	for(int i=1;i<n-1;i++)
		ret=min(ret,min(a[i-1],a[i+1])+(abs(a[i-1]-a[i+1])+1)/2);
	sort(a,a+n);
	ret=min(ret,(a[0]+1)/2+(a[1]+1)/2);
	cout<<ret;
}