#include<bits/stdc++.h>
using namespace std;
stack<int>s; 
int main(){
	int n;cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		while(s.size()){
			ans=max(ans,s.top()^a);
			if(a<=s.top())break;
			s.pop();
		}
		s.push(a);
	}
	cout<<ans;
	return 0;
}