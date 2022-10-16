#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin>>s>>s;s+='0';
	int cnt=s[0]-'0';
	for(int i=1;i<s.size();i++)
		if(s[i]=='0')
		{
			cout<<cnt;
			cnt=s[i]-'0';
		}else
			cnt+=(s[i]-'0');
}