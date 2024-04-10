#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[5]={100,20,10,5,1},ans=0;
	cin>>n;
	for(int i=0;i<5;i++)
		while(a[i]<=n)
			n-=a[i],
			ans++;
	cout<<ans;
}