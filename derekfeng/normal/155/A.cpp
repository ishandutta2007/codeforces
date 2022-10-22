#include<bits/stdc++.h>
using namespace std;
int n,x,mx=-1,mn=1e9,ans;
int main(){
	cin>>n;
	while(n--){
		cin>>x;
		if(x>mx)mx=x,ans++;
		if(x<mn)mn=x,ans++;
	}
	cout<<ans-2;
}