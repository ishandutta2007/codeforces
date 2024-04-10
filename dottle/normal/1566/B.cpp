#include<bits/stdc++.h>
using namespace std;

int t;
string s;

int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>s;
		int ans=0;
		for(int i=0;i<s.size();i++)
			if(!i||s[i]!=s[i-1])
				ans+='1'-s[i];
			cout<<min(ans,2)<<endl;
	}
}