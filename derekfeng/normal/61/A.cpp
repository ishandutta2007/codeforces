#include<bits/stdc++.h>
using namespace std;
string s,t;
int main(){
	cin>>s>>t;
	for(int i=0;i<s.size();i++)cout<<((s[i]-'0')^(t[i]-'0'));
}