#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    string s, t;
    cin>>n>>s>>t;
    vector <int> ab, ba;
    for(int a=0; a<n; a++)
    {
        if(s[a]=='a' and t[a]=='b') ab.push_back(a+1);
        if(s[a]=='b' and t[a]=='a') ba.push_back(a+1);
    }
    vector <pair <int, int> > an;
    while(ab.size()>1)
    {
        an.push_back({ab.back(), -1});
        ab.pop_back();
        an.back().second=ab.back();
        ab.pop_back();
    }
    while(ba.size()>1)
    {
        an.push_back({ba.back(), -1});
        ba.pop_back();
        an.back().second=ba.back();
        ba.pop_back();
    }
    if(ba.size()+ab.size()==1) cout<<-1;
    else
    {
        if(ab.size())
        {
            an.push_back({ab[0], ab[0]});
            an.push_back({ab[0], ba[0]});
        }
        cout<<an.size()<<"\n";
        for(int a=0; a<an.size(); a++) printf("%d %d\n", an[a].first, an[a].second);
    }
}