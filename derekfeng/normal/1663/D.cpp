#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;int x;cin>>s>>x;
	if(s[1]=='B'||s[1]=='b')puts(x<2000?"YES":"NO");
	else if(s[1]=='R'||s[1]=='r')puts(x<2800?"YES":"NO");
	else puts(x>=1200?"YES":"NO");
}