#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
	int ans=0;
	int n;
	cin>>n;
	string s="";
	char c;
	getchar();
	for(int i=1;i<=n;i++)
	{
		c=getchar();
		if (c!=' '){s=s+c; continue; }
		int tot=0;
		for(int i=0;i<s.length();i++)
			if ('A'<=s[i]&&s[i]<='Z')tot++;
		ans=max(ans,tot);
		s="";
	}
	int tot=0;
	for(int i=0;i<s.length();i++)
		if ('A'<=s[i]&&s[i]<='Z')tot++;
	ans=max(ans,tot);
	cout<<ans<<endl;
}