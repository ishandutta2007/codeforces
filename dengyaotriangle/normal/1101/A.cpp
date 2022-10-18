#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long l,r,d;
		cin>>l>>r>>d;
		if(d<l) cout<<d;
		else{
			long long v=r/d;
			v++;
			cout<<v*d;
		}
		cout<<endl;
	}
	return 0;
}