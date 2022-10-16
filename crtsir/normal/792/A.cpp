#include<bits/stdc++.h>
using namespace std;
int n,a[200003];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)scanf("%d",a+i);
	sort(a,a+n);
	int minn=2000000007,cnt=0;
	for(int i=1;i<n;i++){
		if(a[i]-a[i-1]<minn){
			minn=a[i]-a[i-1];
			cnt=0;
		}
		if(a[i]-a[i-1]==minn)cnt++;
	}
	cout<<minn<<' '<<cnt;
}