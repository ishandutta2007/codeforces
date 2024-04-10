#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int l=0, r=s.size()-1;
    vector <int> an, anr;
    while(1)
    {
        while(l<s.size() and s[l]==')') l++;
        while(r and s[r]=='(') r--;
        if(l<r)
        {
            an.push_back(l+1);
            anr.push_back(r+1);
            l++, r--;
        }
        else break;
    }
    while(anr.size())
    {
        an.push_back(anr.back());
        anr.pop_back();
    }
    if(an.size())
    {
        cout<<"1\n"<<an.size()<<"\n";
        for(int a=0; a<an.size(); a++) cout<<an[a]<<" ";
    }
    else cout<<0;
}