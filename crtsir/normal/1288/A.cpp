#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		int x=0;
		bool can=0;
		for(x;x<=n&&x-(d+x)/(x+1)<=100000;x++)
			if(x+(d+x)/(x+1)<=n)
				can=1;
		if(can)cout<<"YES\n";else cout<<"NO\n";
	}
}