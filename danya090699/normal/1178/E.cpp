#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    string s, an;
    cin>>s;
    int n=s.size();
    for(int a=0; n-1-a>=a; a+=2)
    {
        int b=n-1-a;
        if(b-a>=3)
        {
            if(s[a]==s[b]) an.push_back(s[a]);
            else if(s[a+1]==s[b-1]) an.push_back(s[a+1]);
            else if(s[a]==s[b-1]) an.push_back(s[a]);
            else if(s[a+1]==s[b]) an.push_back(s[a+1]);
        }
        else
        {
            cout<<an<<s[a];
            while(an.size()) cout<<an.back(), an.pop_back();
            return 0;
        }
    }
    cout<<an;
    while(an.size()) cout<<an.back(), an.pop_back();
}