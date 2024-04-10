#include<bits/stdc++.h>
using namespace std;

int n,l,a,b,c;
int x;
int ans;

int main(){
	cin>>n>>l>>c;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		ans+=(a-x)/c;
		x=a+b;
	}
	ans+=(l-x)/c;
	cout<<ans;
	return 0; 
}