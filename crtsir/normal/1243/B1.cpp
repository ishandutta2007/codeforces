#include<bits/stdc++.h>
using namespace std;
int TT,n; 
string s,t;
int main(){
	cin>>TT;
	while(TT--){
		cin>>n>>s>>t;
		vector<char>a,b;
		for(int i=0;i<s.size();i++)
			if(s[i]!=t[i]){
				a.push_back(s[i]);
				b.push_back(t[i]);
			}
		if(a.size()!=0&&a.size()!=2)
		{
			cout<<"No\n";
			continue;
		}
		if(a.size()==0){
			cout<<"Yes\n";
			continue;
		}
		if(a[0]==a[1]&&b[1]==b[0]){
			cout<<"Yes\n";
			continue;
		}
		cout<<"No\n";
	}
}