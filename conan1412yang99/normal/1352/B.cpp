#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n , k;
		cin>>n>>k;
		if(n < k) cout<<"NO"<<endl;
		else if(k == 1) cout<<"YES"<<endl<<n<<endl;
		else{
			if(n - ((k - 1) * 2) > 0 && (n - (k + 1) * 2) % 2 == 0){
				cout<<"YES"<<endl;
				for(int i = 0 ; i < k - 1 ; i++) cout<<2<<" ";
				cout<<(n - (k - 1) * 2)<<endl;
			}
			else if(n - k - 1 > 0 && (n - k - 1) % 2 != 0){
				cout<<"YES"<<endl;
				for(int i = 0 ; i < k - 1 ; i++) cout<<1<<" ";
				cout<<(n - k + 1)<<endl;
			}
			else if(n == k){
				cout<<"YES"<<endl;
				for(int i = 0 ; i < n ; i++) cout<<1<<" ";
				cout<<endl;
			}
			else cout<<"NO"<<endl;
		}
	}
}