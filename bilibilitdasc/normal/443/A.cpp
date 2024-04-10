#include <iostream>
using namespace std;
bool ch[26];
int ans;
int main()
{
	string st;
	getline(cin,st);
	for(int i=0;i<st.size();i++)
	{
		char s=st[i];
		if(s<='z'&&s>='a')
		{
		ch[s-'a']=1;
		//cout<<s-'a'<<" ";
		} 
	}
	for(int i=0;i<26;i++)
	ans+=ch[i];
	cout<<ans;
	return 0;
}