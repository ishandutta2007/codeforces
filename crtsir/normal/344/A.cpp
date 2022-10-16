#include<bits/stdc++.h>
using namespace std;
int n,a[100003],ans=1;
int main(){cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
		ans+=bool(a[i]!=a[i-1]);
	cout<<ans;
}