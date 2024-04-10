#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
string s;
int main()
{
	int n;
	
	cin>>n;
	cin>>s;
	mp[s]=1;
	cout<<"OK"<<endl;
	for(int i=1;i<n;i++)
	{
		cin>>s;
		mp[s]++;
		if(mp[s]==1)cout<<"OK"<<endl;
		else cout<<s<<mp[s]-1<<endl;
	}
	return 0;
 }