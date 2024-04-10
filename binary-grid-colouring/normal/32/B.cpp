#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456];


int main()
{
	string s;
	cin>>s;
	int len =s.size();
	for(int i=0;i<len;)
	{
		if(s[i]=='.')
		{
			cout<<0;
		}
		if( s[i]=='-'&& s[i+1]=='.')
		{
			cout<<1;
			i++;;
		}
		 if(s[i]=='-'&&s[i+1]=='-')
		{
			cout<<2;
			i++;
		}
		i++;
	}
	return 0;
}