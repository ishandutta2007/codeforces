#include<bits/stdc++.h>
using namespace std;
#define re register int
int n,kk,ans;
string a;
int main()
{
	cin>>n>>kk;
	cin>>a;
	for(re i=0;i<=25;i++)
	{
		re anss=0;
		char j='a'+i;
		for(re k=0;k<=a.length();k++)
		if(a[k]==j)
		{
			re js=0;
			while(a[k]==j&&js<kk){js++,k++;}k--;
			if(js>=kk) anss++;
		}
//		else cout<<a[k]<<" "<<j<<endl;
		ans=max(ans,anss);
	}
	cout<<ans;
	return 0;
}