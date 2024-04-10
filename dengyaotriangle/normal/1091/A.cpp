#include<bits/stdc++.h>

using namespace std;

int main(){
	int y,b,r;
	cin>>y>>b>>r;
	int ans=0;
	for(int i=1;i<=200;i++){
		if(y>=i&&b>=(i+1)&&r>=(i+2)) ans=max(ans,3*i+3);
	} 
	cout<<ans;
	return 0;
}