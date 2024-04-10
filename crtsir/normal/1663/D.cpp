#include<bits/stdc++.h>
using namespace std;
string s;
int x;
int main(){
	cin>>s;
	cin>>x;
	if(s=="ABC"&&x<2000){cout<<"YES";return 0;}
	if(s=="ARC"&&x<2800){cout<<"YES";return 0;}
	if(s=="AGC"&&x>=1200){cout<<"YES";return 0;}
	cout<<"NO";
}