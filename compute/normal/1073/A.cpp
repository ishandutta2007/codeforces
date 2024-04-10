#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	string s;
	cin>>n;
	cin>>s;
	map<char,int> mp;
	int flag=1;
	for(int i=1;i<n;i++)
	{
		if(s[i]!=s[i-1])
		{
			flag=0;
			puts("YES");
			cout<<s[i-1]<<s[i]<<endl;
			break;
		}
	}
	if(flag) puts("NO");
	return 0;
}