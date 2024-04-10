#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        int q=0;
        for(int a=0; a<s.size(); a++) q+=s[a]-'0';
        if(q==0 or q==s.size()) cout<<s<<"\n";
        else
        {
            for(int a=0; a<s.size(); a++) cout<<"01";
            cout<<"\n";
        }
    }
}