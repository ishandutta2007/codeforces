#include <bits/stdc++.h>
using namespace std;
#define int long long int

main() {
	while(1){
		string s;
		cin>>s;
		if(s=="end"){
			break;
		}
		int x=1;
		char c;
		while(x<=1000000000){
			cout<<"?"<<" "<<x<<" "<<2*x<<endl;
			cin>>c;
			if(c=='x'){
				break;
			}
			x=2*x;
		}
		if(x==1){
			cout<<"?"<<" "<<2<<" "<<1<<endl;
			cin>>c;
			if(c=='y'){
				cout<<"!"<<" "<<2<<endl;
				continue;
			}
			else{
				cout<<"!"<<" "<<1<<endl;
				continue;
			}
		}
		int val=x;
		int lo=x+1;
		int hi=2*x;
		int ans=-1;
		while(lo<=hi){
			int mid=(lo+hi)/2;
			cout<<"?"<<" "<<val<<" "<<mid<<endl;
			cin>>c;
			if(c=='y'){
				lo=mid+1;
			}
			else{
				ans=mid;
				hi=mid-1;
			}
		}
		cout<<"!"<<" "<<ans<<endl;
	}
	return 0;
}