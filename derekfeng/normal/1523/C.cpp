#include<bits/stdc++.h>
using namespace std;
int t,n;
vector<int>ans;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		ans.clear(); 
		for(int i=0;i<n;i++){
			int x;cin>>x;
			if(x==1)ans.push_back(x);
			else{
				while(ans.back()!=x-1)ans.pop_back();
				ans.back()++; 
			}
			for(int i=0;i<ans.size()-1;i++)cout<<ans[i]<<".";
			cout<<ans.back()<<"\n";
		}
	}
}