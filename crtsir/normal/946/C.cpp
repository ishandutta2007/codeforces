#include<bits/stdc++.h>
using namespace std;
string ap="abcdefghijklmnopqrstuvwxyz";
vector<int>v;
int main(){
	string s,x;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]-'a'<=v.size()&&v.size()<26)
			v.push_back(i);
	if(v.size()<26)
	{
		cout<<-1;
		return 0;
	}
	for(int i=0;i<v.size();i++)
		s[v[i]]=char('a'+i);
	cout<<s;
}