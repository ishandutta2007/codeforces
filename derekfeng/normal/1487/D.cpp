#include<bits/stdc++.h>
using namespace std;
int T;
vector<int>ans;
int main(){
	for(int i=3;i*i<=2e9+1;i+=2)ans.push_back((i*i-1)/2);
//	for(int i=0;i<100;i++)cout<<ans[i]<<"\n";
	cin>>T;
	while(T--){
		int x;cin>>x;x--;
		cout<<upper_bound(ans.begin(),ans.end(),x)-ans.begin()<<"\n";
	}
}