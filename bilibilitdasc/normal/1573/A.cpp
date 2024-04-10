#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T; cin >> T;
	while(T --)
	{
		int n, ans=0; string s;
		cin >> n; cin >> s;
		for(int i=0;i<n;i++)
		{
			if(s[i] - 48 && i != n-1) ++ans;
			ans += s[i] - '0';
		}
		cout << ans << endl;
	}
	return 0;
}