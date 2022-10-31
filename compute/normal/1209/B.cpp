#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
int main()
{
	int n;
	string s;
	cin>>n>>s;
	for(int i=0;i<n;i++) cin>>a[i]>>b[i];
	int ans=0;
	for(int i=0;i<n;i++) ans+=(s[i]=='1');
	for(int i=1;i<=10000;i++)
	{
		int cur=0;
		for(int j=0;j<n;j++)
		{
			if(i>=b[j]&&(i-b[j])%a[j]==0)
			{
				if(s[j]=='0') s[j]='1';
				else s[j]='0';
			}
			cur+=(s[j]=='1');
		}
		ans=max(ans,cur);
		
	}
	cout<<ans<<endl;
}