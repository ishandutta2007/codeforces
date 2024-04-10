#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll f[123456][2];
string s[123456],t[123456];
int a[123456];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		t[i] = s[i];
		reverse(t[i].begin(),t[i].end());
	}
	for(int i=1;i<=n;i++)
	{
		f[i][0] = f[i][1] = (1LL<<60);
	}
	f[1][0] = 0;
	f[1][1] = a[1];
	for(int i=2;i<=n;i++)
	{
		if(s[i]>=s[i-1])
		{
			f[i][0] = min(f[i][0],f[i-1][0]);
		}
		if(s[i]>=t[i-1])
		{
			f[i][0] = min(f[i][0],f[i-1][1]);
		}
		if(t[i]>=s[i-1])
		{
			f[i][1] = min(f[i][1],f[i-1][0]+a[i]);
		}
		if(t[i]>=t[i-1])
		{
			f[i][1] = min(f[i][1],f[i-1][1]+a[i]);
		}
	}
	ll ans = min(f[n][1],f[n][0]);
	if(ans>=(1LL<<60))puts("-1");
	else cout<<ans<<endl;
	return 0;
}