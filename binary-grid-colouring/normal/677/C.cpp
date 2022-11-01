#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[1010]={0};
LL mod=1e9+7;
string s;
LL ans;
int main()
{
	cin>>s;
	// 
	for(int i=0;i<=63;i++)
	{
		for(int j=0;j<=63;j++)
		{
			a[i&j]++;
		}
	}
	ans=1;
	
	for(int i=0;i<s.size();i++)
	{
		int p;
		if(s[i]>='0'&&s[i]<='9') p=s[i]-'0';
		if(s[i]>='A'&&s[i]<='Z') p=s[i]-'A'+10;
		if(s[i]>='a'&&s[i]<='z') p=s[i]-'a'+36;
		if(s[i]=='-') p=62;
		if(s[i]=='_') p=63;
		ans=ans*a[p];
		ans%=mod;
	}
	cout<<ans;
	return 0;
}