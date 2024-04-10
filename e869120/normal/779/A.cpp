#include<bits/stdc++.h>
using namespace std;
int a[6],b[6],n,c,d,sum;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){cin>>c;a[c]++;}
	for(int i=0;i<n;i++){cin>>d;b[d]++;}
	for(int i=1;i<=5;i++){
		if((a[i]+b[i])%2==1){cout<<"-1"<<endl;return 0;}
		if(a[i]<b[i])swap(a[i],b[i]);
		sum+=a[i]-(a[i]+b[i])/2;
	}
	cout<<sum/2<<endl;
	return 0;
}