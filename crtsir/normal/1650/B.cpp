#include<bits/stdc++.h>
using namespace std;
int l,r,a;
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>l>>r>>a;
		if(l/a!=(r+1)/a)
			r=1ll*a*((r+1)/a)-1;
		cout<<r/a+r%a<<endl;
	}
}