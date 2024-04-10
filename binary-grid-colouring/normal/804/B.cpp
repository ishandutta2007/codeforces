#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
int main()
{
	string s;
	cin>>s;
	reverse(s.begin(),s.end());
	ll ans =0;
	int b=0;
	for(int i=0;i<s.length();i++)
	{
		if (s[i] == 'b')
		{
      		b++;
    	} 
    	else
    	{
      		ans = (ans + b) % mod;
      		b = b * 2 % mod;
    	}
	}
	cout<<ans<<endl;
	return 0;
}