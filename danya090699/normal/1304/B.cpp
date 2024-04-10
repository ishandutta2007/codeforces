#include <bits/stdc++.h>
using namespace std;
bool ok(string s)
{
    for(int a=0; a<s.size(); a++)
    {
        if(s[a]!=s[s.size()-1-a]) return false;
    }
    return true;
}
main()
{
	//freopen("input.txt", "r", stdin);
	int n, m;
	cin>>n>>m;
    bool us[n];
    string s[n], an, r;
    for(int a=0; a<n; a++)
    {
        cin>>s[a];
        us[a]=0;
    }
    for(int a=0; a<n; a++)
    {
        for(int b=a+1; b<n; b++)
        {
            if(!us[b] and ok(s[a]+s[b]))
            {
                us[a]=1, us[b]=1;
                an+=s[a], r=s[b]+r;
            }
        }
    }
    for(int a=0; a<n; a++)
    {
        if(!us[a] and ok(s[a]))
        {
            an+=s[a];
            break;
        }
    }
    an+=r;
    cout<<an.size()<<"\n"<<an;
}