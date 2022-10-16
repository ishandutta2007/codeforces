#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s,t,x[6]={"abca","acba","bacb","bcab","cabc","cbac"};
	cin>>n>>s>>t;
	if(n==1)
	{ 
		for(int i=0;i<6;i++){
			if(x[i].substr(0,2)!=s&&x[i].substr(0,2)!=t
			&&x[i].substr(1,2)!=s&&x[i].substr(1,2)!=t){
				cout<<"YES\n";
				cout<<x[i].substr(0,3);
				return 0;
			} 
		}
		cout<<"NO";
		return 0;
	} 
	for(int i=0;i<6;i++){
		if(x[i].substr(0,2)!=s&&x[i].substr(0,2)!=t&&x[i].substr(1,2)!=s
		&&x[i].substr(1,2)!=t&&x[i].substr(2,2)!=s&&x[i].substr(2,2)!=t){
			cout<<"YES\n";
			for(int j=0;j<n;j++)cout<<x[i].substr(0,3);
			return 0;
		} 
	}
	if(s[0]!=s[1]&&t[0]!=t[1]){
		for(int i=0;i<6;i++){
			if(x[i].substr(0,2)!=s&&x[i].substr(0,2)!=t
			&&x[i].substr(1,2)!=s&&x[i].substr(1,2)!=t){
				cout<<"YES\n";
				for(int j=0;j<n;j++)cout<<x[i][0];
				for(int j=0;j<n;j++)cout<<x[i][1];
				for(int j=0;j<n;j++)cout<<x[i][2];
				return 0;
			} 
		}
	}
	else
		cout<<"NO";
}