#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int ans=0;
	cin>>s;
	for(int i=1;i<s.size();i++)
	{
		vector<string>ss;
		for(int j=0;j<s.size()-i+1;j++)
			ss.push_back(s.substr(j,i));
		for(int j=0;j<ss.size()-1;j++)
			for(int k=j+1;k<ss.size();k++)
				if(ss[j]==ss[k])
					ans=i;
	}
	cout<<ans;
}