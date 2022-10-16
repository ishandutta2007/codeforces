#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s,t;
		cin>>s>>t;
		swap(s,t);
		t+='?';
		int j,k=0,cnt=1;
		for(j=1;j<s.size();j++)cnt+=(s[j]!=s[j-1]);
		for(j=1;j<t.size();j++)cnt-=(t[j]!=t[j-1]);
		if(cnt){
		    cout<<"NO\n";
		    continue;
		}
		for(j=0;j<s.size();j++)
			if(s[j]==t[k])k++;
		if(k==t.size()-1)cout<<"YES\n";
		else cout<<"NO\n";
	}
}