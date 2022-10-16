#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n<=30)
			cout<<"NO"<<endl;
		else
			if(n!=36&&n!=40&&n!=44)
				cout<<"YES"<<endl<<6<<' '<<14<<' '<<10<<' '<<n-30<<endl;
			else
				cout<<"YES\n"<<6<<' '<<10<<' '<<15<<' '<<n-31<<endl;
	}
}