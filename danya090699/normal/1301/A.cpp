#include <bits/stdc++.h>
using namespace std;
main()
{
	//freopen("input.txt", "r", stdin);
	int t;
	cin>>t;
	while(t)
    {
        t--;
        string s[3];
        cin>>s[0]>>s[1]>>s[2];
        int ok=1;
        for(int a=0; a<s[0].size(); a++)
        {
            if(s[2][a]!=s[0][a] and s[2][a]!=s[1][a]) ok=0;
        }
        cout<<(ok ? "YES\n" : "NO\n");
    }
}