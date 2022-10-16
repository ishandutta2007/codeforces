#include<bits/stdc++.h>
using namespace std;
long long n,k;
bool check1(long long x){
	long long times2=1,times=0;
	while(x<n)x=2*x+2,times2*=2,times+=times2;
	times=times*2+2;times2*=2;
	times=times-min(x-n+1,times2);
	return times>=k;
}
bool check2(long long x){
	k--;
	bool can=check1(x*2);
	k++;
	return can; 
}
int main(){
	cin>>n>>k;
	if(k==1){
		cout<<n;
		return 0;
	}
	long long l1=0,r1=1e18;
	while(l1!=r1){
		long long mid=(l1+r1)/2;
		if(mid%2)mid++;
		if(check1(mid))
			l1=mid;
		else
			r1=mid-2;
	}
	long long l2=1,r2=1e18-1;
	while(l2!=r2){ 
		long long mid=(l2+r2)/2;
		if(mid%2==0)mid++;
		if(check2(mid))
			l2=mid;
		else
			r2=mid-2;
	}
	cout<<max(l1,l2);
}