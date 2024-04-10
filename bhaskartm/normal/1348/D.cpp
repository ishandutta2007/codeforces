#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int g=0; g<t; g++){
		long long int n;
		cin>>n;
	
		vector<long long int>v;
		v.push_back(1);
		long long int ans=0;
		for(int i=1; i<32; i++){
			if(pow(2, i)==n){
				ans=i;
				break;
			}
			if(pow(2, i)<n){
				ans=i;
				continue;
			}
			if(pow(2, i)>n){
				break;
			}
		}
		cout<<ans<<endl;
		n=n-1;
		
		while(ans!=0){
			
			long long int x=(v[v.size()-1])*2;
			if(x*ans<n){
				v.push_back(x);
				ans--;
				n=n-x;
				continue;
			}
			else{
				v.push_back(n/ans);
				
				n=n-(n/ans);
				ans--;
			}
			
		}
		
		for(int i=0; i<v.size()-1; i++){
			cout<<v[i+1]-v[i]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}