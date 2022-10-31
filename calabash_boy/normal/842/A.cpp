#include<bits/stdc++.h>
using namespace std;
int main(){
	long long l,r,x,y,k;
	cin>>l>>r>>x>>y>>k;
	for (int i=x;i<=y;i++){
		long long tt = k*i;
		if (tt>=l&&tt<=r){
			cout<<"YES"<<endl;
			return 0;
			
		}
	}
	cout<<"NO"<<endl;
	return 0;
}