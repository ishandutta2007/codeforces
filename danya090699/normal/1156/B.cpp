#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin>>s;
    map <char, string> ma;
    for(int a=0; a<s.size(); a++) ma[s[a]].push_back(s[a]);
    if(ma.size()==2)
    {
        auto it=ma.begin();
        char sy=(*it).first;
        it++;
        char sy2=(*it).first;
        if(sy+1==sy2)
        {
            cout<<"No answer\n";
            return;
        }
    }
    if(ma.size()==3)
    {
        auto it=ma.begin();
        char sy=(*it).first;
        it++;
        char sy2=(*it).first;
        it++;
        char sy3=(*it).first;
        if(sy+1==sy2 and sy2+1==sy3)
        {
            cout<<"No answer\n";
            return;
        }
        if(sy+1==sy2)
        {
            cout<<ma[sy]<<ma[sy3]<<ma[sy2]<<"\n";
            return;
        }
    }
    int a=0;
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        if(a&1) cout<<(*it).second;
        a++;
    }
    a=0;
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        if((a&1)==0) cout<<(*it).second;
        a++;
    }
    cout<<"\n";
}
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        solve();
    }
}