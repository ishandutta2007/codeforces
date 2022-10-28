#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	string l="abacaba";
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		string ans;
		int index=-1;
		for(int i=0; i<=s.size()-7; i++){
			
			string t;
			t=s;
			if(t[i]=='?'){
				t[i]='a';
			}
			else if(t[i]!='a'){
				continue;
			}
			
			if(t[i+1]=='?'){
				t[i+1]='b';
			}
			
			else if(t[i+1]!='b'){
				continue;
			}
			
			if(t[i+2]=='?'){
				t[i+2]='a';
			}
			else if(t[i+2]!='a'){
				continue;
			}
			
			if(t[i+3]=='?'){
				t[i+3]='c';
			}
			else if(t[i+3]!='c'){
				continue;
			}
			if(t[i+4]=='?'){
				t[i+4]='a';
			}
			else if(t[i+4]!='a'){
				continue;
			}
			if(t[i+5]=='?'){
				t[i+5]='b';
			}
			else if(t[i+5]!='b'){
				continue;
			}
			if(t[i+6]=='?'){
				t[i+6]='a';
			}
			else if(t[i+6]!='a'){
				continue;
			}
			
			for(int j=0; j<t.size(); j++){
				if(t[j]=='?'){
					t[j]='d';
				}
			}
			
			int cnt=0;
			for(int j=0; j<=s.size()-7; j++){
				if(l==t.substr(j, 7)){
				
					cnt++;
				}
			}
			
			if(cnt==1){
				ans=t;
				index=i;
			}
		}
		if(index==-1){
			cout<<"NO"<<endl;
			continue;
		}
		else{
			cout<<"YES"<<endl;
			cout<<ans<<endl;
		}
	}
	return 0;
}