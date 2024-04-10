#include<bits/stdc++.h>
using namespace std;
bool ism(char c)
{
	if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='Y')
		return true;
	else
		return false;
}
int main()
{
	string s;
	cin>>s;
	s=s+'A';
	int last=-1,ans=-1;
	for(int i=0;i<s.size();i++)
		if(ism(s[i]))
			ans=max(ans,i-last),
			last=i;
	cout<<ans;
}