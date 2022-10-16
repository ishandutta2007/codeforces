#include<bits/stdc++.h>
using namespace std;
int a[100003],n,m,k,la;
int main(){
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		int b;
		cin>>b;
		if(i)a[i-1]=b-la-1;
		la=b;
	}
	sort(a,a+n-1);
	long long ans=0;
	for(int i=0;i<n-k;i++)ans+=a[i];
	cout<<ans+n;
}