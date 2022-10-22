#include<iostream>
using namespace std;
main(){int t;cin>>t;while(t--){string s;cin>>s;cout<<s.substr(0,2);for(int i=3;i<=s.size();i=i+2)cout<<s[i];puts("");}}