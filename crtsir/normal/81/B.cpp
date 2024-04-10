#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,ans="";
	getline(cin,s);
	if(s.size()<2)
	{
		cout<<s;
		return 0;
	}
	for(int i=0;i<s.size()-2;i++)
		if(isdigit(s[i]))
		{
			while(isdigit(s[i]))
				i++;
			while(s[i]==' ')
				i++;
			if(isdigit(s[i]))
				s=s.substr(0,i)+'Z'+s.substr(i,s.size()-i);
		}
	for(int i=0;i<s.size();i++)
		if(s[i]==' ')
		{
			s=s.substr(0,i)+s.substr(i+1,s.size()-i-1);
			i--;
		}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='.')
		{
			if(s[i-1]!=',')
				ans+=" ...";
			else
				ans+="...";
			i+=2;
			continue;
		}
		if(isdigit(s[i]))
			ans+=s[i];
		if(s[i]==',')
			ans+=", ";
		if(s[i]=='Z')
			ans+=" ";
	}
	if(ans[0]==' ')+2,
		ans=ans.substr(1,ans.size()-1);
	if(ans[ans.size()-1]==' ')
		ans=ans.substr(0,ans.size()-1);
	cout<<ans;
}