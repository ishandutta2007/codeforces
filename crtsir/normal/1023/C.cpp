#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	int x,y;
	cin>>s>>x>>s;
	y=(s.size()-x)/2;
	x=y;
	for(int i=0;i<s.size();i++)
		if(s[i]=='(')
			if(x)
				x--;
			else
				cout<<s[i];
		else
			if(y)
				y--;
			else
				cout<<s[i];
}