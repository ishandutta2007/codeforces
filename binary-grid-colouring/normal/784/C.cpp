#include<bits/stdc++.h>
using namespace std;
int a[20];
int main()
{
	int n;
	int ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ans=max(ans,a[i]);
	}
	cout<<(ans^a[n-1])<<endl;
	return 0;
}