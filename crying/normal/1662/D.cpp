#include<bits/stdc++.h>
using namespace std;
bool del(string &s){
	for(int i=1;i<s.size();i++)
		if(s[i]==s[i-1]){
			s=s.substr(0,i-1)+s.substr(i+1);
			return 1;
		}
	return 0;
}
string s,t,S,T;
int tt;
int main(){
    cin>>tt;
    while(tt--){
    	cin>>S>>T;s="";t="";
    	bool ok=1;
    	for(int i=0;i<S.size();i++)
    		if(S[i]!='B')
    			s+=S[i];
			else
				ok^=1;
    	for(int i=0;i<T.size();i++)
    		if(T[i]!='B')
    			t+=T[i];
			else
				ok^=1; 
		if(!ok){
			cout<<"NO\n";
			continue;
		}
		while(del(s));
		while(del(t));
		if(s==t)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}