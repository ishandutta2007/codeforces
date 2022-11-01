#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	string s;
	cin>>s;
	int cnt = 0,ans = 0;
	int len = s.length();
	for(int i=0;i<len;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			cnt = 0;
			while(s[i+cnt] == s[j+cnt])cnt++;
			ans = max(ans,cnt);
		}
	}
	cout<<ans<<endl;
	return 0;
}