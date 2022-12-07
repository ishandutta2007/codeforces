#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    char be='z';
    for(int a=0; a<s.size(); a++)
    {
        if(s[a]>be) printf("Ann\n");
        else printf("Mike\n");
        be=min(be, s[a]);
    }
}