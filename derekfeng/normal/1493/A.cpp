#include<bits/stdc++.h>
using namespace std;
int T,n,K;
vector<int>ans;
int main(){
	cin>>T;
	while(T--){
		ans.clear();
		cin>>n>>K;
		for(int i=K+1;i<=n;i++)ans.push_back(i);
		for(int i=K-1;i>(K-1)/2;i--)ans.push_back(i);
		cout<<ans.size()<<"\n";
		for(auto x:ans)cout<<x<<" ";puts("");
	}
}