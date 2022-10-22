#include<bits/stdc++.h>
using namespace std;
string s,t;
int main(){
	cin>>s>>t;
	reverse(s.begin(),s.end());
	puts(s==t?"YES":"NO");
}