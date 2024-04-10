#include<bits/stdc++.h>
using namespace std;
string s;
vector<pair<char,int>> v; 
int main()
{
	cin>>s;
	char cur=s[0];
	int cnt=1;
	for(int i=1;i<s.length();++i)
	{
		if(cur!=s[i])
		{
			v.push_back(make_pair(cur,cnt));
			cur=s[i];
			cnt=1;
		}
		else
			cnt++;
	}
	v.push_back(make_pair(cur,cnt));
	int n=v.size();
	if(n%2==1)
	{
		bool flag=1;
		for(int i=0;i<n/2;++i)
			if(v[i].first!=v[n-i-1].first||v[i].second+v[n-i-1].second<3)
				flag=0;
		if(v[n/2].second<2)
			flag=0;
		if(flag)
			printf("%d\n",v[n/2].second+1);
		else
			puts("0");

	}
	else
		puts("0");
}