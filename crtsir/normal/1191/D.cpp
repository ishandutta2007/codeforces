#include<bits/stdc++.h>
using namespace std;
long long n,a[100003],cntt,cnt,num;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	if(a[1]==0&&n-1){
		cout<<"cslnb";
		return 0;
	}
	for(int i=1;i<n;i++)if(a[i]==a[i-1])cntt++;
	for(int i=2;i<n;i++)if(a[i]==a[i-1]&&a[i-2]+1==a[i-1]){
		cout<<"cslnb";
		return 0;
	}
	if(cntt>=2){
		cout<<"cslnb";
		return 0;
	}
	for(int i=0;i<n;i++)
		if(a[i]>=num)
			cnt=cnt+a[i]-num,
			num++;
	if(cnt%2)cout<<"sjfnb";else cout<<"cslnb";
}//0 1 2 3---n-1