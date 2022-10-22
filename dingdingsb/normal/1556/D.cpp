#include<bits/stdc++.h>
using namespace std;
enum{N=10010};
int n,k,a[N];
int main(){
	int x,_12,_13,_23;
	cin>>n>>k;
	cout<<"and 1 2"<<endl;
	cin>>_12;
	cout<<"or 1 2"<<endl;
	cin>>x;_12+=x;
	cout<<"and 1 3"<<endl;
	cin>>_13;
	cout<<"or 1 3"<<endl;
	cin>>x;_13+=x;
	cout<<"and 2 3"<<endl;
	cin>>_23;
	cout<<"or 2 3"<<endl;
	cin>>x;_23+=x;
	a[1]=(+_12+_13-_23)/2;
	a[2]=(+_12-_13+_23)/2;
	a[3]=(-_12+_13+_23)/2;
	for(int i=4;i<=n;i++){
		cout<<"and 1 "<<i<<endl;
		cin>>a[i];
		cout<<"or 1 "<<i<<endl;
		cin>>x;
		a[i]=a[i]+x-a[1];
	}
	sort(a+1,a+n+1);
	cout<<"finish "<<a[k]<<endl;
	return 0;
}