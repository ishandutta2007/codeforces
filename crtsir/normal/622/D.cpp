#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n/2*2;i+=2)printf("%d ",i);
	for(int i=n/2*2+1;i<=n;i++)cout<<n<<' ';
	for(int i=n/2*2-1;i>=1;i-=2)printf("%d ",i);
	for(int i=2;i<=n-1;i+=2)printf("%d ",i);
	for(int i=(n+1)/2*2;i<=n;i++)cout<<i<<' ';
	for(int i=(n-1)/2*2;i>=2;i-=2)printf("%d ",i);
	for(int i=(n+1)/2*2;i<=n;i++)cout<<i<<' ';
	for(int i=n/2*2+1;i<=n;i++)cout<<n<<' ';
}