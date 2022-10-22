#include<bits/stdc++.h>
using namespace std;
string s,T,ans;
int n,K;
string go(string s){
	string ret=s;
	while(ret.size()<K)ret+=s;
	return ret;
}
int main(){
	cin>>n>>K>>s;
	ans=go(s);
	for(int i=1;i<n;i++){
		string ret=s.substr(0,i);
		if(go(ret)<ans)ans=go(ret);
	}
	cout<<ans.substr(0,K)<<"\n";
}