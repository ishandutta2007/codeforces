#include<bits/stdc++.h>
using namespace std;
long long cnt1,cnt2,n,a[103],cnt3=1;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){cnt1+=a[i],cnt2+=a[i];cnt3++;if(a[i]*2>a[0])cnt1-=a[i],cnt3--;}
	if((cnt1+a[0])*2<=cnt2){
		cout<<0;
		return 0;
	}
	cout<<cnt3<<endl<<"1 ";
	for(int i=1;i<n;i++)if(a[i]*2<=a[0])cout<<i+1<<' ';
}