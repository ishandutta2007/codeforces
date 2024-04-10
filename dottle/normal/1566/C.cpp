#include<bits/stdc++.h>
using namespace std;

int T,n;
string s,t;

int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n>>s>>t;
		int ans=0;
		for(int i=0,pr=-1;i<s.size();i++){
			if(s[i]!=t[i])
				ans+=2,pr=-1;
			else {	
			if(s[i]=='0')
				if(pr==1)ans+=2,pr=-1;
				else ans++,pr=0;
			if(s[i]=='1')
				if(pr==0)ans++,pr=-1;
				else pr=1;
			}	
		}
		cout<<ans<<endl;
	}
}